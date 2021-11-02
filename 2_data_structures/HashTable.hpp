#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

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
    HashTable(int size=10) : _size(size) {
        ht = new LinkedList<HashEntry<T>*>* [size];
        for(int i=0; i<size; i++) {
            ht[i] = new LinkedList<HashEntry<T>*>();
        }
    }
    ~HashTable() {
        for(int i=0; i<_size; i++) {
            delete ht[i];
        }
        delete ht;
        ht = nullptr;
    }

    T get(int key) {
        int k = key % _size;
        
        LinkedList<HashEntry<T>*> *l = ht[k];
        LLNode<HashEntry<T>*> *curr = l->head;
        
        while(curr) {
            HashEntry<T> *entry = curr->value;
            if(entry->key == key) {
                return entry->value;
            }
            curr = curr->next;
        }

        throw out_of_range("Key not found.");
    }

    void set(int key, T value) {
        int k = key % _size;

        LinkedList<HashEntry<T>*> *l = ht[k];
        LLNode<HashEntry<T>*> *curr = l->head;

        while(curr) {
            HashEntry<T> *entry = curr->value;
            if(entry->key == key) {
                entry->value = value;
                return;
            }
            curr = curr->next;
        }

        l->insert(new HashEntry<T>(key, value));
    }

    bool contains(int key) {
        int k = key % _size;

        LinkedList<HashEntry<T*>> *l = ht[k];
        LLNode<HashEntry<T>*> *curr = l->head;
        
        while(curr) {
            HashEntry<T> *entry = curr->value;
            if(entry->key == key) {
                return true;
            }
            curr = curr->next;
        }

        return false;
    }

    string str() {
        stringstream ss;
        ss << "[" << endl;
        for(int i=0; i<_size; i++) {
            ss << "  " << i << " -> [";

            LinkedList<HashEntry<T>*> *l = ht[i];
            if(l->head == nullptr) {
                ss << "]" << endl;;
                continue;
            }

            LLNode<HashEntry<T>*> *curr = l->head;
            while(curr) {
                HashEntry<T> *entry = curr->value;
                ss << "(" << entry->key << "," << entry->value << ")";
                if(curr->next) {
                    ss << ", ";
                }
                curr = curr->next;
            }

            ss << "]" << endl;
        }
        ss << "]" << endl;
        return ss.str();
    }

    private:
    int _size = 10;
    LinkedList<HashEntry<T>*>* *ht;
};

#endif // define HPP