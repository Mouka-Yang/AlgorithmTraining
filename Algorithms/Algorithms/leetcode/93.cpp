/*
93. Restore IP Addresses

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int a, b, c, d;
        vector<string> ans;
        for (int i = 1 ; i <= 3; i ++)
        {
            for (int j = 1 ; j <= 3; j ++)
            {
                for (int k = 1 ; k <= 3 ; k ++)
                {
                    for (int l = 1 ; l <= 3 ; l ++)
                    {
                        if (i+j+k+l != s.length())
                            continue;
                        a = atoi(s.substr(0, i).c_str());
                        if (a > 255 || (i > 1 && s[0] == '0')) continue;
                        b = atoi(s.substr(i, j).c_str());
                        if (b > 255 || (j > 1 && s[i] == '0')) continue;
                        c = atoi(s.substr(i+j, k).c_str());
                        if (c > 255 || (k > 1 && s[i+j] == '0')) continue;
                        d = atoi(s.substr(i+j+k, l).c_str());
                        if (d > 255 || (l > 1 && s[i+j+k] == '0')) continue;
                        
                        ans.push_back(s.substr(0, i) + "." + s.substr(i, j) + "." + s.substr(i+j, k) + "." + s.substr(i+j+k, l));
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    string s = "25525511135";
    vector<string> res;
    res = Solution().restoreIpAddresses(s);
    for_each(res.begin(), res.end(), [](const string& s){cout << s << " ";});
}
