#ifndef ARVORE_H
#define ARVORE_H

template <typename T>

struct NodeArvore{
  T iPayload;
  
  NodeArvore<T>* ptrLeft;
  NodeArvore<T>* ptrRight;

};

#include "Arvore.tplt"

template <typename T>
NodeArvore<T>* newNode(T);

template <typename T>
NodeArvore<T>* insertNode(NodeArvore<T>*, T);

template <typename T>
NodeArvore<T>* lesserLeaf(NodeArvore<T>*);

template <typename T>
NodeArvore<T>* deleteNode(NodeArvore<T>*, T);

template <typename T>
void traversePreOrder(NodeArvore<T>*);

template <typename T>
void traverseInOrder(NodeArvore<T>*);

template <typename T>
void traversePostOrder(NodeArvore<T>*);

template <typename T>
NodeArvore<T>* geradorArvoreAleatoria(int, int);

#endif