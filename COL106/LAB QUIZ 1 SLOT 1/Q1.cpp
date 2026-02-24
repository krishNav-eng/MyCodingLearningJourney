#include <bits/stdc++.h>
using namespace std;

class Pile {
private:
    int capacity;
    int *S;
    int top;

public:
    Pile(int capacity) {
        capacity = capacity;
        S = new int[capacity];
        top = -1;
    }

    int insert(int x) {
        if(top>=capacity-1) {
            return -1;
        }
        S[++top] = x;
        return 0;
    }

    int delete_item() {
        if(top<0) {
            return -1;
        }
        top--;
        return 0;
    }

    int end_item() {
        if(top<0) {
            return -1;
        }
        return S[top];
    }

    int size() {
        return top+1;
    }
};