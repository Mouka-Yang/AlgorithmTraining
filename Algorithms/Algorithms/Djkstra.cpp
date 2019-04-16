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

int main()
{
	const auto maxDist = 1000;
	// vector<vector<int>> graph =
	//     {{0, 4, 0, 0, 0, 0, 0, 8, 0},
	//      {4, 0, 8, 0, 0, 0, 0, 11, 0},
	//      {0, 8, 0, 7, 0, 4, 0, 0, 2},
	//      {0, 0, 7, 0, 9, 14, 0, 0, 0},
	//      {0, 0, 0, 9, 0, 10, 0, 0, 0},
	//      {0, 0, 4, 14, 10, 0, 2, 0, 0},
	//      {0, 0, 0, 0, 0, 2, 0, 1, 6},
	//      {8, 11, 0, 0, 0, 0, 1, 0, 7},
	//      {0, 0, 2, 0, 0, 0, 6, 7, 0}};
	// auto v_num = graph[0].size();

	const vector<vector<int>> edges = {
		{0, 1, 4},
		{0, 7, 8},
		{1, 2, 8},
		{1, 7, 11},
		{2, 3, 7},
		{2, 5, 4},
		{2, 8, 2},
		{3, 4, 9},
		{3, 5, 14},
		{4, 5, 10},
		{5, 6, 2},
		{6, 7, 1},
		{6, 8, 6},
		{7, 8, 7} };

	unordered_map <int, vector<pair<int, int>>> adj_map;
	set<int> vertices;
	for (auto& edge : edges) {
		adj_map[edge[0]].push_back(make_pair(edge[1], edge[2]));
		adj_map[edge[1]].push_back(make_pair(edge[0], edge[2]));
		vertices.insert({ edge[0], edge[1] });
	}
	auto v_num = vertices.size();

	for (auto& x : adj_map) {
		cout << x.first << " ";
		for (auto& y : x.second) {
			cout << "(" << y.first << "," << y.second << ")" << " ";
		}
		cout << endl;
	}
	vector<int> shortest_paths(v_num, maxDist);
	vector<int> visited(v_num, 0);
	vector<pair<int, int> > adjs;
	shortest_paths[0] = 0;
	adjs.push_back(make_pair(0, 0));
	visited[0] = 1;
	while (!adjs.empty())
	{
		auto cur_pair = adjs.back();
		auto cur = cur_pair.first;
		adjs.pop_back();

		for (auto i = 0; i < v_num; i++)
		{
			// if i is a adjacent vertex of cur
			auto cur_adj = find_if(adj_map[cur].begin(), adj_map[cur].end(), [&i](const pair<int, int>& p){ return p.first == i; });
			//cout << i << " " << cur_adj->first << " " << cur_adj->second << endl;
			if (cur_adj != adj_map[cur].end())
			{
				shortest_paths[i] = (shortest_paths[cur] + cur_adj->second) > shortest_paths[i] ? 
					shortest_paths[i] : 
					shortest_paths[cur] + cur_adj->second;
				if (!visited[i])
				{
					adjs.push_back(make_pair(i, shortest_paths[i]));
					visited[i] = 1;
				}
			}
		}
		sort(adjs.begin(), adjs.end(),
			[](const pair<int, int> &a, const pair<int, int> &b) -> bool {
			return a.second > b.second;
		});
		for (auto &x : adjs)
		{
			cout << "(" << x.first << "," << x.second << ") ";
		}
		cout << endl;
	}
	for (auto &x : shortest_paths)
	{
		cout << x << " ";
	}
	cout << endl;
}