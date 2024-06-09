#ifndef BUSCABFS_H
#define BUSCABFS_H

template <typename T>
struct Node{
    T iPayload;
    Node<T>* ptrNext;
    Node<T>* ptrPrevious;
};

template <typename T>
struct ListNode {
    Node<T>* iPayload;
    ListNode<T>* next;
};

template <typename T>
struct List {
    ListNode<T>* front;
    ListNode<T>* rear;
};

#include "BuscaBFS.tplt"

template <typename T>
List<T>* initializeList();

template <typename T>
ListNode<T>* createListNode(Node<T>*);

template <typename T>
void addElement(List<T>* list, Node<T>* node);

template <typename T>
Node<T>* deleteElement(List<T>* list);

template <typename T>
Node<T>* bfs(Node<T>*, int);

#endif