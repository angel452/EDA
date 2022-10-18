#include <iostream>
//#include "priorityQueue.h"
#include "priorityQueue2.h"
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
            //cout << "Data: "; cin >> data;
            data = 1;
            cout << "Priority: "; cin >> priority;

            insertElement(queue, data, priority);
        }

        else if(answer == 2) // delete
        {
            int num; cin >> num;
            deleteElement(queue,num);
        }

        else if(answer == 3) //search
        {
            int num; cin >> num;
            searchElement(queue,num);
        }

        else if(answer == 4) //show
        {
            showQueue(queue);
        }

    } while ( answer != 0 );

    return 0;
}
