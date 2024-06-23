#include <iostream>

template <typename T> class Node {
    T value;

  public:
    Node *next;

    Node(T value) :
        value(value) {
        next = nullptr;
    }

    T getValue() {
        return value;
    }
};

template <typename T> class LinkedList {
    int size;
    Node<T> *head;
    Node<T> *tail;

  public:
    LinkedList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void printList() const {
        if (isEmpty()) {
            std::cout << "List is empty\n";
        } else {
            std::cout << "List Items: ";

            Node<T> *curr = head;
            while (curr) {
                std::cout << curr->getValue() << ", ";
                curr = curr->next;
            }

            std::cout << '\n';
        }
    }

    void prepend(T value) {
        if (isEmpty()) {
            head = new Node<T>(value);
            tail = head;
        } else {
            Node<T> *next = head;
            head = new Node<T>(value);
            head->next = next;
        }

        ++size;
    }

    // constant time complexity which is an improvement from
    // linear time complexity in a regular Linked List for
    // this same operation
    void append(T value) {
        if (isEmpty()) {
            tail = new Node<T>(value);
            head = tail;
        } else {
            Node<T> *prevTail = tail;
            tail = new Node<T>(value);
            prevTail->next = tail;
        }

        ++size;
    }

    void removeFromFront() {
        if (!isEmpty()) {
            Node<T> *nextHead = head->next;
            delete head;
            head = nextHead;
            --size;
        }
    }

    // Linked List with a tail still does not permit constant time
    // complexity to remove from End (need a doubly linked list for
    // this)
    void removeFromEnd() {
        if (isEmpty()) {
            return;
        }

        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node<T> *curr = head;
            Node<T> *prev = head;

            while (curr->next) {
                prev = curr;
                curr = curr->next;
            }

            prev->next = nullptr;
            tail = prev;
            delete curr;
        }
        --size;
    }
};

int main() {

    LinkedList<int> *list = new LinkedList<int>;
    list->append(1);
    list->removeFromEnd();
    list->prepend(5);
    list->append(10);
    list->append(15);
    list->append(20);
    list->removeFromEnd();
    list->removeFromFront();
    list->printList();

    return 0;
}
