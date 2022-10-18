#include <iostream>
using namespace  std;

struct Node{
    int priority;
    int data;
    Node *rigth;
    Node *left;
};

void showQueue(Node *queue, int contador)
{
    if(queue == nullptr)
    {
        return;
    }

    showQueue(queue->rigth, contador+1);
    cout << "| " << queue->data << " " << queue->priority << " |" << endl;
    showQueue(queue->left, contador+1);
}

int numOfChilds(Node *queue)
{
    int num = 0;
    if(queue->left != nullptr)
    {
        num = num+1;
    }

    if(queue->rigth != nullptr)
    {
        num = num+1;
    }

    return num;
}

void insertElement(Node *&queue, int _data, int _priority)
{
    Node *newNode = new Node();
    newNode->priority = _priority;
    newNode->data = _data;

    Node *aux1;
    Node *aux2;

    Node *auxGeneral;

    //Si el arbol esta vacio
    if(queue == nullptr)
    {
        queue = newNode;
        newNode->rigth = nullptr;
        newNode->left = nullptr;
    }
    else
    {
        aux1 = queue;
        aux2 = queue;

        // TO DO
    }
    //guardamos el puntero donde
    if( aux1 != nullptr )
    {
        do {
            aux2 = aux1;

            // A que hijo ir?
            if( numOfChilds(aux1) == 0)
            {
                aux1 = aux1->left;
                break;
            }
            else if( numOfChilds(aux1) == 1)
            {
                aux1 = aux1->rigth;
                break;
            }
            else if( numOfChilds(aux1) == 2)
            {
                aux1 = aux1->left;
            }
        } while (aux1 != nullptr);
    }

    if(true)
    {
        aux2->left = newNode;
        auxGeneral->rigth = newNode;
    }

    newNode->left = aux1;
    newNode->rigth = aux2;
}

void deleteElement()
{

}

void searchElement()
{

}
