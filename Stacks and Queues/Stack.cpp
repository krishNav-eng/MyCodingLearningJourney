#include <bits/stdc++.h>

using namespace std;

class Stack {
private:
    int cap;
    int *S;
    int t;

public:
    Stack(int sz) : cap(sz), t(-1) {
        S = new int[cap];
    }

    ~Stack() {
        delete[] S;
    }

    void push(int x) {
        if(t>=cap-1) {
            cout<<"Stack overflow\n";
            return;
        }
        S[++t] = x;
    }

    int pop() {
        if(t==-1) {
            cout<<"Stack underflow\n";
            return -1;
        } return S[t--];
    }

    int top() const() {
        if(t==-1) {
            cout<<"Stack is empty\n";
            return -1;
        }
        return S[t];
    }

    bool isEmpty() const() {
        return t==-1;
    }

    int size() const() {
        return t+1;
    }
}