#include "header.h"
std::pair<int, bool> initializeState(int num)
{
    return std::make_pair(num, false);
}
class Solution {
public:
    using Result_T  = std::vector<std::vector<int>>;
    using Partial_T = std::vector<int>;

    std::vector<std::vector<int>> permute(std::vector<int>& nums)
    {
        std::vector<std::pair<int, bool>> numsState(nums.size());
        std::transform(nums.begin(), nums.end(), numsState.begin(), initializeState);
        backtrace(numsState, nums.size());
        return results;
    }

    void backtrace(std::vector<std::pair<int, bool>>& numsState, int level)
    {
        if (level == 0) {
            results.push_back(partial);
        }
        else {
            for (auto& numState : numsState) {
                auto& [num, isUsed] = numState;
                if (!isUsed) {
                    partial.push_back(num);
                    isUsed = true;
                    backtrace(numsState, level - 1);
                    partial.pop_back();
                    isUsed = false;
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
    std::vector<int> nums = {1, 2, 3};
    Solution().permute(nums);
}