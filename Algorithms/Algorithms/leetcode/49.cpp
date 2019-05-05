#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mymap;
        vector<vector<string>> res;
        vector<int> count(26);
        for(auto& s : strs){
            fill(count.begin(), count.end(), 0);
            string tmp = "";
            for(auto& c : s){
                count[c-'a']++;
            }
            for(auto& i: count){
                tmp += "#";
                tmp += to_string(i);
            }
            mymap[tmp].push_back(s);
        }
        for (auto& x : mymap){
            res.push_back(x.second);
        }
       
        return res;
    }
};

int main(){
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat" };
    auto res = Solution().groupAnagrams(strs);
    for (auto& x : res){
        for_each(x.begin(), x.end(), [](const string& s){cout << s << " ";});
        cout << endl;
    }
}