#include <iostream>
#include "priorityQueue.h"
#include "menu.h"
using  namespace  std;

int main()
{
    Node *queue = nullptr;

    int answer;
    do {
        answer = showMenu();

        if( answer == 1) //insert
        {
            int data, priority;
            cout << "Data: "; cin >> data;
            cout << "Priority: "; cin >> priority;

            insertElement(queue, data, priority);
        }

        else if(answer == 2) // delete
        {
            deleteElement();
        }

        else if(answer == 3) //search
        {
            searchElement();
        }

        else if(answer == 4) //search
        {
            showQueue(queue);
        }

    } while ( answer != 0 );

    return 0;
}
