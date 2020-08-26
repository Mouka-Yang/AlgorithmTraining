/*
Longest Substring with At Least K Repeating Characters

Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestSubstring2(string s, int k) {
        auto len = s.size();
        auto max = 0;
        auto max_unqiue = 0;
        vector<int> counts(26, 0);

        for (const char c : s) {
            counts[c - 'a']++;
        }
        for (const int c : counts) {
            if (c >= k) max_unqiue++;
        }

        for (auto i = 1; i <= max_unqiue; i++) {
            auto start = 0, end = 0, unique = 0, satisfy = 0, idx = 0;
            fill(counts.begin(), counts.end(), 0);

            while (end < len) {
                if (unique <= i) {
                    idx = s[end] - 'a';
                    if (counts[idx]++ == 0)
                        unique++;
                    if (counts[idx] == k)
                        satisfy++;

                    end++;
                } else {
                    idx = s[start] - 'a';
                    if (--counts[idx] == k - 1)
                        satisfy--;
                    if (counts[idx] == 0)
                        unique--;
                    start++;
                }
                if (i == unique && unique == satisfy)
                    max = max < end - start ? end - start : max;
            }
        }

        return max;
    }

    int longestSubstring(string s, int k) {
        int n = s.size();
        if (n == 0 || n < k) return 0;
        if (k == 0 || k == 1) return n;
        return divided(s, k, 0, n - 1);
    }
    int divided(string s, int k, int left, int right) {
        if (left > right) return 0;
        vector<int> m(26, 0);
        for (int i = left; i <= right; i++) {
            m[s[i] - 'a']++;
        }
        while (left <= right && m[s[left] - 'a'] < k) {
            left++;
        }
        while (left <= right && m[s[right] - 'a'] < k) {
            right--;
        }
        for (int i = left; i <= right; i++) {
            if (m[s[i] - 'a'] < k) {
                return max(divided(s, k, left, i - 1), divided(s, k, i + 1, right));
            }
        }
        return right - left + 1;
    }
};

int main() {
    string s = "aabba";
    cout << Solution().longestSubstring(s, 2) << "\n";
}