#include <bits/stdc++.h>
#include <vector>

using namespace std;

class MyCircularDeque {
private:
    vector<int> data;
    int size;
    int cap;
    int front;
    int rear;

public:
    MyCircularDeque(int k) : size(0), cap(k), front(0), rear(k-1) {
        data.resize(k);
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        front=(front-1+cap)%cap;
        data[front]=value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        rear=(rear+1)%cap;
        data[rear]=value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        front=(front+1)%cap;
        size--;
        return true;
        
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        rear=(rear-1+cap)%cap;
        size--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return data[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return data[rear];
    }
    
    bool isEmpty() {
        return (size==0);
        
    }
    
    bool isFull() {
        return (size==cap);
    }
};
