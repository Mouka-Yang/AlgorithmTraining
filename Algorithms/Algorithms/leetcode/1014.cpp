/*
Best Sightseeing Pair

Given an array A of positive integers, A[i] represents the value of the i-th sightseeing spot, and two sightseeing spots i and j have distance j - i between them.

The score of a pair (i < j) of sightseeing spots is (A[i] + A[j] + i - j) : the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.

 

Example 1:

Input: [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11
 

Note:

2 <= A.length <= 50000
1 <= A[i] <= 1000
*/
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int maxSum = INT_MIN, maxCur = INT_MIN;
        for(auto x : A){
            maxSum = max(x + maxCur, maxSum);
            maxCur = max(maxCur, x) - 1;
        }
        return maxSum;
    }
};

int main(){
    vector<int> n{6, 9, 10, 5, 9, 10, 4, 5};
    Solution().maxScoreSightseeingPair(n);
}