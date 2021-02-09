#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "header.h"
using namespace testing;
constexpr const int INVALID_BRAND_ID = 201;

using ProductList = std::vector<int>;

class VendingMachineSystem {
public:
    VendingMachineSystem(int trayNum, int trayCapacity) : trayNum_(trayNum), trayCapacity_(trayCapacity) {}

    bool AddProduct(int brandId, const ProductList& productIdList)
    {
        if (productIdList.size() > trayCapacity_) {
            return false;
        }

        if (trayMap_.count(brandId) == 0) {
            return addProductToEmptyTray(brandId, productIdList);
        }

        return addProductToExistedTray(brandId, productIdList);
    }

    ProductList BuyProduct(int brandId, int num)
    {
        if (trayMap_.count(brandId) == 0) {
            return {};
        }

        auto& targetTray = trayMap_[brandId];
        if (targetTray.size() < num) {
            return {};
        }

        ProductList result(targetTray.begin(), targetTray.begin() + num);

        targetTray.erase(targetTray.begin(), targetTray.begin() + num);
        if (targetTray.empty()) {
            trayMap_.erase(brandId);
        }

        return result;
    }

    ProductList QueryProduct()
    {
        ProductList resultProducts{};

        for (const auto& [brandId, productList] : trayMap_) {
            resultProducts.push_back(productList.front());
        }

        return resultProducts;
    }

private:
    bool addProductToExistedTray(int brandId, const ProductList& productIdList)
    {
        auto& targetTray = trayMap_[brandId];
        if (trayCapacity_ - targetTray.size() < productIdList.size()) {
            return false;
        }

        targetTray.insert(targetTray.end(), productIdList.begin(), productIdList.end());
    }

    bool addProductToEmptyTray(int brandId, const ProductList& productIdList)
    {
        if (trayMap_.size() == trayNum_) {
            return false;
        }

        trayMap_[brandId].insert(trayMap_[brandId].end(), productIdList.begin(), productIdList.end());
    }

    int trayNum_;
    int trayCapacity_;
    std::map<int, ProductList> trayMap_{};
};

TEST(AA, A)
{
    VendingMachineSystem s(2, 5);
    s.AddProduct(3, {3, 5, 4, 6, 2});
    s.BuyProduct(3, 3);
    s.QueryProduct();
}

TEST(BB, B)
{
    VendingMachineSystem s(2, 5);
    EXPECT_FALSE(s.AddProduct(3, {3, 5, 4, 6, 2, 1}));
    EXPECT_TRUE(s.AddProduct(3, {3, 5, 4, 6, 2}));
    EXPECT_TRUE(s.AddProduct(1, {9}));
    EXPECT_FALSE(s.AddProduct(2, {7}));

    EXPECT_EQ(s.BuyProduct(3, 3), ProductList({3, 5, 4}));
    EXPECT_TRUE(s.BuyProduct(9, 3).empty());
    EXPECT_TRUE(s.BuyProduct(3, 3).empty());

    EXPECT_EQ(s.QueryProduct(), ProductList({9, 6}));

    EXPECT_FALSE(s.AddProduct(3, {10, 20, 13, 14}));
    EXPECT_TRUE(s.AddProduct(3, {10, 20, 13}));

    EXPECT_EQ(s.BuyProduct(3, 5), ProductList({6, 2, 10, 20, 13}));

    EXPECT_TRUE(s.AddProduct(9, {5, 4}));
}
