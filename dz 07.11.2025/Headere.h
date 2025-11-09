#pragma once

#include <iostream>
using namespace std;

// шаблонний клас вузла
template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

// шаблонний клас однозв'язного списку
template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void AddToHead(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    void AddToTail(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void DeleteFromHead() {
        if (!head) return;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void DeleteFromTail() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node<T>* temp = head;
        while (temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void DeleteAll() {
        while (head)
            DeleteFromHead();
    }

    void Show() {
        Node<T>* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~SinglyLinkedList() {
        DeleteAll();
    }
};
