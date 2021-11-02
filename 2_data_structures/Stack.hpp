#ifndef STACK_HPP
#define STACK_HPP

#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;

template<class T>
class Stack {
    public:
    Stack() {}

    void push(T x) {
        s.push_back(x);
    }

    void pop() {
        if(size() > 0) {
            s.pop_back();
        }
        else throw out_of_range("Cannot pop an empty stack.");
    }

    T top() {
        if(size() > 0) {
            return s[size()-1];
        }
        else throw out_of_range("Cannot top an empty stack.");
    }

    int size() {
        return s.size();
    }

    string str() {
        int n = size();
        if(n > 0) {
            stringstream ss;
            ss << "[";
            for(int i=n-1; i>=1; i--) {
                ss << s[i] << ", ";
            }
            ss << s[0] << "]";
            return ss.str();
        }
        return "[]";
    }

    private:
    vector<T> s;
};

#endif // define HPP
