#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template <typename K, typename V>


class PriorityQueue
{
private:
    struct {
        K key;
        V value;
        Node* prev;
        Node* next;

        Node(K k, V, v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    }

    Node* head;
    Node* tail;
    int n;
public:
    PriorityQueue() : head(nullptr), tail(nullptr), n(0) {};
    
    int size() const { return n; }
    bool isEmpty() const { return n==0; }

    void insert(const K& k, const V& v) {
        Node* newNode = new Node(k, v);
        if(isEmpty()){
            head=tai=newNode;
        } else if(k<head->key) {
            newNode->next=head;
            head->prev = newNode;
            head=newNode;
        } else {
            Node* curr=head;
            while(curr->next && curr->next->key<=k) {
                curr=curr->next;
            }
            newNode->next=curr->next;
            newNode->prev=curr;
            if(curr->next){
                curr->next->prev=newNode;
            } else tail=newNode;
            curr->next=newNode;
        }
        n++;
    }

    void removeMin() {
        if(isEmpty()) throw runtime_error("Priority Queue is empty");
        Node* temp=head;
        head=head->next;
        if(head) head->prev=nullptr;
        else tail=nullptr;
        delete temp;
        n--;
    }

    const V& min() const {
        if(isEmpty()) throw runtime_error("Priority Queue is empty");
        return head->value;
    }

};


int main() {
    
}