#include <vector>
#include <iostream>

using namespace std;

class Node {
    public:
    Node *next;
    int value;

    Node(int v) : next(nullptr), value(v) {}
    ~Node() { if(next) delete next; }
};

class LinkedList {
    public:
    Node *head;

    LinkedList() : head(nullptr) {}
    ~LinkedList() { if(head) delete head; }

    void insert(int x) {
        Node *n = new Node(x);
        Node *curr = head;

        if(!head) {
            head = n;
            return;
        }

        if(x <= head->value) {
            n->next = head;
            head = n;
            return;
        }

        while(curr && curr->next && x >= curr->next->value) {
            curr = curr->next;
        }
        n->next = curr->next;
        curr->next = n;
    }
};

void bucket_sort(vector<int> &a) {
    int n = a.size();
    LinkedList buckets[10];

    for(int i=0; i<n; i++) {
        int b = a[i] / 10;
        buckets[b].insert(a[i]);
    }

    int i=0;
    for(int b=0; b<10; b++) {
        Node *curr = buckets[b].head;
        while(curr && i<n) {
            a[i] = curr->value;
            curr = curr->next;
            i++;
        }
    }
}