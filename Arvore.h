#ifndef ARVORE_H
#define ARVORE_H

template <typename T>

struct Node
{
  T iPayload;
  
  Node<T>* ptrLeft;
  Node<T>* ptrRight;

};

#include "Arvore.tplt"

template <typename T>
Node<T>* newNode(T);

template <typename T>
Node<T>* insertNode(Node<T>*, T);

template <typename T>
Node<T>* lesserLeaf(Node<T>*);

template <typename T>
Node<T>* deleteNode(Node<T>*, T);

template <typename T>
void traversePreOrder(Node<T>*);

template <typename T>
void traverseInOrder(Node<T>*);

template <typename T>
void traversePostOrder(Node<T>*);

template <typename T>
Node<T>* geradorArvoreAleatoria(int, int);

#endif