#include <iostream>
#include <fstream>
#include "priorityQueue2.h"
using namespace  std;

int showMenu()
{
    cout << "--------------- PRIORITY QUEUE -------------------" << endl;
    cout << " Insert a Element ------------------ 1 " << endl;
    cout << " Delete a Element ------------------ 2 " << endl;
    cout << " Search a Element ------------------ 3 " << endl;
    cout << " Show queue  ----------------------- 4 " << endl;
    cout << " Insert Elements from .txt (INT) --- 5 " << endl;
    cout << " Get Priority Element -------------- 6 " << endl;
    cout << " Exit ------------------------------ 0 " << endl;
    cout << "---------------------------------------------------" << endl;

    int answer;
    cout << "Answer: "; cin >> answer;

    return answer;
}

template<typename ElemType>
void chooseFuction(Node<ElemType> *queue)
{
    int answer;
    do {
        answer = showMenu();

        if( answer == 1) //insert
        {
            ElemType data, priority;
            cout << "Data: "; cin >> data;
            cout << "Priority: "; cin >> priority;
            insertElement(queue, data, priority);
        }

        else if(answer == 2) // delete
        {
            ElemType num;
            cout << "Elemento a eliminar: "; cin >> num;
            deleteElement(queue,num);
        }

        else if(answer == 3) //search
        {
            ElemType num;
            cout << "Elemento a buscar: "; cin >> num;
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
                return;
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

        else if(answer == 6)
        {
            getPQ(queue);
        }

        else
        {
            cout << "Opcion invalida. Intente de nuevo" << endl;
        }

    } while ( answer != 0 );
}