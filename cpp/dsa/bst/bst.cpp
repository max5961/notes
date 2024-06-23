#include <iostream>
#include <queue>

template <typename T> class BST;

template <typename T> class Node {
    friend class BST<T>;
    T value;

  public:
    /* left and right are public only for the purposes of running simple tests
     * at the start of writing this implementation */
    Node<T> *left;
    Node<T> *right;
    Node(const T &value) :
        value(value),
        left(nullptr),
        right(nullptr) {
    }
    T getValue() {
        return value;
    }
};

template <typename T> class BST {
  public:
    /* root is public only for the purposes of running simple tests at the start
     * of writing this implementation */
    Node<T> *root;
    BST();
    ~BST();
    bool isEmpty() const;
    void insert(const T &value);
    void insert(Node<T> *&root, Node<T> *&node);
    bool search(const T &value) const;
    bool search(const Node<T> *const &root, const T &value) const;
    // read data -> visit left subtree -> visit right subtree
    void preOrderDfs() const;
    void preOrderDfs(const Node<T> *const &root) const;
    // visit left subtree -> read data -> visit right subtree
    void inOrderDfs() const;
    void inOrderDfs(const Node<T> *const &root) const;
    // visit left subtree -> visit right subtree -> read data
    void postOrderDfs() const;
    void postOrderDfs(const Node<T> *const &root) const;
    // breadth first search
    void levelOrderBfs() const;
    void reverse();
    void reverse(Node<T> *root);
    // min
    T min() const;
    T min(Node<T> *root) const;
    // max
    T max() const;
    T max(Node<T> *root) const;
    // delete
    void remove1(const T &value);
    void remove1(Node<T> *root, const T &value);
    void remove(const T &value);
    Node<T> *remove(Node<T> *root, const T &value);
};

template <typename T>
BST<T>::BST() :
    root(nullptr) {
}

template <typename T> BST<T>::~BST() {
    std::cout << "(destructor) freeing memory for: ";
    std::queue<Node<T> *> q;

    q.push(root);

    while (q.size()) {
        Node<T> *curr = q.front();
        q.pop();

        if (curr->left) {
            q.push(curr->left);
        }

        if (curr->right) {
            q.push(curr->right);
        }

        std::cout << curr->value << " ";
        delete curr;
    }

    std::cout << '\n';
}

template <typename T> bool BST<T>::isEmpty() const {
    return !root;
}

template <typename T> void BST<T>::insert(const T &value) {
    Node<T> *node = new Node<T>(value);

    if (isEmpty()) {
        root = node;
    } else {
        insert(root, node);
    }
}

template <typename T> void BST<T>::insert(Node<T> *&root, Node<T> *&node) {
    if (node->value < root->value) {
        if (!root->left) {
            root->left = node;
        } else {
            insert(root->left, node);
        }
    } else {
        if (!root->right) {
            root->right = node;
        } else {
            insert(root->right, node);
        }
    }
}

template <typename T> bool BST<T>::search(const T &value) const {
    return search(root, value);
}

template <typename T>
bool BST<T>::search(const Node<T> *const &root, const T &value) const {
    if (!root) {
        return false;
    }

    if (root->value == value) {
        return true;
    }

    if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

template <typename T> void BST<T>::preOrderDfs() const {
    preOrderDfs(root);
    std::cout << '\n';
}

template <typename T>
void BST<T>::preOrderDfs(const Node<T> *const &root) const {
    if (!root) {
        return;
    }

    std::cout << root->value << " ";
    preOrderDfs(root->left);
    preOrderDfs(root->right);
}

template <typename T> void BST<T>::inOrderDfs() const {
    inOrderDfs(root);
    std::cout << '\n';
}

template <typename T>
void BST<T>::inOrderDfs(const Node<T> *const &root) const {
    if (!root) {
        return;
    }

    inOrderDfs(root->left);
    std::cout << root->value << " ";
    inOrderDfs(root->right);
}

template <typename T> void BST<T>::postOrderDfs() const {
    postOrderDfs(root);
    std::cout << '\n';
}

template <typename T>
void BST<T>::postOrderDfs(const Node<T> *const &root) const {
    if (!root) {
        return;
    }

    postOrderDfs(root->left);
    postOrderDfs(root->right);
    std::cout << root->value << " ";
}

template <typename T> void BST<T>::levelOrderBfs() const {
    std::queue<Node<T> *> q;
    q.push(root);

    while (q.size()) {
        Node<T> *curr = q.front();
        q.pop();

        if (curr->left) {
            q.push(curr->left);
        }

        if (curr->right) {
            q.push(curr->right);
        }

        std::cout << curr->value << " ";
    }

    std::cout << '\n';
}

template <typename T> void BST<T>::reverse() {
    reverse(root);
}

template <typename T> void BST<T>::reverse(Node<T> *root) {
    if (!root) {
        return;
    }

    Node<T> *temp = root->left;
    root->left = root->right;
    root->right = temp;
    reverse(root->left);
    reverse(root->right);
}

template <typename T> T BST<T>::min() const {
    return min(root);
}

template <typename T> T BST<T>::min(Node<T> *root) const {
    if (!root->left) {
        return root->value;
    }

    return min(root->left);
}

template <typename T> T BST<T>::max() const {
    return max(root);
}

template <typename T> T BST<T>::max(Node<T> *root) const {
    if (!root->right) {
        return root->value;
    }

    return max(root->right);
}

template <typename T> void BST<T>::remove1(const T &value) {
    if (root->value == value) {
        Node<T> *tmp = root;
        if (!root->left && !root->right) {
            delete root;
            root = nullptr;
        } else if (!root->left) {
            root = root->right;
            delete tmp;
        } else if (!root->right) {
            root = root->left;
            delete tmp;
        } else {
            T newValue = min(root->right);
            remove1(root, newValue);
            root->value = newValue;
        }
    } else {
        remove1(root, value);
    }
}

template <typename T> void BST<T>::remove1(Node<T> *root, const T &value) {
    if (!root->left && !root->right) {
        return;
    }

    if (root->left && root->left->value == value) {
        Node<T> *child = root->left;
        if (!child->left && !child->right) {
            root->left = nullptr;
            delete child;
        } else if (!child->left) {
            root->left = child->right;
            delete child;
        } else if (!child->right) {
            root->left = child->left;
            delete child;
        } else {
            T newValue = min(child->right);
            remove1(child, newValue);
            child->value = newValue;
        }
    } else if (root->right && root->right->value == value) {
        Node<T> *child = root->right;
        if (!child->left && !child->right) {
            root->right = nullptr;
            delete child;
        } else if (!child->left) {
            root->right = child->right;
            delete child;
        } else if (!child->right) {
            root->right = child->left;
            delete child;
        } else {
            T newValue = min(child->right);
            remove1(child, newValue);
            child->value = newValue;
        }
    } else if (value > root->value) {
        remove1(root->right, value);
    } else {
        remove1(root->left, value);
    }
}

template <typename T> void BST<T>::remove(const T &value) {
    root = remove(root, value);
}

template <typename T> Node<T> *BST<T>::remove(Node<T> *root, const T &value) {
    if (!root) {
        return root;
    }

    if (value < root->value) {
        root->left = remove(root->left, value);
    } else if (value > root->value) {
        root->right = remove(root->right, value);
    } else {
        Node<T> *tmpLeft = root->left;
        Node<T> *tmpRight = root->right;
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        } else if (!root->left) {
            delete root;
            return tmpRight;
        } else if (!root->right) {
            delete root;
            return tmpLeft;
        } else {
            T newValue = min(root->right);
            root->right = remove(root->right, newValue);
            root->value = newValue;
        }
    }

    return root;
}

int main() {
    BST<int> *const bst = new BST<int>;
    bst->insert(10);
    bst->insert(5);
    bst->insert(15);
    bst->insert(12);
    bst->insert(17);
    bst->insert(3);
    bst->insert(7);
    bst->insert(6);
    bst->insert(8);
    bst->insert(2);
    bst->levelOrderBfs();
    bst->remove(10);
    bst->levelOrderBfs();

    delete bst;
    return 0;
}
