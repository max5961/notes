#include <iostream>

template <typename T> class LinkedList;

template <typename T> class Node {
    friend class LinkedList<T>;
    T value;
    Node<T> *next;

  public:
    Node(const T value);
    T getValue() const;
};

template <typename T>
Node<T>::Node(const T value) :
    value(value),
    next(nullptr) {
}

template <typename T> T Node<T>::getValue() const {
    return value;
}

template <typename T> class LinkedList {
    int size;
    Node<T> *head;

  public:
    LinkedList();
    ~LinkedList();
    bool isEmpty() const;
    int getSize() const;
    void print() const;
    void prepend(const T &value);
    void append(const T &value);
    void insert(const T &value, const int index);
    void removeFrom(const int index);
    void removeValue(const T &value);
    int search(const T &value);
    void reverse();
};

template <typename T>
LinkedList<T>::LinkedList() :
    head(nullptr),
    size(0) {
}

template <typename T> LinkedList<T>::~LinkedList() {
    Node<T> *curr = head;
    Node<T> *next = head;

    std::cout << "\nCalling Destructor...\n";
    while (curr) {
        next = curr->next;
        std::cout << "Deleting: " << curr->value << '\n';
        delete curr;
        curr = next;
    }
}

template <typename T> bool LinkedList<T>::isEmpty() const {
    return size == 0;
}

template <typename T> int LinkedList<T>::getSize() const {
    return size;
}

template <typename T> void LinkedList<T>::print() const {
    if (isEmpty()) {
        std::cout << "List is empty." << '\n';
        return;
    }
    Node<T> *curr = head;
    while (curr) {
        std::cout << curr->value << " ";
        curr = curr->next;
    }
    std::cout << '\n';
}

template <typename T> void LinkedList<T>::prepend(const T &value) {
    Node<T> *const node = new Node<T>(value);

    if (!isEmpty()) {
        Node<T> *next = head;
        node->next = next;
    }

    head = node;

    ++size;
}

template <typename T> void LinkedList<T>::append(const T &value) {
    if (isEmpty()) {
        prepend(value);
        return;
    }

    Node<T> *curr = head;
    Node<T> *prev = head;

    while (curr) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = new Node<T>(value);

    ++size;
}

template <typename T>
void LinkedList<T>::insert(const T &value, const int index) {
    if (index < 0 || index > getSize() + 1) {
        std::cout << "Invalid index" << '\n';
        return;
    }

    if (index == 0) {
        prepend(value);
        return;
    }

    Node<T> *curr = head;
    Node<T> *prev = head;
    for (int i = 0; i < index; ++i) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = new Node<T>(value);
    prev->next->next = curr;

    ++size;
}

template <typename T> void LinkedList<T>::removeFrom(const int index) {
    if (index < 0 || index > getSize()) {
        std::cout << "Invalid index" << '\n';
        return;
    }

    Node<T> *curr = head;
    Node<T> *prev = head;
    for (int i = 0; i < index; ++i) {
        prev = curr;
        curr = curr->next;
    }
    Node<T> *next = curr->next;
    delete curr;

    if (index == 0) {
        head = next;
    } else {
        prev->next = next;
    }

    --size;
}

template <typename T> void LinkedList<T>::removeValue(const T &value) {
    if (head && head->value == value) {
        removeFrom(0);
        return;
    }

    Node<T> *curr = head;
    Node<T> *prev = head;

    while (curr) {
        if (curr->value == value) {
            prev->next = curr->next;
            delete curr;
            return;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    std::cout << "value: '" << value << "' does not exist in Linked List\n";
}

template <typename T> int LinkedList<T>::search(const T &value) {
    Node<T> *curr = head;
    Node<T> *prev = head;

    int index = 0;
    while (curr) {
        if (curr->value == value) {
            return index;
        }

        prev = curr;
        curr = curr->next;
        ++index;
    }

    return -1;
}

template <typename T> void LinkedList<T>::reverse() {
    Node<T> *curr = head;
    Node<T> *prev = nullptr;

    while (curr) {
        Node<T> *oldNext = curr->next;
        curr->next = prev;
        prev = curr;
        curr = oldNext;
    }

    head = prev;
}

int main() {
    LinkedList<int> *ll = new LinkedList<int>;

    ll->append(5);
    ll->append(10);
    ll->append(15);
    ll->insert(7, 3);
    ll->print();
    ll->reverse();
    ll->print();
    std::cout << ll->search(5) << '\n';

    delete ll;

    return 0;
}
