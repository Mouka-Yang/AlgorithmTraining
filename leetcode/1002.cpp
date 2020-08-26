/*
 Find Common Characters
Easy

197

28

Favorite

Share
Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

 

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]
 

Note:

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter
*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> counts(26, 0);
        for(auto s:A[0]){
            counts[s - 'a']++;
        }

        for (int i = 1; i < A.size(); i++){
            for (char c = 'a'; c <= 'z'; c++){
                int cc = count(A[i].begin(), A[i].end(), c);
                counts[c - 'a'] = max(counts[c - 'a'], cc);
            }
        }

        vector<string> res;
        for (int i = 0; i < 26; i++){
            if (counts[i]) {
                res.push_back(string(1, static_cast<char>(i + 'a')));
            } 
        }
        return res;
    }
};