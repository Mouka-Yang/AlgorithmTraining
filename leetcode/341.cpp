/*
Flatten Nested List Iterator

Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:

Input: [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,1,2,1,1].
Example 2:

Input: [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,4,6].
             */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

#include "header.h"

class NestedInteger {
   public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger>& getList() const;
};

using ListIter = vector<NestedInteger>::const_iterator;
class NestedIterator {
   private:
    stack<ListIter> begins, ends;

   public:
    NestedIterator(vector<NestedInteger>& nestedList) : begins(), ends() {
        begins.push(nestedList.cbegin());
        ends.push(nestedList.cend());
    }

    int next() {
        //  cur is a num, output it
        return (begins.top()++)->getInteger();
    }

    bool hasNext() {
        while (!begins.empty()) {
            // if current list goes to the end
            if (begins.top() == ends.top()){
                begins.pop();
                ends.pop();
            } else{
                if (begins.top()->isInteger()){
                    return true;
                }

                auto& newList = begins.top()->getList();
                // if current item is a list
                begins.top()++; // move to next element
                // push new list to the stack
                begins.push(newList.cbegin());
                ends.push(newList.cend());
            }
        }
        return false;
    }
};

int main() {
}