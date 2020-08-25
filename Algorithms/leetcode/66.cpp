#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits)
    {
        auto res = digits;
        int c = 1;
        for (auto digit = res.rbegin(); digit != res.rend(); digit++) {
            int temp = c;
            c = (*digit + temp) / 10;
            *digit = (*digit + temp) % 10;
        }

        if (c == 1) {
            res.emplace(res.begin(), 1);
        }

        return res;
    }
};