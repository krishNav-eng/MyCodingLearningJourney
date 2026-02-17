#include <bits/stdc++.h>

using namespace std;


class MyQueue {
private:
    stack<int> in_stack, out_stack;

    void transfer() {
        if(out_stack.empty()) {
            while(!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
    }

public:
    void push(int x) {
        in_stack.push(x);
    }

    int pop() {
        if(empty()) throw runtime_error("Queue is empty");
        transfer();
        int val = out_stack.top();
        out_stack.pop();
        return val;
    }
    
    int peek() {
        if(empty()) throw runtime_error("Queue is empty");
        transfer();
        return out_stack.top();
    }

    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }
};