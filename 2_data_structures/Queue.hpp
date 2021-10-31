#ifndef QUEUE_HPP
#define QUEUE_HPP
#endif

#include <vector>

using namespace std;

template<class T>
class Queue {
    public:
    Queue() {}
    ~Queue() {}

    void enqueue(T x) {
        q.push_back(x);
    }

    void dequeue() {
        int n = q.size();
        if(h < n) {
            h++;
        }
        else throw out_of_range("Cannot dequeue on an empty queue.");
    }

    T head() {
        if(begin() < end()) {
            return q[h];
        }
        else throw out_of_range("Cannot retrieve head from an empty queue.");
    }

    T tail() {
        if(begin() < end()) {
            return q[end()-1];
        }
        else throw out_of_range("Cannot retrieve tail from an empty queue.");
    }

    int begin() {
        return h;
    }
    
    int end() {
        return q.size();
    }

    string str() {
        stringstream ss;
        ss << "[";
        try {
            for(int i=begin(); i<end()-1; i++) {
                ss << q[i] << ", ";
            }
            ss << tail() << "]";
            return ss.str();
        }
        catch(out_of_range e) {
            return "[]";
        }
    }

    private:
    vector<T> q;
    int h = 0;
};
