#ifndef NODE_H
#define NODE_H

template <typename T>

struct Node{
    T iPayload;
    Node<T>* ptrNext;
    Node<T>* ptrPrevious;
};

#include "DoublyLinkedList.tplt"

template <typename T>
Node<T>* createNode(T);

template <typename T>
void insertEnd(Node<T>**, T);

template <typename T>
void displayList(Node<T>*);

template <typename T>
void deleteNode(Node<T>**, Node<T>*);

template <typename T>
Node<T>* geradorListaAleatoria(int, int);

template <typename T>
Node<T>* searchNodebyValue(Node<T>**, T);

template <typename T>
void swapValue(Node<T>*, Node<T>*);

#endif