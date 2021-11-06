#ifndef BST_HPP
#define BST_HPP

#include <sstream>

using namespace std;

template<class T>
struct BSTNode {
    T value;
    int height;
    BSTNode *parent;
    BSTNode *left;
    BSTNode *right;

    BSTNode(T v, int h)
    : value(v), height(h), parent(nullptr), left(nullptr), right(nullptr) {}

    ~BSTNode() {
        if(left) delete left;
        left = nullptr;
        if(right) delete right;
        right = nullptr;
    }
};

template<class T>
class BST {
    public:
    BSTNode<T> *root;

    BST() : root(nullptr), _size(0) {}
    ~BST() { 
        delete root;
        root = nullptr;
    }

    void insert(T value) {
        if(!root) {
            root = new BSTNode<T>(value, 0);
        }
        else {
            _insert(root, value, 0);
        }
    }

    bool contains(T value) {
        return _contains(root, value);
    }

    string preorder() {
        stringstream ss;
        _preorder(root, ss);
        return ss.str();
    }

    string inorder() {
        stringstream ss;
        _inorder(root, ss);
        return ss.str();
    }

    string postorder() {
        stringstream ss;
        _postorder(root, ss);
        return ss.str();
    }

    private:

    bool _contains(BSTNode<T> *n, T value) {
        if(!n) return false;
        if(n->value == value) return true;
        if(_contains(n->left)) return true;
        if(_contains(n->right)) return true;
        return false;
    }

    void _preorder(BSTNode<T> *n, stringstream &ss) {
        if(!n) return;

        ss << n->value << ", ";
        if(n->left) {
            _preorder(n->left, ss);
        }
        if(n->right) {
            _preorder(n->right, ss);
        }
    }

    void _inorder(BSTNode<T> *n, stringstream &ss) {
        if(!n) return;

        if(n->left) {
            _inorder(n->left, ss);
        }
        ss << n->value << ", ";
        if(n->right) {
            _inorder(n->right, ss);
        }
    }

    void _postorder(BSTNode<T> *n, stringstream &ss) {
        if(!n) return;

        if(n->left) {
            _postorder(n->left, ss);
        }
        if(n->right) {
            _postorder(n->right, ss);
        }
        ss << n->value << ", ";
    }

    void _insert(BSTNode<T> *n, T value, int height) {
        if(value <= n->value) {
            if(!n->left) {
                n->left = new BSTNode<T>(value, height+1);
                n->left->parent = n;
            }
            else {
                _insert(n->left, value, height+1);
            }
        }
        else {
            if(!n->right) {
                n->right = new BSTNode<T>(value, height+1);
                n->right->parent = n;
            }
            else {
                _insert(n->right, value, height+1);
            }
        }
    }

    private:
    int _size = 0;
};

#endif // define HPP
