/*
Insert Delete GetRandom O(1)

Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();
*/

#include <algorithm>
#include <functional>
#include <numeric>
#include <random>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
class RandomizedSet2 {
   private:
    enum { defaultSize = 10 };
    const int defaultValue = 9876543;

    hash<int> hashFunc;
    float maxLoadFactor;
    int entryCount;
    vector<int> buckets;

    auto getHashIndex(int val) {
        return hashFunc(val) % buckets.size();
    }
    auto getLoadFactor() {
        return static_cast<float>(entryCount / buckets.size());
    }

    bool insertHelper(int val) {
        auto hashIdx = getHashIndex(val);

        while (buckets[hashIdx] != defaultValue) {
            if (buckets[hashIdx] == val) {
                return false;
            }
            hashIdx = (hashIdx + 1) % buckets.size();
        }
        buckets[hashIdx] = val;
        entryCount++;
        return true;
    }

    bool removeHelper(int val) {
        auto hashIdx = getHashIndex(val);
        auto oldIdx = hashIdx;

        auto removeIdx = defaultValue;
        while (buckets[hashIdx] != defaultValue) {
            if (removeIdx == defaultValue && buckets[hashIdx] == val) {
                removeIdx = hashIdx;
                buckets[hashIdx] = defaultValue;
                entryCount--;
            } else if (removeIdx != defaultValue && getHashIndex(buckets[hashIdx]) == oldIdx) {
                swap(buckets[removeIdx], buckets[hashIdx]);
                removeIdx = hashIdx;
            }
            hashIdx = (hashIdx + 1) % buckets.size();
        }
        return removeIdx != defaultValue;
    }

    void rehash() {
        auto tmp(buckets);
        buckets = vector<int>(buckets.size() * 2, defaultValue);
        entryCount = 0;

        for (auto x : tmp) {
            if (x != defaultValue)
                insert(x);
        }
    }

   public:
    /** Initialize your data structure here. */
    RandomizedSet2() : hashFunc(),
                       maxLoadFactor(0.75),
                       entryCount(0),
                       buckets(defaultSize, defaultValue) {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (getLoadFactor() > maxLoadFactor) {
            rehash();
        }
        return insertHelper(val);
    }

    void insert(vector<int> &nums) {
        for (auto x : nums) {
            insert(x);
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        return removeHelper(val);
    }

    /** Get a random element from the set. */
    int getRandom() {
        if (entryCount == 0) return defaultValue;

        default_random_engine generator;
        uniform_int_distribution<int> distribution(0, buckets.size() - 1);
        auto idx = distribution(generator);

        while (buckets[idx] == defaultValue) idx = (idx + 1) % buckets.size();
        return buckets[idx];
    }
};

using RandomGenerator = std::_Binder<std::_Unforced, std::uniform_int_distribution<int> &, std::default_random_engine &>;
class RandomizedSet {
   private:
    vector<int> entryList;
    unordered_map<int, int> entryMap;
    default_random_engine generator;

   public:
    /** Initialize your data structure here. */
    RandomizedSet() : entryList(),
                      entryMap(),
                      generator() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (entryMap.count(val) != 0) {
            return false;
        }

        entryList.push_back(val);
        entryMap[val] = entryList.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (entryMap.count(val) == 0) {
            return false;
        }

        auto removeIdx = entryMap[val];
        entryList[removeIdx] = entryList.back();
        entryMap[entryList.back()] = removeIdx;
        entryList.pop_back();
        entryMap.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        uniform_int_distribution<int> distribution(0, entryList.size() - 1);
        return entryList[distribution(generator)];
    }
};

int main() {
    RandomizedSet set;

    vector<int> n{3, -2, 2, 1, -3, -2, -2, 3, -1, -3, 1, -2, -2, -2, 1, -2, 0, -3, 1};
    set.insert(3);
    set.insert(-2);
    set.remove(2);
    set.insert(1);
    set.insert(-3);
    set.insert(-2);
    set.remove(-2);
    set.remove(3);
    set.insert(-1);
    set.remove(-3);
}