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
Node* searchNodebyValue(Node**, int);

void swapValue(int&, int&);
void selectionSort(Node*);
void optimizedSelectionSort(Node*);

int main()
{
    int arriTempos[100] = {0};
    for (int i = 0;i<100;i++)
    {
        Node* head = geradorListaAleatoria(10000, i);
        auto timeStart = high_resolution_clock::now();
        selectionSort(head);
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        arriTempos[i] = timeDuration.count();
    }
    
    cout<<"Tempos selectionSort: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTempos[i]<<", ";
    }
    cout<<endl;
    
    int arriTemposOtimizado[100] = {0};
    for (int i = 0;i<100;i++)
    {
        Node* head = geradorListaAleatoria(10000, i);
        auto timeStart = high_resolution_clock::now();
        optimizedSelectionSort(head);
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        arriTempos[i] = timeDuration.count();
    }
    
    cout<<"Tempos optimizedSelectionSort: ";
    for (int i = 0;i<100;i++)
    {
        cout<< arriTempos[i]<<", ";
    }
    cout<<endl;
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

Node* searchNodebyValue(Node** head, int iValue)
{
    // Verifica se a fila é vazia
    if (*head == nullptr)
    {
        cout << "Fila vazia, não foi possível achar o nó." << endl;
        return nullptr;
    }
    // Percorre a lista até encontrar o nó procurado ou chegar ao fim da fila
    Node* current = *head;
    while (current != nullptr && current->iPayload != iValue) current = current->ptrNext;
    // Verifica se não achou o nó na fila
    if (current == nullptr)
    {
        cout << "Não foi possível achar o nó de valor " << iValue << "." << endl;
        return nullptr;
    }
    // Se já foi encontrado apenas o retorna
    return current;
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

void selectionSort(Node* firstNode)
{
    //verifica se o nó fornecido é o primeiro
    if(firstNode->ptrPrevious != nullptr)
    {
        cout << "Meio ou fim da Lista: Não é possível realizar selectionSort" << endl;
        return;
    }
    
    //cria um nó temporário
    Node* tempNode = firstNode;
    //percorre a lista até o último nó
    while (tempNode->ptrNext != nullptr)
    {
        //cria um novo nó para percorrer a lista
        Node* currentNode = tempNode->ptrNext;
        while (currentNode != nullptr)
        {
            if (tempNode->iPayload > currentNode->iPayload)
            {
                swapValue(tempNode, currentNode);
            }
            //atualiza o nó que percorre a lista
            currentNode = currentNode->ptrNext;
        }
        //atualiza o nó do loop de fora
        tempNode = tempNode->ptrNext;
    }
}

void optimizedSelectionSort(Node* firstNode)
{
    //verifica se o nó fornecido é o primeiro
    if(firstNode->ptrPrevious != nullptr)
    {
        cout << "Meio ou fim da Lista: Não é possível realizar optimazedSelectionSort" << endl;
        return;
    }
    
    //cria um nó temporário
    Node* tempNode = firstNode;
    //percorre a lista até o último nó
    while (tempNode->ptrNext != nullptr)
    {
        //inicializa o nó que vai trocar
        Node* swapNode = tempNode;
        //cria um novo nó para percorrer a lista
        Node* currentNode = tempNode->ptrNext;
        while (currentNode != nullptr)
        {
            if (swapNode->iPayload > currentNode->iPayload)
            {
                //atualiza o nó que vai trocar para ser o menor
                swapNode = currentNode;
            }
            //atualiza o nó que percorre a lista
            currentNode = currentNode->ptrNext;
        }
        swapValue(tempNode, swapNode);
        //atualiza o nó do loop de fora
        tempNode = tempNode->ptrNext;
    }
}