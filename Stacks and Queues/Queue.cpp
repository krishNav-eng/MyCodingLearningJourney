#include <bits/stdc++.h>

using namespace std;


class Queue {
private:
    int cap;
    int *Q;
    int f, b;

public:
    Queue(int sz) : cap(sz), f(0), b(0) {
        Q = new int[cap];
    }

    ~Queue() {
        delete[] Q;
    }

    void enqueue(int x) {
        if((b+1)%cap==f) {
            cout<<"Queue overflow\n";
            return;
        } 
        Q[b] = x;
        b = (b+1)%cap;
    }

    int dequeue() {
        if(f==b) {
            cout<<"Queue underflow\n";
            return -1;
        } 
        int x = Q[f];
        f = (f+1)%cap;
        return x;
    }

    int front() const() {
        if(f==b) {
            cout<<"Queue is empty\n";
            return -1;
        }
        return Q[f];
    }

    int size() const() {
        return (b-f+cap)%cap;
    }

    bool isEmpty() const() {
        return f==b;
    }
};