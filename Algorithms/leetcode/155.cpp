/*
Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class MinStack {
   private:
    vector<int> _arr;
    vector<int> _mins;

   public:
    /** initialize your data structure here. */
    MinStack() : _arr(), _mins() {
    }

    void push(int x) {
        _arr.push_back(x);
        if (_mins.empty()||x <= _mins.back()){
            _mins.push_back(x);
        }
    }

    void pop() {
        if (_arr.size() > 0) {
            int x = _arr.back();
            _arr.pop_back();
            
            if (x == _mins.back()){
                _mins.pop_back();
            }
        }
    }

    int top() {
        return _arr.back();
    }

    int getMin() {
        return _mins.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    s.pop();
    s.top();
    s.getMin();
}