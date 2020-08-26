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
#include <climits>
#include <functional>
#include <list>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class AllOne2 {
   private:
    int minCount;
    int maxCount;
    vector<string> keyList;
    unordered_map<string, pair<int, int>> entryMap;
    unordered_map<int, vector<string>> stringCountMap;

   public:
    /** Initialize your data structure here. */
    AllOne2() : minCount(0), maxCount(0), keyList(), entryMap(), stringCountMap() {
    }

    void updateCountMap(string key, bool insert) {
        auto currentCount = entryMap[key].first;
        auto listIndex = entryMap[key].second;
        auto oldCount = insert ? currentCount - 1 : currentCount + 1;
        // remove from old count list
        if (!insert || currentCount != 1) {
            stringCountMap[oldCount][listIndex] =
                stringCountMap[oldCount].back();
            entryMap[stringCountMap[oldCount].back()].second = listIndex;
            stringCountMap[oldCount].pop_back();
            if (stringCountMap[oldCount].size() == 0) {
                stringCountMap.erase(oldCount);
            }
        }
        // add to new count list
        if (currentCount != 0) {
            stringCountMap[currentCount].push_back(key);
            entryMap[key].second = stringCountMap[currentCount].size() - 1;
        }
    }
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (entryMap.find(key) == entryMap.end()) {
            entryMap[key] = make_pair(1, 0);
        } else {
            entryMap[key].first++;
        }
        updateCountMap(key, true);

        auto currentCount = entryMap[key].first;
        maxCount = max(maxCount, currentCount);
        if (minCount == 0 || stringCountMap.count(minCount) == 0 || currentCount < minCount) {
            minCount = currentCount;
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (entryMap.find(key) != entryMap.end()) {
            auto currentCount = --entryMap[key].first;
            updateCountMap(key, false);

            if (stringCountMap.count(maxCount) == 0) {
                maxCount = currentCount;
            }

            if (currentCount == 0 && stringCountMap.count(minCount) == 0 && maxCount > 1) {
                for (int i = 2; i <= maxCount; i++) {
                    if (stringCountMap.count(i) != 0) {
                        minCount = i;
                        break;
                    }
                }
            } else if (currentCount != 0 && currentCount < minCount) {
                minCount = currentCount;
            }

            if (currentCount == 0) {
                entryMap.erase(key);
            }
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (entryMap.size() > 0) {
            return stringCountMap[maxCount][0];
        }
        return "";
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (entryMap.size() > 0) {
            return stringCountMap[minCount][0];
        }
        return "";
    }
};

class Bucket {
   private:
    int _count;
    unordered_set<string> _stringSet;

   public:
    Bucket(int count = 0) : _count(count), _stringSet() {}
    int getCount() { return _count; }
    void setCount(int count) { _count = count; }
    void addItem(string item) { _stringSet.insert(item); }
    void removeItem(string item) { _stringSet.erase(item); }
    int getBucketSize() { return _stringSet.size(); }
    const string& getFirstItem() { return *_stringSet.cbegin(); }
};

using CountListIter = std::list<Bucket>::iterator;

class AllOne {
   private:
    list<Bucket> buckets;
    unordered_map<string, int> keyMap;
    unordered_map<int, CountListIter> CountMap;

   public:
    /** Initialize your data structure here. */
    AllOne() : buckets({Bucket(-1)}), keyMap(), CountMap() {
    }

    void updateCountMap(string key, bool insert) {
        int currentCount = keyMap[key];
        int oldCount = insert ? currentCount - 1 : currentCount + 1;

        auto oldBucketIter = oldCount == 0 ? buckets.begin() : CountMap[oldCount];
        auto newBucketIter = oldBucketIter;

        // if not dec the key with value 1, 
        // then insert the key to new bucket
        if (currentCount != 0) {
            if (CountMap.count(currentCount) != 0) {
                // if current count bucket not empty
                newBucketIter = CountMap[currentCount];
            } else {
                // if current count bucket is empty
                if (insert) {
                    // if insert operation, insert new count bucket after old one
                    newBucketIter = buckets.insert(next(oldBucketIter), Bucket(currentCount));
                } else {
                    // else insert before the old one
                    newBucketIter = buckets.insert(oldBucketIter, Bucket(currentCount));
                }
                CountMap[currentCount] = newBucketIter;
            }
            newBucketIter->addItem(key);
        }

        // if not insert a new key,
        // then remove it from old bucket
        if (!insert || currentCount != 1) {
            oldBucketIter->removeItem(key);
            if (oldBucketIter->getBucketSize() == 0) {
                CountMap.erase(oldBucketIter->getCount());
                buckets.erase(oldBucketIter);
            }
        }
    }
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (keyMap.count(key) != 0) {
            keyMap[key]++;
        } else {
            keyMap[key] = 1;
        }
        updateCountMap(key, true);
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (keyMap.count(key) != 0) {
            keyMap[key]--;
            updateCountMap(key, false);

            if (keyMap[key] == 0){
                keyMap.erase(key);
            }
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (keyMap.size() > 0) {
            return prev(buckets.end())->getFirstItem();
        }
        return "";
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (keyMap.size() > 0) {
            return next(buckets.begin())->getFirstItem();
        }
        return "";
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

int main() {
    AllOne all;
    // all.inc("bbb");
    // all.inc("aaa");
    // all.inc("aaa");
    // all.inc("aaa");
    // all.inc("aaa");
    // all.inc("aaa");
    // all.inc("aaa");
    // all.inc("aaa");
    // all.inc("aaa");
    // all.inc("aaa");
    // all.inc("aaa");
    // all.inc("aaa");
    // all.inc("bbb");
    // all.inc("bbb");
    all.inc("ccc");
    all.inc("ccc");
    all.getMaxKey();
    all.getMinKey();
    all.inc("bbb");
    all.getMaxKey();
    all.getMinKey();

}