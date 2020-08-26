/*
Implement Queue using Stacks

Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Example:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false
Notes:

You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/

#include <algorithm>
#include <numeric>
#include <stack>
#include <vector>
using namespace std;

class MyQueue {
   private:
    stack<int> _s;

   public:
    /** Initialize your data structure here. */
    MyQueue() : _s() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> tmp;
        while(!_s.empty()){
            tmp.push(_s.top());
            _s.pop();
        }
        _s.push(x);

        while(!tmp.empty()){
            _s.push(tmp.top());
            tmp.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        auto x = _s.top();
        _s.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        return _s.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return _s.empty();
    }
};
