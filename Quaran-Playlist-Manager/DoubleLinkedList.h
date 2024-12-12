#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>


template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoubleLinkedList() {
        clear();
    }

    DoubleLinkedList(const DoubleLinkedList& other) : head(nullptr), tail(nullptr) {
        Node<T>* current = other.head;
        while (current) {
            append(current->data);
            current = current->next;
        }
    }

    DoubleLinkedList& operator=(const DoubleLinkedList& other) {
        if (this != &other) {
            clear();
            Node<T>* current = other.head;
            while (current) {
                append(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    void setHead(Node<T>* newHead) {
        head = newHead;
    }

    void setTail(Node<T>* newTail) {
        tail = newTail;
    }


    Node<T>* getHead() const {
        return head;
    }
    Node<T>* getTail() const {
        return tail;
    }

    void append(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }


    void addToBeginning(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void remove(Node<T>* nodeToRemove) {
        if (!nodeToRemove) return;

        if (nodeToRemove->prev) nodeToRemove->prev->next = nodeToRemove->next;
        if (nodeToRemove->next) nodeToRemove->next->prev = nodeToRemove->prev;

        if (nodeToRemove == head) head = nodeToRemove->next;
        if (nodeToRemove == tail) tail = nodeToRemove->prev;

        delete nodeToRemove;
    }


    void removeAtIndex(int index) {
        if (index < 0 || isEmpty()) {
            std::cerr << "Invalid index or list is empty.\n";
            return;
        }

        Node<T>* current = head;
        int currentIndex = 0;

        while (current && currentIndex != index) {
            current = current->next;
            currentIndex++;
        }

        if (current) {
            if (current->prev) current->prev->next = current->next;
            if (current->next) current->next->prev = current->prev;
            if (current == head) head = current->next;
            if (current == tail) tail = current->prev;

            delete current;
        }
        else {
            std::cerr << "Index out of bounds.\n";
        }
    }


    void removeFirst() {
        if (isEmpty()) {
            std::cerr << "List is empty.\n";
            return;
        }
        Node<T>* toDelete = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete toDelete;
    }

    void removeLast() {
        if (isEmpty()) {
            std::cerr << "List is empty.\n";
            return;
        }
        Node<T>* toDelete = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete toDelete;
    }


    int search(T value) const {
        Node<T>* current = head;
        int index = 0;

        while (current) {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }

    void display() const {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }


    void clear() {
        Node<T>* current = head;
        while (current) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
    }


    bool isEmpty() const {
        return head == nullptr;
    }


    int size() const {
        int count = 0;
        Node<T>* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

};

#endif

