#include <bits/stdc++.h>
using namespace std;

class Set {
private:
    int size;
    int capacity;
    int *arr;

public:
    Set(int capacity) {
        capacity = capacity;
        size = 0;
        arr = new int[capacity];
    }

    int insert(int x) {
        for(int i = 0; i < size; i++) {
            if(arr[i] == x) {
                return -1;
            }
        }
        arr[size] = x;
        size++;
        return 1;
    }

    int remove(int x) {
        for(int i=0; i<size; i++) {
            if(arr[i] == x) {
                for(int j=i; j<size-1; j++) {
                    arr[j]=arr[j+1];
                }
                size--;
                return 1;
            }
        }
        return -1;
    }

    bool contains(int x) {
        for(int i=0; i<size; i++) {
            if(arr[i]==x) return true;
        }
        return false;
    }

    int size() {
        return size;
    }

    void display() {
        for(int i=0; i<size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
