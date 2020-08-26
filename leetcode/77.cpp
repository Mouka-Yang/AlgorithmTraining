#include "header.h"
class Solution {
public:
    using Result_T  = std::vector<std::vector<int>>;
    using Partial_T = std::vector<int>;

    std::vector<std::vector<int>> combine(int n, int k)
    {
        std::vector<char> used(n);
        std::fill(used.begin(), used.end(), false);
        backtrace(used, k, 0);
        return results;
    }

    void backtrace(std::vector<char>& used, int level, int start)
    {
        if (level == 0) {
            results.push_back(partial);
        }
        else {
            auto len = used.size();
            for (int i = start + 1; i <= len; i++) {
                if (!used[i - 1]) {
                    partial.push_back(i);
                    used[i - 1] = true;
                    backtrace(used, level - 1, i);
                    used[i - 1] = false;
                    partial.pop_back();
                }
            }
        }
    }

private:
    Partial_T partial{};
    Result_T  results{};
};

int main()
{
    Solution().combine(4, 3);
}