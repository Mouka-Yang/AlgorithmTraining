#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> adj = {
        {1, 2, 3},
        {4, 5},
        {4, 6},
        {}, 
        {},
        {},
        {}};

    vector<int> vs(7, 0);
    auto count = 0;
    for (auto subadj : adj) {
        vs[count++] = subadj.size();
    }

    vector<int> ends;
    vector<int> result;
    vector<int> visited(7, 0);
    for (auto i = 0; i < vs.size(); i++)
        if (!vs[i]) {
            ends.push_back(i);
        }

    while (!ends.empty()) {
        auto cur = ends.back();
        ends.pop_back();
        result.push_back(cur);
        visited[cur] = 1;
        for (auto i = 0; i < vs.size(); i++) {
            for (auto c : adj[i]) {
                if (c == cur && !visited[i]) {
                    if (--vs[i] == 0)
                        ends.insert(ends.begin(), i);
                }
            }
        }
        // if (adj[i][cur] &&)
        //     ends.insert(ends.begin(), i);
    }
    for (auto c : result)
        cout << c << " ";
    cout << "\n";
    cout << "Hello World!" << endl;
}