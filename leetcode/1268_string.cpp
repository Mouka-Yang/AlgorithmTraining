#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <algorithm>
#include <string>
#include <vector>
using namespace testing;

class Solution {
public:
    using ResultType = std::vector<std::vector<std::string>>;
    using InputType = std::vector<std::string>;

    ResultType suggestedProducts(InputType& products, std::string searchWord)
    {
        std::sort(products.begin(), products.end());

        std::string_view key{searchWord.c_str(), searchWord.size()};

        ResultType res(key.size());

        for (auto i{1U}; i <= key.size(); ++i) {
            auto subKey{key.substr(0, i)};
            auto count{0U};

            for (const auto& product : products) {
                if (product.find(subKey) != std::string::npos) {
                    res[i - 1].push_back(product);
                    ++count;
                }

                if (count == 3) {
                    break;
                }
            }
        }

        return res;
    }
};
