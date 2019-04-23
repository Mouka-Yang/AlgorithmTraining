/*
Find the Duplicate Number

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <set>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

class Solution
{
  public:
    int findDuplicate(vector<int> &nums)
    {
        // auto tmp = 0 ;
        // for (auto i = 0 ; i < nums.size(); i++){
        // while(nums[i] != i+1){
        //     tmp = nums[i];
        //     if (nums[i] == nums[tmp-1]) return nums[i];

        //     nums[i] = nums[tmp-1];
        //     nums[tmp-1] = tmp;
        // }

        // for_each(nums.begin(), nums.end(), [](const int x){cout << x << " ";});
        // cout << endl;
        // }

        // return 0;
        auto fast = 0, slow = 0;
        do
        {
            fast = nums[nums[fast] ];
            slow = nums[slow];
        } while (fast != slow);

        slow = 0;
        do
        {
            fast = nums[fast];
            slow = nums[slow];
        } while (fast != slow);

        return slow ;
    }
};

int main()
{
    vector<int> n{1,3,4,2,2};
    // vector<int> n{8, 7, 1, 10, 17, 15, 18, 11, 16, 9, 19, 12, 5, 14, 3, 4, 2, 13, 18, 18};
    cout << Solution().findDuplicate(n) << endl;
}