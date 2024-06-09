#ifndef BUSCABFS_H
#define BUSCABFS_H

template <typename T>
struct ListNode {
    NodeArvore<T>* iPayload;
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
ListNode<T>* createListNode(NodeArvore<T>*);

template <typename T>
void addElement(List<T>*, NodeArvore<T>*);

template <typename T>
NodeArvore<T>* deleteElement(List<T>*);

template <typename T>
NodeArvore<T>* bfs(NodeArvore<T>*, T);

#endif