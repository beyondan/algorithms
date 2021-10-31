
#include "HashTable.hpp"
#include "LinkedList.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

void test_stack() {
    Stack<int> s;

    cout << "==== Stack ====" << endl;
    cout << "Push 0-9" << endl;
    for(int i=0; i<10; i++) {
        s.push(i);
    }
    cout << s.str() << endl;

    cout << "Top = " << s.top() << endl;
    cout << "Pop 9" << endl;
    s.pop();
    cout << s.str() << endl;
    cout << "Pop 8" << endl;
    s.pop();
    cout << s.str() << endl;
    cout << "Pop 7" << endl;
    s.pop();
    cout << s.str() << endl;
    cout << "Top = " << s.top() << endl;

    cout << "Pop 6-0" << endl;
    for(int i=0; i<7; i++) {
        s.pop();
    }
    cout << s.str() << endl;

    cout << "Pop (empty)" << endl;
    try {
        s.pop();
    }
    catch(out_of_range e) {
        cout << e.what() << endl;
    }

    cout << "Top (empty)" << endl;
    try {
        cout << s.top() << endl; 
    }
    catch(out_of_range e) {
        cout << e.what() << endl;
    }
}

void test_queue() {
    Queue<int> q;

    cout << "==== Queue ====" << endl;
    cout << "Enqueue 0-9" << endl;
    for(int i=0; i<10; i++) {
        q.enqueue(i);
    }
    cout << q.str() << endl;
    cout << "Head = " << q.head() << endl;
    cout << "Tail = " << q.tail() << endl;

    cout << "Dequeue 0" << endl;
    q.dequeue();
    cout << q.str() << endl;
    cout << "Head = " << q.head() << endl;
    cout << "Tail = " << q.tail() << endl;

    cout << "Dequeue 1" << endl;
    q.dequeue();
    cout << q.str() << endl;
    cout << "Head = " << q.head() << endl;
    cout << "Tail = " << q.tail() << endl;

    cout << "Enqueue 10" << endl;
    q.enqueue(10);
    cout << q.str() << endl;
    cout << "Head = " << q.head() << endl;
    cout << "Tail = " << q.tail() << endl;

    cout << "Dequeue 2" << endl;
    q.dequeue();
    cout << q.str() << endl;
    cout << "Head = " << q.head() << endl;
    cout << "Tail = " << q.tail() << endl;

    cout << "Dequeue 3-10" << endl;
    for(int i=3; i<11; i++) {
        q.dequeue();
    }

    cout << q.str() << endl;
    try {
        cout << "Head = " << q.head() << endl;
    }
    catch(out_of_range e) {
        cout << e.what() << endl;
    }
    try {
        cout << "Tail = " << q.tail() << endl;
    }
    catch(out_of_range e) {
        cout << e.what() << endl;
    }
}

void test_linkedlist() {
    LinkedList<int> l;

    cout << "==== LinkedList ====" << endl;
    cout << "Insert 0-9" << endl;
    for(int i=0; i<10; i++) {
        l.insert(i);
    }
    cout << l.str() << endl;
    cout << "Find 5" << endl;
    cout << l.find(5)->value << endl;

    cout << "Remove 3" << endl;
    l.remove(3);
    cout << l.str() << endl;

    cout << "Remove 0" << endl;
    l.remove(0);
    cout << l.str() << endl;

    cout << "Remove 9" << endl;
    l.remove(9);
    cout << l.str() << endl;
}

void test_hashtable() {
    HashTable<int> ht;

    cout << "==== HASH TABLE ====" << endl;
    cout << "Add 0, 4, 8, 12, ... , 96" << endl;
    for(int i=0; i<100; i+=4) {
        ht.set(i, i);
    }
    cout << ht.str() << endl;

    cout << "Get 95" << endl;
    try {
        cout << ht.get(95) << endl;
    }
    catch(out_of_range e) {
        cout << e.what() << endl;
    }

    cout << "Get 44" << endl;
    cout << ht.get(44) << endl;

    cout << "Get 96" << endl;
    cout << ht.get(96) << endl;

    cout << "Get 92" << endl;
    cout << ht.get(92) << endl;

    cout << "Get 96" << endl;
    cout << ht.get(96) << endl;

    cout << "Set 96, 111" << endl;
    ht.set(96, 111);
    cout << ht.str() << endl;
}

int main() {
    test_stack();
    test_queue();
    test_linkedlist();
    test_hashtable();

    return 0;
}
