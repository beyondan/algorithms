#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#endif

#include "LinkedList.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

template<class T>
struct HashEntry {
    int key;
    T value;
    HashEntry(int k, T v) : key(k), value(v) {}
};

template<class T>
class HashTable {
    public:
    HashTable(int size=10) : size(size) {
        ht = new LinkedList<HashEntry<T>>[size];
    }
    ~HashTable() {
        delete[] ht;
    }

    T get(int key) {
        int k = key % size;
        
        LinkedList<HashEntry<T>> l = ht[k];
        LLNode* curr = l.head;
        
        while(curr) {
            HashEntry<T> entry = curr->value;
            if(entry.key == key) {
                return entry.value;
            }
        }

        throw out_of_range("Key not found.");
    }

    void set(int key, T value) {
        int k = key % size;
        HashEntry<T> *newEntry = new HashEntry<T>(key, value);

        vector<HashEntry<T>*> v = ht[k];
        int vsize = v.size();

        for(int i=0; i<vsize; i++) {
            if(v[i]->key == key) {
                v[i] = newEntry;
                return;
            }
        }

        cout << "Adding new entry: " << newEntry->key << ", " << newEntry->value << endl;
        v.push_back(newEntry);
    }

    bool contains(int key) {
        int k = key % size;

        vector<HashEntry<T>*> v = ht[k];
        int vsize = v.size();

        for(int i=0; i<vsize; i++) {
            if(v[i]->key == key) {
                return true;
            }
        }
        return false;
    }

    string str() {
        stringstream ss;
        for(int i=0; i<size; i++) {
            ss << i << " -> [";
            vector<HashEntry<T>*> v = ht[i];
            int vsize = v.size();
            if(vsize == 0) {
                ss << "]" << endl;
                continue;
            }

            for(int j=0; j<vsize-1; j++) {
                ss << "(" << v[j]->key << "," << v[j]->value << "), ";
            }
            ss << "(" << v[vsize-1]->key << "," << v[vsize-1]->value << ")]" << endl;
        }
        return ss.str();
    }

    private:
    int size;
    LinkedList<HashEntry<T>> ht[];
};
