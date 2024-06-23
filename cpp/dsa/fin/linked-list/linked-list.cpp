#include <iostream>

template <typename T> class Node {
    T value;

  public:
    Node<T> *next = nullptr;
    Node<T>(T value) :
        value(value) {
    }
    T getValue() {
        return value;
    }
};

template <typename T> class LinkedList {
    int size;
    Node<T> *head;

  public:
    // constructor
    LinkedList() {
        size = 0;
        head = nullptr;
    }

    // destructor
    ~LinkedList() {
        Node<T> *curr = head;
        while (curr) {
            Node<T> *next = curr->next;
            delete curr;
            curr = next;
        }
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void printList() const {
        if (isEmpty()) {
            std::cout << "List is empty!\n";
            return;
        }

        std::cout << "List Items: ";

        Node<T> *curr = head;
        while (curr) {
            std::cout << curr->getValue() << ", ";
            curr = curr->next;
        }

        std::cout << '\n';
    }

    int search(T value) const {
        Node<T> *curr = head;

        int i = 0;
        while (curr) {
            if (curr->getValue() == value) {
                return i;
            }
            curr = curr->next;
            ++i;
        }

        return -1;
    }

    void prepend(T value) {
        Node<T> *prevHead = head;
        head = new Node<T>(value);
        head->next = prevHead;

        ++size;
    }

    void append(T value) {

        if (isEmpty()) {
            head = new Node<T>(value);
        } else {
            Node<T> *curr = head;

            while (curr->next) {
                curr = curr->next;
            }

            curr->next = new Node<T>(value);
        }

        ++size;
    }

    void insert(int index, T value) {
        if (index < 0 || index >= size) {
            return;
        }

        if (index == 0) {
            prepend(value);
        } else {
            Node<T> *curr = head;
            Node<T> *prev = head;

            for (int i = 0; i < index; i++) {
                prev = curr;
                curr = curr->next;
            }

            prev->next = new Node<T>(value);
            prev->next->next = curr;

            ++size;
        }
    }

    void removeFrom(int index) {
        if (index < 0 || index >= size) {
            return;
        }

        if (index == 0) {
            Node<T> *next = head->next;
            delete head;
            head = next;
        } else {
            Node<T> *curr = head;
            Node<T> *prev = head;

            for (int i = 0; i < index; i++) {
                prev = curr;
                curr = curr->next;
            }

            Node<T> *next = curr->next;
            delete curr;
            prev->next = next;
        }

        --size;
    }
    void removeValue(T value) {
        if (head->getValue() == value) {
            removeFrom(0);
            return;
        }

        Node<T> *curr = head;
        Node<T> *prev = head;

        while (curr) {
            if (curr->getValue() == value) {
                Node<T> *next = curr->next;
                prev->next = next;
                delete curr;
                --size;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        std::cout << "That value doesn't exist in the list!" << '\n';
    }

    void reverse() {
        Node<T> *prev = nullptr;
        Node<T> *curr = head;

        while (curr) {
            // 1. create next pointer and pointer it at curr->next
            Node<T> *next = curr->next;

            // 2. point current->next to prev
            // This is arguably the most important part in the process
            // This is where the direction of the list actually reverses
            curr->next = prev;

            // 3. point prev to curr
            prev = curr;

            // 4. point curr to next (curr->next)
            curr = next;
        }

        // 5. At this point, curr points to null, so the last
        // element in the reversed list is prev and it will
        // become the new head
        head = prev;
    }
};

int main() {

    LinkedList<std::string> *const list = new LinkedList<std::string>;

    list->append("Mouse");
    list->append("Light");
    list->append("Speaker");
    list->append("Plant");
    list->append("Keys");
    list->printList();
    list->reverse();
    list->printList();

    delete list;

    return 0;
}
