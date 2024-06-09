#include "DoublyLinkedList.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "RadixSort.h"
#include "Arvore.h"
#include "BuscaDFS.h"
#include "BuscaBFS.h"

#include <iostream>
#include <chrono>

using namespace std;

int main()
{
    int arriTemposBubble[100] = {0};
    int arriTemposListaBubble[100] = {0};
    for (int i = 0;i<100;i++)
    {
        auto timeStartLista = chrono::high_resolution_clock::now();
        Node<int>* head = geradorListaAleatoria<int>(10000, i);
        auto timeStopLista = chrono::high_resolution_clock::now();
        auto timeDurationLista = chrono::duration_cast<chrono::nanoseconds>(timeStopLista - timeStartLista);
        arriTemposListaBubble[i] = timeDurationLista.count();
        auto timeStart = chrono::high_resolution_clock::now();
        bubbleSort(head, 10000);
        auto timeStop = chrono::high_resolution_clock::now();
        auto timeDuration = chrono::duration_cast<chrono::nanoseconds>(timeStop - timeStart);
        arriTemposBubble[i] = timeDuration.count();
    }
    
    cout<<"Tempos bubbleSort: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTemposBubble[i]<<", ";
    }
    cout<<endl;

    cout<<"Tempos gerar Lista bubbleSort: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTemposListaBubble[i]<<", ";
    }
    cout<<endl;
    
    int arriTemposBubbleOtimizado[100] = {0};
    int arriTemposListaBubbleOtimizado[100] = {0};
    for (int i = 0;i<100;i++)
    {
        auto timeStartLista = chrono::high_resolution_clock::now();
        Node<int>* head = geradorListaAleatoria<int>(10000, i);
        auto timeStopLista = chrono::high_resolution_clock::now();
        auto timeDurationLista = chrono::duration_cast<chrono::nanoseconds>(timeStopLista - timeStartLista);
        arriTemposListaBubbleOtimizado[i] = timeDurationLista.count();
        auto timeStart = chrono::high_resolution_clock::now();
        optimizedBubbleSort(head, 10000);
        auto timeStop = chrono::high_resolution_clock::now();
        auto timeDuration = chrono::duration_cast<chrono::nanoseconds>(timeStop - timeStart);
        arriTemposBubbleOtimizado[i] = timeDuration.count();
    }
    
    cout<<"Tempos optimizedBubbleSort: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTemposBubbleOtimizado[i]<<", ";
    }
    cout<<endl;

    cout<<"Tempos gerar Lista optimizedBubbleSort: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTemposListaBubbleOtimizado[i]<<", ";
    }
    cout<<endl;

    int arriTemposSelection[100] = {0};
    int arriTemposListaSelection[100] = {0};
    for (int i = 0;i<100;i++)
    {
        auto timeStartLista = chrono::high_resolution_clock::now();
        Node<int>* head = geradorListaAleatoria<int>(10000, i);
        auto timeStopLista = chrono::high_resolution_clock::now();
        auto timeDurationLista = chrono::duration_cast<chrono::nanoseconds>(timeStopLista - timeStartLista);
        arriTemposListaSelection[i] = timeDurationLista.count();
        auto timeStart = chrono::high_resolution_clock::now();
        selectionSort(head);
        auto timeStop = chrono::high_resolution_clock::now();
        auto timeDuration = chrono::duration_cast<chrono::nanoseconds>(timeStop - timeStart);
        arriTemposSelection[i] = timeDuration.count();
    }
    
    cout<<"Tempos selectionSort: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTemposSelection[i]<<", ";
    }
    cout<<endl;

    cout<<"Tempos gerar Lista selectionSort: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTemposListaSelection[i]<<", ";
    }
    cout<<endl;
    
    int arriTemposSelectionOtimizado[100] = {0};
    int arriTemposListaSelectionOtimizado[100] = {0};
    for (int i = 0;i<100;i++)
    {
        auto timeStartLista = chrono::high_resolution_clock::now();
        Node<int>* head = geradorListaAleatoria<int>(10000, i);
        auto timeStopLista = chrono::high_resolution_clock::now();
        auto timeDurationLista = chrono::duration_cast<chrono::nanoseconds>(timeStopLista - timeStartLista);
        arriTemposListaSelectionOtimizado[i] = timeDurationLista.count();
        auto timeStart = chrono::high_resolution_clock::now();
        optimizedSelectionSort(head);
        auto timeStop = chrono::high_resolution_clock::now();
        auto timeDuration = chrono::duration_cast<chrono::nanoseconds>(timeStop - timeStart);
        arriTemposSelectionOtimizado[i] = timeDuration.count();
    }
    
    cout<<"Tempos optimizedSelectionSort: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTemposSelectionOtimizado[i]<<", ";
    }
    cout<<endl;

    cout<<"Tempos gerar Lista optimizedSelectionSort: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTemposListaSelectionOtimizado[i]<<", ";
    }
    cout<<endl;

    int arriTemposInsertion[100] = {0};
    int arriTemposListaInsertion[100] = {0};
    for (int i = 0;i<100;i++)
    {
        auto timeStartLista = chrono::high_resolution_clock::now();
        Node<int>* head = geradorListaAleatoria<int>(10000, i);
        auto timeStopLista = chrono::high_resolution_clock::now();
        auto timeDurationLista = chrono::duration_cast<chrono::nanoseconds>(timeStopLista - timeStartLista);
        arriTemposListaInsertion[i] = timeDurationLista.count();
        auto timeStart = chrono::high_resolution_clock::now();
        insertionSort(head, 10000);
        auto timeStop = chrono::high_resolution_clock::now();
        auto timeDuration = chrono::duration_cast<chrono::nanoseconds>(timeStop - timeStart);
        arriTemposInsertion[i] = timeDuration.count();
    }
    
    cout<<"Tempos insertionSort: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTemposInsertion[i]<<", ";
    }
    cout<<endl;

    cout<<"Tempos gerar Lista insertionSort: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTemposListaInsertion[i]<<", ";
    }
    cout<<endl;
    
    int arriTemposRadix[100] = {0};
    int arriTemposListaRadix[100] = {0};
    for (int i = 0;i<100;i++)
    {
        auto timeStartLista = chrono::high_resolution_clock::now();
        Node<int>* head = geradorListaAleatoria<int>(10000, i);
        auto timeStopLista = chrono::high_resolution_clock::now();
        auto timeDurationLista = chrono::duration_cast<chrono::nanoseconds>(timeStopLista - timeStartLista);
        arriTemposListaRadix[i] = timeDurationLista.count();
        auto timeStart = chrono::high_resolution_clock::now();
        radixSort(&head);
        auto timeStop = chrono::high_resolution_clock::now();
        auto timeDuration = chrono::duration_cast<chrono::nanoseconds>(timeStop - timeStart);
        arriTemposRadix[i] = timeDuration.count();
    }
    
    cout<<"Tempos radixSort: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTemposRadix[i]<<", ";
    }
    cout<<endl;

    cout<<"Tempos gerar Lista radixSort: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTemposListaRadix[i]<<", ";
    }
    cout<<endl;

    int arriTemposBuscaDFS[100] = {0};
    int arriTemposArvoreDFS[100] = {0};
    for (int i = 0;i<100;i++)
    {
        auto timeStartArvore = chrono::high_resolution_clock::now();
        NodeArvore<int>* root = geradorArvoreAleatoria<int>(10000, i);
        auto timeStopArvore = chrono::high_resolution_clock::now();
        auto timeDurationArvore = chrono::duration_cast<chrono::nanoseconds>(timeStopArvore - timeStartArvore);
        arriTemposArvoreDFS[i] = timeDurationArvore.count();
        auto timeStart = chrono::high_resolution_clock::now();
        NodeArvore<int>* noEncontrado = searchNode<int>(root, 0);
        auto timeStop = chrono::high_resolution_clock::now();
        auto timeDuration = chrono::duration_cast<chrono::nanoseconds>(timeStop - timeStart);
        arriTemposBuscaDFS[i] = timeDuration.count();
        free(root);
    }
    
    cout<<"Tempos BuscaDFS: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTemposBuscaDFS[i]<<", ";
    }
    cout<<endl;

    cout<<"Tempos gerar Arvore DFS: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTemposArvoreDFS[i]<<", ";
    }
    cout<<endl;

    int arriTemposBuscaBFS[100] = {0};
    int arriTemposArvoreBFS[100] = {0};
    for (int i = 0;i<100;i++)
    {
        auto timeStartArvore = chrono::high_resolution_clock::now();
        NodeArvore<int>* root = geradorArvoreAleatoria<int>(10000, i);
        auto timeStopArvore = chrono::high_resolution_clock::now();
        auto timeDurationArvore = chrono::duration_cast<chrono::nanoseconds>(timeStopArvore - timeStartArvore);
        arriTemposArvoreBFS[i] = timeDurationArvore.count();
        auto timeStart = chrono::high_resolution_clock::now();
        NodeArvore<int>* noEncontrado = bfs<int>(root, i);
        auto timeStop = chrono::high_resolution_clock::now();
        auto timeDuration = chrono::duration_cast<chrono::nanoseconds>(timeStop - timeStart);
        arriTemposBuscaBFS[i] = timeDuration.count();
    }
   
    cout<<"Tempos BuscaBFS: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTemposBuscaBFS[i]<<", ";
    }
    cout<<endl;

    cout<<"Tempos gerar Arvore BFS: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTemposArvoreBFS[i]<<", ";
    }
    cout<<endl;

    // // Gerando uma lista aleatória para mostrar Radix
    // Node<int>* head = geradorListaAleatoria(10, 12);
    
    // // Vamos exibir a lista gerada
    // cout << "=======================================================" << endl;
    // cout << "Original: ";
    // displayList(head);
    // cout << "-------------------------------------------------------" << endl;

    // // Testando as funções de adição e remoção de nós
    // insertEnd(&head, 96);
    // insertEnd(&head, 100);
    // insertEnd(&head, 13);
    // insertEnd(&head, 7);
    // insertEnd(&head, 44);
    // Node<int>* current = searchNodebyValue(&head, 13);
    // deleteNode(&head, current);

    // // Exibindo a lista após manipulação pelas funções
    // cout << "Manipulada: "; 
    // displayList(head);
    // cout << "-------------------------------------------------------" << endl;

    // // Aplicando o Sort, e mostrando a lista ordenada
    // radixSort(&head);
    // cout << "Resultado: ";
    // displayList(head);
    // cout << "=======================================================" << endl;

    return 0;
}
