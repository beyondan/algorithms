
#include "HashTable.hpp"
#include "LinkedList.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

#include <iostream>
#include <stdexcept>
#include <stdlib.h>
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
    HashTable<int> ht(10);

    cout << "==== HASH TABLE ====" << endl;
    for(int i=0; i<100; i++) {
        ht.set(i, i);
    }
    
    for(int i=0; i<10; i++) {
        int rn = rand() % 100;
        int got = ht.get(rn);
        if(got != rn) {
            cout << "Get '" << rn << "' should not return '" << got << "'" << endl;
            cout << ht.str() << endl;
            return;
        }
    }

    ht.set(96, 111);
    if(ht.get(96) != 111) {
        cout << "Get 96 should return 111" << endl;
        return;
    }

    try {
        cout << ht.get(99999) << endl;
        cout << "Get 99999 should error and not print this line." << endl;
        return;
    }
    catch(out_of_range e) {
    }
    
    cout << "PASSED" << endl;
}

int main() {
    test_stack();
    test_queue();
    test_linkedlist();
    test_hashtable();

    return 0;
}
