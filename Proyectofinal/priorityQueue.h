#include <iostream>
using namespace  std;

struct Node{
    int priority;
    int data;
    Node *next;
};

void showQueue(Node *&queue)
{
    Node *ptrNode;

    cout << "-------------------------------------------------------------------------------" << endl;
    for(ptrNode = queue; ptrNode != nullptr; ptrNode = ptrNode->next )
    {
        cout << "|" << ptrNode->data << " - " << ptrNode->priority << "|     ";
    }
    cout << endl << "-------------------------------------------------------------------------------" << endl;
}

void insertElement(Node *&queue, int _data, int _priority)
{
    Node *newNode = new Node();
    newNode->data = _data;
    newNode->priority = _priority;

    Node *aux1 = queue;
    Node *aux2;

    while( (aux1 != nullptr) && (aux1->priority < _priority))
    {
        aux2 = aux1;
        aux1 = aux1->next;
    }

    if(queue == aux1)
    {
        queue = newNode;
    }
    else
    {
        aux2->next = newNode;
    }

    newNode->next = aux1;
}

void deleteElement()
{

}

void searchElement()
{

}