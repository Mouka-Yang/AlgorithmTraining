#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "header.h"
using namespace testing;
constexpr const int INVALID_BRAND_ID = 201;

using ProductList = std::vector<int>;

class Tray {
public:
    Tray(int capacity) : capacity_(capacity) {}

    int GetCapacity() const
    {
        return capacity_;
    }

    int GetBrandId() const
    {
        return brandId_;
    }

    void SetBrandId(int brandId)
    {
        brandId_ = brandId;
    }

    bool IsEmpty() const
    {
        return products_.empty();
    }

    int GetRemainSpace() const
    {
        return capacity_ - products_.size();
    }

    int GetProductNum() const
    {
        return products_.size();
    }

    void AddProduct(const ProductList& newProducts)
    {
        products_.insert(products_.end(), newProducts.begin(), newProducts.end());
    }

    const ProductList& GetProduct() const
    {
        return products_;
    }

    ProductList RemoveProduct(int num)
    {
        ProductList removedProduct{products_.begin(), products_.begin() + num};
        products_.erase(products_.begin(), products_.begin() + num);

        return removedProduct;
    }

private:
    int capacity_;
    int brandId_{INVALID_BRAND_ID};
    ProductList products_{};
};

class VendingMachineSystem {
public:
    VendingMachineSystem(int trayNum, int trayCapacity) : traySet_(trayNum, Tray(trayCapacity)) {}

    bool AddProduct(int brandId, const ProductList& productIdList)
    {
        if (brandIdSet_.count(brandId) != 0) {
            return addProductToExistedTray(brandId, productIdList);
        }

        return addProductToEmptyTray(brandId, productIdList);
    }

    ProductList BuyProduct(int brandId, int num)
    {
        if (brandIdSet_.count(brandId) == 0) {
            return {};
        }

        auto& targetTray = traySet_[findTrayByBrandId(brandId)];
        auto productNum = targetTray.GetProductNum();
        if (productNum < num) {
            return {};
        }

        auto removedProducts = targetTray.RemoveProduct(num);
        if (targetTray.IsEmpty()) {
            brandIdSet_.erase(brandId);
            targetTray.SetBrandId(INVALID_BRAND_ID);
        }

        return removedProducts;
    }

    ProductList QueryProduct()
    {
        if (brandIdSet_.empty()) {
            return {};
        }

        std::sort(traySet_.begin(), traySet_.end(), [](const auto& lhs, const auto& rhs) {
            return lhs.GetBrandId() < rhs.GetBrandId();
        });

        ProductList queryResults{};
        for (const auto& tray : traySet_) {
            if (tray.GetBrandId() != INVALID_BRAND_ID) {
                queryResults.push_back(tray.GetProduct()[0]);
            }
        }

        return queryResults;
    }

private:
    bool addProductToExistedTray(int brandId, const ProductList& productIdList)
    {
        auto& targetTray = traySet_[findTrayByBrandId(brandId)];
        auto remainSpace = targetTray.GetRemainSpace();

        if (remainSpace < productIdList.size()) {
            return false;
        }

        targetTray.AddProduct(productIdList);
        return true;
    }

    bool addProductToEmptyTray(int brandId, const ProductList& productIdList)
    {
        auto emptyTrayId = findEmptyTray();
        if (emptyTrayId == -1 || traySet_[emptyTrayId].GetCapacity() < productIdList.size()) {
            return false;
        }

        traySet_[emptyTrayId].AddProduct(productIdList);
        traySet_[emptyTrayId].SetBrandId(brandId);

        brandIdSet_.insert(brandId);

        return true;
    }

    int findTrayByBrandId(int brandId) const
    {
        auto traySize{traySet_.size()};

        for (auto i{0U}; i < traySize; ++i) {
            if (traySet_[i].GetBrandId() == brandId) {
                return i;
            }
        }

        return -1;
    }

    int findEmptyTray() const
    {
        auto traySize{traySet_.size()};

        for (auto i{0U}; i < traySize; ++i) {
            if (traySet_[i].IsEmpty()) {
                return i;
            }
        }

        return -1;
    }

    std::vector<Tray> traySet_;
    std::unordered_set<int> brandIdSet_{};
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
