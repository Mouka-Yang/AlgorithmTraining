#include <algorithm>
#include <map>
#include <vector>
class Solution {
public:
    bool carPooling(std::vector<std::vector<int>>& trips, int capacity)
    {
        std::map<int, int> pool_map{};
        bool success{true};

        for (const auto& trip : trips) {
            auto start{trip[1]};
            auto end{trip[2]};
            auto num{trip[0]};

            pool_map[start] -= num;
            pool_map[end] += num;
            if (pool_map[start] + capacity < 0) {
                success = false;
                break;
            }
        }

        if(!success){
            return false;
        }

        int sum{0};
        for (const auto [_, num] : pool_map) {
            sum += num;
            if (num + capacity < 0) {
                success = false;
                break;
            }
        }

        return false;
    }
};
