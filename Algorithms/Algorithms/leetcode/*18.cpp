#include "header.h"

class Solution {
   public:
    using VectorIter = std::vector<int>::const_iterator;
    std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
    {
        std::sort(nums.begin(), nums.end());
        sumToTarget(nums, 0, target);
        return results_;
    }

    void sumToTarget(std::vector<int> &nums, int start, int target)
    {
        auto length = nums.size();
        if (currentRes_.size() == MaxNum) {
            if (target == 0) {
                results_.push_back(currentRes_);
            }
        }
        else {
            while (start != length) {
                auto remain = target - nums[start];
                currentRes_.push_back(nums[start]);
                sumToTarget(nums, start + 1, remain);
                currentRes_.pop_back();

                start = skipEqualElements(nums, start + 1);
            }
        }
    }

    int skipEqualElements(std::vector<int> &nums, int start)
    {
        auto length = nums.size();
        while (start != length) {
            if (nums[start] == nums[start - 1]) {
                start++;
            }
            else {
                break;
            }
        }
        return start;
    }

   private:
    std::vector<int> currentRes_{};
    std::vector<std::vector<int>> results_{};
    const int MaxNum = 4;
};

int main()
{
    std::vector<int> nums{1, 0, -1, 0, -2, 2};
    Solution().fourSum(nums, 0);
}