#include<iostream>
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

    bool addValue(int valor){
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
        return true;
    }

    bool deleteValue(int valor){
        if(queue != nullptr){
            cout << "numero a eliminar: " << valor << endl;
            Node *aux1 = queue;
            Node *aux2 = nullptr;

            while ( (aux1 != nullptr) && (aux1->dato != valor)){
                cout << "buscando ... " << aux1->dato << endl;
                aux2 = aux1;
                aux1 = aux1->next;
            }
            cout << "Se encontro el dato: " << endl;
            cout << "aux1: " << aux1->dato << endl;
            cout << "aux2: " << aux2->dato << endl;

            if( aux1 == nullptr ){
                cout << "Elemento no encontrado" << endl;
                //return false;
            }
            else if(aux2 = nullptr){
                cout << "segundo condicional" << endl;
                queue = queue->next;
                delete aux1;
            }
            else{
                cout << "aaaa as" << endl;
                cout << "aux despues:" << aux1->dato << endl;
                cout << "aux anterior:" << aux2->dato << endl;

                aux2->next = aux1->next;
                delete aux1;
            }
            return true;
        }

        return true;
    }

    bool conteinsSerch(){
        return true;
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


int main(){

    Lista queue;

    queue.addValue(10);
    queue.addValue(20);
    queue.addValue(5);
    queue.addValue(50);
    queue.addValue(7);
    queue.addValue(12);

    queue.print();

    //queue.deleteValue(50);
    //queue.deleteValue(5);
    queue.deleteValue(20);

    queue.print();

    return 0;
}