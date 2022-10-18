#include <iostream>
#include <fstream>
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
            cout << "Data: "; cin >> data;
            cout << "Priority: "; cin >> priority;
            insertElement(queue, data, priority);


        }

        else if(answer == 2) // delete
        {
            int num;
            cout << "Elemento a eliminar: "; cin >> num;
            deleteElement(queue,num);
        }

        else if(answer == 3) //search
        {
            int num;
            cout << "Elemento a buscar"; cin >> num;
            searchElement(queue,num);
        }

        else if(answer == 4) //show
        {
            showQueue(queue);
        }

        else if(answer == 5) //show
        {
            cout << "Insertando Datos ..." << endl;

            ifstream dataTxt("data.txt");

            if (!dataTxt.is_open()) {
                cerr << "Could not open the file" << endl;
                return EXIT_FAILURE;
            }

            int contador = 0;
            int a, b;
            while (contador < 25)
            {
                dataTxt >> a >> b;
                cout << a << " - " << b << endl;
                insertElement(queue,a,b);
                contador++;
            }

            dataTxt.close();
            cout << "Se insertaron todos los datos correctamente" << endl;
        }

    } while ( answer != 0 );

    return 0;
}
