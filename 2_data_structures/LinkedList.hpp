#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#endif

#include <sstream>

using namespace std;

template<class T>
class LLNode {
    public:
    LLNode<T> *next, *prev;
    int value;

    LLNode(int x) : next(nullptr), prev(nullptr), value(x) {}
    ~LLNode() {
        if(next) delete next;
        next = nullptr;
        prev = nullptr;
    }
};

template<class T>
class LinkedList {
    public:
    LLNode<T> *head, *tail;
    
    LinkedList() : head(nullptr), tail(nullptr) {}
    ~LinkedList() { 
        if(head) delete head;
        head = nullptr;
        tail = nullptr;
    }

    void insert(int x) {
        LLNode<T> *n = new LLNode<T>(x);
        _size++;

        if(!head) {
            head = tail = n;
            return;
        }

        LLNode<T> *curr = head;
        while(curr && curr->next) {
            curr = curr->next;
        }
        curr->next = n;
        n->prev = curr;
        tail = n;
    }

    void remove(int x) {
        LLNode<T> *n = find(x);
        if(n) {
            _size--;
            if(n->prev) {
                n->prev->next = n->next;
            }
            else {
                head = n->next;
            }
            if(n->next) {
                n->next->prev = n->prev;
            }
            else {
                tail = n->prev;
            }
            n->next = nullptr;
            n->prev = nullptr;
            delete n;
        }
    }

    LLNode<T> * find(int x) {
        LLNode<T> *curr = head;
        while(curr) {
            if(curr->value == x) {
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;
    }

    string str() {
        stringstream ss;
        if(!head) return "";
    
        LLNode<T> *curr = head;
        while(curr && curr->next) {
            ss << curr->value << " -> ";
            curr = curr->next;
        }
        ss << curr->value;
        return ss.str();
    }

    int size() {
        return _size;
    }

    private:
    int _size=0;
};
