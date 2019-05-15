/*
All O`one Data Structure

Implement a data structure supporting the following operations:

Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".
Challenge: Perform all these in O(1) time complexity.
*/

#include <algorithm>
#include <functional>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

class AllOne {
   private:
    int maxIndex;
    int secondMaxIndex;
    int minIndex;
    int secondMinIndex;
    vector<string> keyList;
    unordered_map<string, pair<int, int>> entryMap;

   public:
    /** Initialize your data structure here. */
    AllOne() : maxIndex(-1),
               secondMaxIndex(-1),
               minIndex(-1),
               secondMinIndex(-1),
               keyList(),
               entryMap() {
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (entryMap.count[key] == 0) {
            keyList.push_back(key);
            entryMap[key] = make_pair(1, keyList.size() - 1);
        } else {
            entryMap[key].first++;
        }

        if (entryMap[key].first > entryMap[keyList[maxIndex]].first) {
            maxIndex = entryMap[key].second;
            
        } else if (entryMap[key].first < entryMap[keyList[minIndex]].first) {
            minIndex = entryMap[key].second;
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */