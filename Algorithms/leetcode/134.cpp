#include "header.h"

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
    {
        auto stationNum = gas.size();

        std::vector<int> remainGas(stationNum, 0);
        std::transform(gas.cbegin(), gas.cend(), cost.cbegin(), remainGas.begin(),
                       [](const int& x, const int& y) { return x - y; });
        auto finalGas = std::accumulate(remainGas.cbegin(), remainGas.cend(), 0);

        if (finalGas < 0) {
            return -1;
        }

        auto currentTotalGas = 0;
        auto currentStart    = 0;
        for (auto i = 0; i < stationNum; i++) {
            currentTotalGas = currentTotalGas + remainGas[i];
            if (currentTotalGas < 0) {
                currentTotalGas = 0;
                currentStart    = i + 1;
            }
        }

        return stationNum > currentStart ? currentStart : -1;
    }
};