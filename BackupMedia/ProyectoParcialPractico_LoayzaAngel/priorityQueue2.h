#include <iostream>
using namespace  std;

template <typename ElemType>
struct Node{
    ElemType priority;
    ElemType data;
    Node *next;
};

template <typename ElemType>
void showQueue(Node<ElemType> *queue)
{
    Node<ElemType> *aux = queue;
    cout << "More Priority..." << endl;
    while (aux != nullptr)
    {
        cout << "| D:" << aux->data << " P:" << aux->priority << " |   ";
        aux = aux->next;
    }
    cout << endl;
}

template <typename ElemType>
void insertElement(Node <ElemType> *&queue, int _data, int _priority)
{
    Node<ElemType> *newNodo = new Node<ElemType>() ;
    newNodo->priority = _priority;
    newNodo->data = _data;

    Node<ElemType> *aux1 = queue;
    Node<ElemType> *aux2;

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

template <typename ElemType>
void deleteElement(Node<ElemType> *&queue, int num)
{
    if(queue != nullptr)
    {
        Node<ElemType> *aux1 = queue; //aux borrar
        Node<ElemType> *aux2 = nullptr; // anterior

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
            //cout << "el primer elemento borrado" << endl;
            //cout << queue->data << " - ";
            queue = queue->next;
            //cout << queue->data << endl;
            delete aux1;
        }
        else
        {
            aux2->next = aux1->next;
            delete aux1;
        }
    }
}

template <typename ElemType>
bool searchElement(Node<ElemType> *queue, int num)
{
    Node<ElemType> *aux = queue;
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

template<typename ElemType>
void getPQ(Node<ElemType> *queue)
{
    cout << "Dato con mas prioridad: " << queue->data << endl;
    cout << "Nivel de Prioridad: " << queue->priority << endl;
}