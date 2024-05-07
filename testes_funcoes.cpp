#include <iostream>
#include <chrono>
#include <random>

using std::cin;
using std::cout;
using std::endl;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

using std::mt19937;

typedef struct Node{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrevious;
} Node;

Node* createNode(int);
void insertEnd(Node**, int);
void displayList(Node*);
void deleteNode(Node**, Node*);
Node* geradorListaAleatoria(int, int);

void swapValue(int&, int&);
void bubbleSort(Node*, int);
void optimizedBubbleSort(Node*, int);

int main()
{
    // gerando lista aleatório com 10 nós e seed 1
    Node* head = geradorListaAleatoria(10, 1);
    displayList(head);
    bubbleSort(head, 10);
    displayList(head);
    cout << "========================================================================" << endl;

    // gerando a mesma lista novamente, com a mesma semente
    Node* head2 = geradorListaAleatoria(10, 1);
    displayList(head2);
    optimizedBubbleSort(head2, 10);
    displayList(head2);
    cout << "========================================================================" << endl;
    
    //teste das funções BubbleSort, tempos no pdf
    //Node* head3 = geradorListaAleatoria(10000, 13);
    //Node* head3 = geradorListaAleatoria(10000, 632);
    //Node* head3 = geradorListaAleatoria(100000, 13);
    Node* head3 = geradorListaAleatoria(100000, 632);
    auto timeStart = high_resolution_clock::now();
    bubbleSort(head3, 100000);
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado bubbleSort: " << timeDuration.count() << " nano_segundos." << endl;
    cout << "=======================================================================" << endl;
    
    //gera as mesmas listas que acima
    //Node* head4 = geradorListaAleatoria(10000, 13);
    //Node* head4 = geradorListaAleatoria(10000, 632);
    //Node* head4 = geradorListaAleatoria(100000, 13);
    Node* head4 = geradorListaAleatoria(100000, 632);
    timeStart = high_resolution_clock::now();
    optimizedBubbleSort(head4,100000);
    timeStop = high_resolution_clock::now();
    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado optimizedBubbleSort: " << timeDuration.count() << " nano_segundos." << endl;
    cout << "=======================================================================" << endl;
    
    return 0;
}

Node* createNode(int iPayload)
{
    Node * temp = (Node*) malloc(sizeof(Node));
    temp->iPayload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrevious = nullptr;
    
    return temp;
}

void displayList(Node* node)
{
    if(node == nullptr)
    {
        cout << "Lista Vazia: Não é possível realizar displayList" << endl; 
        return;
    }
    if(node->ptrPrevious != nullptr)
    {
        cout << "Meio ou fim da Lista: Não é possível realizar displayList" << endl;
        return;
    }
    
    Node* temp = node;
    cout << "Payload: ";
    while (temp != nullptr)
    {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }
    cout << endl;
}

void insertEnd(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);
    
    if(*head == nullptr)
    {
        (*head) = newNode;
        return;
    }
    
    Node* temp = (*head);
    while(temp->ptrNext != nullptr) temp = temp->ptrNext;
    newNode->ptrPrevious = temp; 
    temp->ptrNext = newNode; 
}

void deleteNode(Node** head, Node* ptrDelete)
{
    if (*head == nullptr || ptrDelete == nullptr)
    {
        cout << "Não foi possível remover." << endl;
        return;
    }
    if(*head == ptrDelete) (*head) = ptrDelete->ptrNext;
    if(ptrDelete->ptrNext != nullptr) ptrDelete->ptrNext->ptrPrevious = ptrDelete->ptrPrevious;
    if(ptrDelete->ptrPrevious != nullptr) ptrDelete->ptrPrevious->ptrNext = ptrDelete->ptrNext;

    free(ptrDelete);
}

Node* geradorListaAleatoria(int iTam, int iSeed)
{
    mt19937 gen(iSeed);
    std::uniform_int_distribution<> dis(0, 100000);
    
    Node* head = nullptr;
    int iContador = 0;
    while(iContador<iTam)
    {
        int random_num = dis(gen);
        insertEnd(&head, random_num);
        iContador++;
    }
    return head;
}

void swapValue(Node* no1, Node* no2)
{
    //verifica se os nós fornecidos não são nulos e faz a troca
    if (no1 != nullptr && no2 != nullptr)
    {
        int iTemp = no1->iPayload;
        no1->iPayload = no2->iPayload;
        no2->iPayload = iTemp;
    }
}

void bubbleSort(Node* node, int iTam)
{
    //cria um nó temporário
    Node* tempNode = node;
    //verifica se o nó fornecido é o primeiro
    if(tempNode->ptrPrevious != nullptr)
    {
        cout << "Meio ou fim da Lista: Não é possível realizar bubbleSort" << endl;
        return;
    }
    
    //percorre a lista (iTam - 1) vezes
    for (int iOuterLoop = 0; iOuterLoop < (iTam - 1); iOuterLoop++)
    {
        //percorre a lista até o penultimo elemento
        for (int iInnerLoop = 0; iInnerLoop < (iTam - 1); iInnerLoop++)
        {
            //verifica o maior valor e faz a troca, se necessário
            if(tempNode->iPayload > tempNode->ptrNext->iPayload)
            {
                swapValue(tempNode, tempNode->ptrNext);
            }
            //atualiza o tempNode
            tempNode = tempNode->ptrNext;
        }
        //volta para o inicio da lista
        tempNode = node;
    }
}

void optimizedBubbleSort(Node* node, int iTam)
{
    //cria um nó temporário
    Node* tempNode = node;
    //verifica se o nó fornecido é o primeiro
    if(node->ptrPrevious != nullptr)
    {
        cout << "Meio ou fim da Lista: Não é possível realizar bubbleSort" << endl;
        return;
    }
    
    //inicializa um booleano para ver se a lista esta desordenada
    bool bUnordered = false;
    
    //percorre a lista (iTam - 1) vezes
    for (int iOuterLoop = 0; iOuterLoop < (iTam - 1); iOuterLoop++)
    {
        //diz que a lista esta desordenada
        bUnordered = false;
        //percorre a lista até o (penultimo - i) elemento
        for (int iInnerLoop = 0; iInnerLoop < (iTam - 1 - iOuterLoop); iInnerLoop++)
        {
            //verifica o maior valor e faz a troca, se necessário
            if(tempNode->iPayload > tempNode->ptrNext->iPayload)
            {
                swapValue(tempNode, tempNode->ptrNext);
                //atualizando o booleano
                bUnordered = true;
            }
            //atualiza o tempNode
            tempNode = tempNode->ptrNext;
        }
        //volta para o inicio da lista
        tempNode = node;
        //se a lista tiver ordenada, já sai da função
        if(bUnordered == false) break;
    }
}