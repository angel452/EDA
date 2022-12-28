#include<iostream>
#include <mutex>
#include <stdlib.h>
#include <time.h>
#include <thread>
using namespace std;

struct Node
{
    int dato;
    Node *next;
};

class Lista
{
    private:    
        Node* queue = nullptr;

    public:

        mutex candado;

        bool addValue(int valor){
            candado.lock();
            cout << "Añadiendo: " << valor << endl;

            if(conteinsSerch(valor)){
                //cout << "Saliendo del lock - Add value" << endl;
                candado.unlock();
                return false;
            }

            Node *newNodo = new Node(); 
            newNodo->dato = valor;

            Node *aux1 = queue;
            Node *aux2;

            while ( (aux1 != nullptr) && (aux1->dato < valor)){
                aux2 = aux1;
                aux1 = aux1->next;
            }

            if(queue == aux1){
                queue = newNodo;
            }   
            else{
                aux2->next = newNodo;
            }

            newNodo->next = aux1;
            candado.unlock();
            cout << "Nodo "<< valor << " insertado" << endl;
            return true;
        }

        bool deleteValue(int valor){
            if(queue != nullptr){
                
                candado.lock();

                cout <<  endl << "numero a eliminar: " << valor << endl;
                Node *aux1 = queue;
                Node *aux2 = nullptr;
                
                while ( (aux1 != nullptr) && (aux1->dato != valor)){
                    aux2 = aux1;
                    aux1 = aux1->next;
                }

                if( aux1 == nullptr ){
                    cout << "Elemento no encontrado" << endl;
                    candado.unlock();
                    return false;
                }
                else if(aux2 ==  nullptr){
                    queue = queue->next;
                    delete aux1;
                }
                else{
                    aux2->next = aux1->next;
                    delete aux1;
                }
                candado.unlock();
                cout << "Nodo "<< valor << " Eliminado" << endl;
                return true;
            }

            return true;
        }

        bool conteinsSerch(int value)
        {
            //candado.lock();
            Node *aux = queue;
            while (aux != nullptr)
            {
                if(aux->dato == value)
                {
                    //cout << "SI se encontro el elemento" << endl;
                    candado.unlock();
                    return true;
                }
                aux = aux->next;
            }
            cout << endl;
            //cout << "NO se encontro el elemento" << endl;
            //candado.unlock();
            return false;
        }


        void print(){
            Node *aux = queue;
            cout << "---------- Lista ------------- " << endl;
            cout << "| ";
            while (aux != nullptr)
            {
                cout << aux->dato << " | -> |";
                aux = aux->next; 
            }
            cout << endl;
        }
};

struct Add
{
    Lista *queue;
    int valMin, valMax;
    Add(Lista &_queue,int _valMin,int _valMax)
    {
        queue = &_queue;
        valMin = _valMin;
        valMax = _valMax;
    }
    
    void operator()(int n_operations)
    {
        for(int i = 0; i < n_operations; i++)
        {
            int number = valMin+rand()%(valMax);
            //cout << "Añadiendo: " << number << endl;
            queue->addValue(number);
        }
    }
};

struct Delete
{
    Lista *queue;
    int valMin, valMax;
    Delete(Lista &_queue,int _valMin,int _valMax)
    {
        queue = &_queue;
        valMin = _valMin;
        valMax = _valMax;
    }
    
    void operator()(int n_operations)
    {
        for(int i=0; i < n_operations; i++)
        {
            int number = valMin+rand()%(valMax);
            //cout << "Eliminando: " << number << endl;
            queue->deleteValue(number);
        }
    }
};


int main(){

    /*
    // Version 1
    queue.addValue(10);
    queue.addValue(20);
    queue.addValue(5);
    queue.addValue(50);
    queue.addValue(7);
    queue.addValue(12);

    queue.print();

    queue.deleteValue(50);
    queue.print();
    queue.deleteValue(5);
    queue.print();
    queue.deleteValue(20);
    queue.print();

    queue.conteinsSerch(5);
    queue.conteinsSerch(7);
    */

    /*
    //Version 2
    Lista queue;

    Add op1(queue,1,100);   
    op1(20); 
    queue.print();

    Delete op2(queue,1,100);
    op2(20);
    queue.print();
    */


    cout << "----- Usando Threads: -------- " << endl;

    srand(time(NULL));
    thread* threads[2];
    Lista queue;
    
    Add opt1(queue, 1,100);
    thread first(opt1,100);

    Delete opt2(queue, 1, 100);
    thread second(opt2, 100);

    threads[0] = &first;
    threads[1] = &second;

    threads[0]->join();
    threads[1]->join();

    queue.print();


    return 0;
}

/*

	LLP<int> lista2;
	thread th1(add<int>(&lista2, 10, 100), 100);
	thread th2(dlt<int>(&lista2, 10, 100), 100);
	th1.join();
	th2.join();
	lista2.print();
*/