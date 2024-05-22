#include "DoublyLinkedList.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "RadixSort.h"

#include <iostream>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

int main()
{
    int arriTemposBubble[100] = {0};
    for (int i = 0;i<100;i++)
    {
        Node<int>* head = geradorListaAleatoria(10000, i);
        auto timeStart = high_resolution_clock::now();
        bubbleSort(head, 10000);
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        arriTempos[i] = timeDuration.count();
    }
    
    cout<<"Tempos bubbleSort: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTemposBubble[i]<<", ";
    }
    cout<<endl;
    
    int arriTemposBubbleOtimizado[100] = {0};
    for (int i = 0;i<100;i++)
    {
        Node<int>* head = geradorListaAleatoria(10000, i);
        auto timeStart = high_resolution_clock::now();
        optimizedBubbleSort(head, 10000);
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        arriTemposBubbleOtimizado[i] = timeDuration.count();
    }
    
    cout<<"Tempos optimizedBubbleSort: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTemposBubbleOtimizado[i]<<", ";
    }
    cout<<endl;

    int arriTemposSelection[100] = {0};
    for (int i = 0;i<100;i++)
    {
        Node<int>* head = geradorListaAleatoria(10000, i);
        auto timeStart = high_resolution_clock::now();
        selectionSort(head, 10000);
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        arriTemposSelection[i] = timeDuration.count();
    }
    
    cout<<"Tempos selectionSort: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTemposSelection[i]<<", ";
    }
    cout<<endl;
    
    int arriTemposSelectionOtimizado[100] = {0};
    for (int i = 0;i<100;i++)
    {
        Node<int>* head = geradorListaAleatoria(10000, i);
        auto timeStart = high_resolution_clock::now();
        optimizedSelectionSort(head, 10000);
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        arriTemposSelectionOtimizado[i] = timeDuration.count();
    }
    
    cout<<"Tempos optimizedSelectionSort: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTemposSelectionOtimizado[i]<<", ";
    }
    cout<<endl;


    int arriTemposInsertion[100] = {0};
    for (int i = 0;i<100;i++)
    {
        Node<int>* head = geradorListaAleatoria(10000, i);
        auto timeStart = high_resolution_clock::now();
        insertionSort(head, 10000);
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        arriTemposInsertion[i] = timeDuration.count();
    }
    
    cout<<"Tempos insertionSort: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTemposInsertion[i]<<", ";
    }
    cout<<endl;
    
    int arriTemposRadix[100] = {0};
    for (int i = 0;i<100;i++)
    {
        Node<int>* head = geradorListaAleatoria(10000, i);
        auto timeStart = high_resolution_clock::now();
        radixSort(head, 10000);
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        arriTemposRadix[i] = timeDuration.count();
    }
    
    cout<<"Tempos radixSort: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTemposRadix[i]<<", ";
    }
    cout<<endl;

    // Gerando uma lista aleatória para mostrar Radix
    Node<int>* head = geradorListaAleatoria(10, 12);
    
    // Vamos exibir a lista gerada
    cout << "=======================================================" << endl;
    cout << "Original: ";
    displayList(head);
    cout << "-------------------------------------------------------" << endl;

    // Testando as funções de adição e remoção de nós
    insertEnd(&head, 96);
    insertEnd(&head, 100);
    insertEnd(&head, 13);
    insertEnd(&head, 7);
    insertEnd(&head, 44);
    Node<int>* current = searchNodebyValue(&head, 13);
    deleteNode(&head, current);

    // Exibindo a lista após manipulação pelas funções
    cout << "Manipulada: "; 
    displayList(head);
    cout << "-------------------------------------------------------" << endl;

    // Aplicando o Sort, e mostrando a lista ordenada
    radixSort(&head);
    cout << "Resultado: ";
    displayList(head);
    cout << "=======================================================" << endl;

    return 0;
}
