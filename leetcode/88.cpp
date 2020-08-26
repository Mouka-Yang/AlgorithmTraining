/*
Merge Sorted Array

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, pre_i = 0, pre_j = 0;
        int len1 = nums1.size(), len2 = nums2.size();
        while (i -j < m){
            pre_j = j;
            while(j < len2){
                if (nums1[i] <= nums2[j]) break;
                j++;
            }
            if (j != pre_j){
                copy(nums1.begin() + i, nums1.begin() + pre_j + m, nums1.begin() + i + j - pre_j);
                copy(nums2.begin() + pre_j, nums2.begin() + j, nums1.begin() + i);
                i += j - pre_j;
            }
            if (j == len2) break;
            i++;
        }
        if (j != len2){
            copy(nums2.begin() + j, nums2.begin() + len2, nums1.begin() + i);
        }
    }
};

int main(){
    // vector<int> n1 = {-1,0,0,0,3,0,0,0,0,0,0};
    // vector<int> n2 = {-1,-1,0,0,1,2};
    // Solution().merge(n1, 5, n2, 6);
    vector<int> n{1, 5, 4, 3, 9, 7, 8};
    make_heap(n.begin(), n.end(), [](const int x, const int y) { return x > y; });
    for (auto i : n)
        cout << i << ' ';
    cout << "\n";
}

/*
[-1,0,0,0,3,0,0,0,0,0,0]
5
[-1,-1,0,0,1,2]
6
*/