#include <iostream>
using namespace  std;

struct Node{
    int priority;
    int data;
    Node *next;
};

void showQueue(Node *queue)
{
    Node *aux = queue;
    while (aux != nullptr)
    {
        cout << "| " << aux->data << " " << aux->priority << " |   ";
        aux = aux->next;
    }
    cout << endl;
}

void insertElement(Node *&queue, int _data, int _priority)
{
    Node *newNodo = new Node();
    newNodo->priority = _priority;
    newNodo->data = _data;

    Node *aux1 = queue;
    Node *aux2;

    while( (aux1 != nullptr) && (aux1->priority < _priority) )
    {
        aux2 = aux1;
        aux1 = aux1->next;
    }

    if(queue == aux1)
    {
        queue = newNodo;
    }
    else
    {
        aux2->next = newNodo;
    }

    newNodo->next = aux1;
}

void deleteElement(Node *queue, int num)
{
    if(queue != nullptr)
    {
        Node *aux1 = queue;
        Node *aux2 = nullptr;

        while( (aux1 != nullptr) && (aux1->data != num) )
        {
            aux2 = aux1;
            aux1 = aux1->next;
        }
    }
}

bool searchElement(Node *queue, int num)
{
    Node *aux = queue;
    int contador = 1;
    while ( aux != nullptr )
    {
        if(aux->data == num)
        {
            cout << "Encontrado en la posicion: " << contador << endl;
            return true;
        }
        contador++;
        aux = aux->next;
    }
    return false;
}