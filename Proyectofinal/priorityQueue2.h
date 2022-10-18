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
    cout << "More Priority..." << endl;
    while (aux != nullptr)
    {
        cout << "| D:" << aux->data << " P:" << aux->priority << " |   ";
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

        if(aux1 == nullptr)
        {
            cout << "Elemento no encontrado" << endl;
        }
        else if (aux2 == nullptr)
        {
            queue = queue->next;
            delete aux1;
        }
        else
        {
            aux2->next = aux1->next;
            delete aux1;
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
    cout << "No se encontro el elemento" << endl;
    return false;
}