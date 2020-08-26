/*
Design HashSet

Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:

add(value): Insert a value into the HashSet. 
contains(value) : Return whether the value exists in the HashSet or not.
remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

Example:

MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // returns true
hashSet.contains(3);    // returns false (not found)
hashSet.add(2);          
hashSet.contains(2);    // returns true
hashSet.remove(2);          
hashSet.contains(2);    // returns false (already removed)

Note:

All values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
Please do not use the built-in HashSet library.
*/

#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;

class MyHashSet {
   private:
    const int defaultSize = 10;
    const int defaultValue = 9876543;
    const float maxLoadFactor = 0.75;

    int entryCount;
    vector<int> buckets;

    auto getLoadFactor() {
        return static_cast<float>(entryCount / buckets.size());
    }
    auto getHashIndex(int key) {
        return hash<int>()(key) % buckets.size();
    }
    void rehash() {
        auto oldBuckets(move(buckets));
        buckets.resize(oldBuckets.size() * 2);
        fill(buckets.begin(), buckets.end(), defaultValue);

        for (auto x : oldBuckets) {
            if (x != defaultValue) {
                add(x);
            }
        }
    }

   public:
    /** Initialize your data structure here. */
    MyHashSet() : entryCount(0), buckets() {
    }

    void add(int key) {
        if (getLoadFactor() > maxLoadFactor) {
            rehash();
        }

        auto hashIdx = getHashIndex(key);
        while (buckets[hashIdx] != defaultValue) {
            if (buckets[hashIdx] == key) {
                return;
            }
            hashIdx = (hashIdx + 1) % buckets.size();
        }
        buckets[hashIdx] = key;
        entryCount++;
    }

    void remove(int key) {
        auto hashIdx = getHashIndex(key);
        auto oldIdx = hashIdx;

        auto removeIdx = defaultValue;
        while (buckets[hashIdx] != defaultValue) {
            if (removeIdx == defaultValue && buckets[hashIdx] == key) {
                removeIdx = hashIdx;
                buckets[hashIdx] = defaultValue;
                entryCount--;
            } else if (removeIdx != defaultValue && getHashIndex(buckets[hashIdx]) == oldIdx) {
                swap(buckets[removeIdx], buckets[hashIdx]);
                removeIdx = hashIdx;
            }
            hashIdx = (hashIdx + 1) % buckets.size();
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto hashIdx = getHashIndex(key);
        while (buckets[hashIdx] != defaultValue) {
            if (buckets[hashIdx] == key) {
                return true;
            }
            hashIdx = (hashIdx + 1) % buckets.size();
        }
        return false;
    }
};
