#include <iostream>

template <typename T> class Node {
    T value;

  public:
    Node<T> *left;
    Node<T> *right;

    Node(T value) :
        value(value) {
        left = nullptr;
        right = nullptr;
    }

    T getValue() {
        return value;
    }
};

template <typename T> class BST {
  public:
    Node<T> *root;

    BST() {
        root = nullptr;
    }

    ~BST();

    void deallocateNodes(Node<T> *&root);

    void add(Node<T> *&root, T value);
    void add(const T &value);
};

template <typename T> BST<T>::~BST() {
    deallocateNodes(root);
}

template <typename T> void BST<T>::deallocateNodes(Node<T> *&root) {
    if (root) {
        if (!root->left && !root->right) {
            delete root;
        } else {
            if (root->left) {
                deallocateNodes(root->left);
            }
            if (root->right) {
                deallocateNodes(root->right);
            }
        }

        delete root;
    }
}

template <typename T> void BST<T>::add(Node<T> *&root, T value) {
    if (!root) {
        root = new Node<T>(value);
        return;
    }

    if (root->getValue() > value) {
        if (!root->left) {
            root->left = new Node<T>(value);
        } else {
            add(root->left, value);
        }
    } else {
        if (!root->right) {
            root->right = new Node<T>(value);
        } else {
            add(root->right, value);
        }
    }
}

template <typename T> void BST<T>::add(const T &value) {
    add(root, value);
}

int main() {

    BST<int> *bst = new BST<int>();
    bst->add(10);
    bst->add(5);
    bst->add(2);
    bst->add(7);
    bst->add(1);

    delete bst;

    return 0;
}
