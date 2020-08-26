#include "gtest/gtest.h"
#include "header.h"

class Solution {
public:
    int numTrees(int n)
    {
        res_.resize(n + 1, 0);
        res_[1] = 1;
        res_[0] = 1;
        if (n < 2) {
            return res_[n];
        }

        for (auto i = 2; i <= n; i++) {
            res_[i] = getPartialTreesNum(i);
        }
        return res_[n];
    }
    int getPartialTreesNum(int n)
    {
        auto partial = 0;
        for (auto i = 0; i < n; i++) {
            partial += res_[i] * res_[n - 1 - i];
        }
        return partial;
    }

private:
    std::vector<int> res_{};
};
