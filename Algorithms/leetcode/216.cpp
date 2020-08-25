#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    void subsub(vector<int>& partial, vector<vector<int>>& res, int index, int count, int rem) {
        if (count == 0) {
            if (rem == 0)
                res.push_back(partial);
            return;
        }

        for (int i = index; i <= 9 && rem >= i; i++) {
            partial.push_back(i);
            subsub(partial, res, i + 1, count - 1, rem - i);
            partial.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> partial;
        subsub(partial, res, 1, k, n);
        return res;
    }
};

int main() {
    Solution().combinationSum3(3, 9);
}
