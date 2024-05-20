#include <iostream>
#include <chrono>
#include <random>


using namespace std;

// Estrutura do Nó para listas duplamente encadeadas
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
void radixSort(Node**);

int main()
{
    // Gerando uma lista aleatória
    Node* head = geradorListaAleatoria(10, 12);
    
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
    Node* current = searchNodebyValue(&head, 13);
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

// Função para criar um nó a partir de um inteiro
Node* createNode(int iPayload)
{
    Node * temp = (Node*) malloc(sizeof(Node));
    temp->iPayload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrevious = nullptr;
    
    return temp;
}

// Função que exibe nossa lista
void displayList(Node* node)
{
    // Se a lista é vazia, ou não passamos o head, então não é possível exibi-la
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
    
    // Criando um nó temporário para exibir todos os valores da lista
    Node* temp = node;
    while (temp != nullptr)
    {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }
    cout << endl;
}

// Insere um nó com valor escolhido à uma lista
void insertEnd(Node** head, int iPayload)
{
    // Criando um nó
    Node* newNode = createNode(iPayload);
    
    // Se a fila é vazia, o head será o novo nó
    if(*head == nullptr)
    {
        (*head) = newNode;
        return;
    }

    // Criamos um nó temporário, atribuindo head, buscando o último para adicionar o novo nó ao fim da lista  
    Node* temp = (*head);
    while(temp->ptrNext != nullptr) temp = temp->ptrNext;
    newNode->ptrPrevious = temp; 
    temp->ptrNext = newNode; 
}

// Deleta um nó da lista
void deleteNode(Node** head, Node* ptrDelete)
{
    // Se a lista é vazia, ou não tem o nó escolhido, é impossível removê-lo
    if (*head == nullptr || ptrDelete == nullptr)
    {
        cout << "Não foi possível remover." << endl;
        return;
    }

    // Se o nó a ser deletado é head, então delete-o, e o próximo será o head
    if(*head == ptrDelete) (*head) = ptrDelete->ptrNext;

    // Se o nó não é o último, então conectamos os nós anterior e próximo
    if(ptrDelete->ptrNext != nullptr) ptrDelete->ptrNext->ptrPrevious = ptrDelete->ptrPrevious;

    // Se o nó não é o primeiro, então fazemos o mesmo.
    if(ptrDelete->ptrPrevious != nullptr) ptrDelete->ptrPrevious->ptrNext = ptrDelete->ptrNext;

    // Liberando a variável
    free(ptrDelete);
}

// Função geradora de uma lista aleatória, com tamanho e seed definidos pelo usuário
Node* geradorListaAleatoria(int iTam, int iSeed)
{
    // Gerando uma lista com números de 0 a 100, podendo incluí-los
    mt19937 gen(iSeed);
    std::uniform_int_distribution<> dis(0, 100);
    
    // Define o head, e adiciona ao fim da lista os nós com os valores gerados
    Node* head = nullptr;
    int iContador = 0;
    while(iContador<iTam)
    {
        int random_num = dis(gen);
        insertEnd(&head, random_num);
        iContador++;
    }

    // Retorna o head da lista
    return head;
}

// Buscar um nó por valor na lista, e nos devolve um nó
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

// Algoritmo para ordenar a lista, Radix Sort
void radixSort(Node** head) 
{
    // Se head é nulo, impossível ordenar
    if (*head == nullptr) return;
    
    // Calculamos o valor máximo de dígitos dos números da lista
    auto getMax = [](Node* head) -> int 
    {
        int iMax = head->iPayload;
        while (head->ptrNext != nullptr) 
        {
            if (head->iPayload > iMax)
                iMax = head->iPayload;
            head = head->ptrNext;
        }
        return iMax;
    };
    
    // Guardamos o valor da quantidade de dígitos
    int iMax = getMax(*head);
    
    // Vamos ordenar
    for (int exp = 1; iMax / exp > 0; exp *= 10)
    {
        Node* output = nullptr;
        Node* temp = *head;
        int count[10] = {0};

        // Contando as ocorrências dos dígitos
        while (temp->ptrNext != nullptr) 
        {
            count[(temp->iPayload / exp) % 10]++;
            temp = temp->ptrNext;
        }


        // Alterando "count[i]"" para que ele contenha as posições finais dos dígitos
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Aqui estamos ordenando a lista de fato
        for (int i = 0; i < 10; i++) 
        {
            Node* temp = *head;
            while (temp != nullptr) 
            {
                if ((temp->iPayload / exp) % 10 == i) 
                {
                    if (output == nullptr) 
                    {
                        Node* newNode = createNode(temp->iPayload);
                        output = newNode;
                    } 
                    else 
                    {
                        insertEnd(&output, temp->iPayload);
                    }
                }
                temp = temp->ptrNext;
            }
        }

        // Exibe a ordenação por passos, caso não queira basta tornar as linhas 244 a 246 comentários.
        cout << "Ordenando: ";
        displayList(output);
        cout << "-------------------------------------------------------" << endl;
        *head = output;
    }
}
