/*
 Cheapest Flights Within K Stops


There are n cities connected by m flights. Each fight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input:
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200

Example 2:
Input:
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500

Note:

The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
The size of flights will be in range [0, n * (n - 1) / 2].
The format of each flight will be (src, dst, price).
The price of each flight will be in the range [1, 10000].
k is in the range of [0, n - 1].
There will not be any duplicated flights or self cycles.

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

class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
		const auto maxDist = 10000;

		vector<vector<int>> dp(K + 2, vector<int>(n, maxDist));
		dp[0][src] = 0;
		for (auto i = 1; i < K + 2; i++) {
			dp[i][src] = 0;
			for (auto& e : flights) {
				dp[i][e[1]] = min(dp[i][e[1]], dp[i - 1][e[0]] + e[2]);
			}
		}
		return dp[K + 1][dst] < maxDist ? dp[K + 1][dst] : maxDist;
	}
};

int main() {
	vector<vector<int>> test = {
		{0,1,100},
		{1,2,100},
		{0,2,500}
	};
	cout << Solution().findCheapestPrice(3, test, 0, 2, 1) << endl;
}