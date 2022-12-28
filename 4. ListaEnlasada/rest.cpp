#include <iostream>
#include <time.h>
#include <mutex>

using namespace std;

template<class T>
struct Node
{
    Node(T x)
    {
        value = x;
        next = 0;
    }
    T value;
    Node<T>* next;
};

template<class T>
struct Lista
{
    Lista()
    {
        head = nullptr;
        nelem = 0;
        tail = nullptr;
    }
    bool contains(T x)
    {
        candado.lock();
        Node<T>* aux1 = head;
        while (aux1!= nullptr)
        {
            if (aux1->value == x)
            {
                candado.unlock();
                return true;
            }
            aux1 = aux1->next;
        }
        candado.unlock();
        return false;
    }

    bool Add(T x)
    {
        candado.lock();
        if (contains(x))
        {
            candado.unlock();
            return false;
        }
        else
        {
            Node<T>* n = new Node<T>(x);
            Node<T>* aux1 = head;
            Node<T>* aux2=nullptr;

            while (aux1 != nullptr && aux1->value < x)
            {
                aux2 = aux1;
                aux1 = aux1->next;
            }

            if (aux1 == head)
            {
                head = n;

            }
            else
            {
                aux2->next = n;
            }
            n->next = aux1;
            candado.unlock();
            return true;
        }
    }
    bool borrar(T x)
    {
      candado.lock();
        if (!contains(x))
        {
            candado.unlock();
            return false;
        }
        else
        {
            Node<T>* n = new Node<T>(x);
            Node<T>* aux1 = head;
            Node<T>* aux2 = nullptr;
            
            if (aux1->value == x)
            {
                head = aux1->next;
                delete aux1;
                return true;
            }

            while (aux1 != nullptr)
            {
                if (aux1->value == x)
                {
                    break;
                }
                aux2 = aux1;
                aux1 = aux1->next;
            }

            aux2->next = aux1->next;

            delete aux1;
            candado.unlock();
            return true;
        }
    }
    void print()
    {
        Node<T>* aux1;
        aux1 = head;
        cout << "head";
        while (aux1 != nullptr)
        {
            cout << "->" << aux1->value;
            aux1 = aux1->next;
        }
        cout << endl;
    }
    Node<T> *head;
    Node<T> *tail;
    int nelem;
    mutex candado;
};

template<class T>
struct ADD
{

  Lista<T> *list_;
  int min_,max_;
   ADD(Lista<T> &list,int min,int max)
  {
    list_=&list;
    min_=min;
    max_=max;
  }
  
  void operator()(int n_operations)
  {
    for(int x=0;x<n_operations;x++)
      {
        int number=min_+rand()%(max_);
        list_->Add(number);
      }
  }
};


template<class T>
struct BORRAR
{

  Lista<T> *list_;
  int min_,max_;
   BORRAR(Lista<T> &list,int min,int max)
  {
    list_=&list;
    min_=min;
    max_=max;
  }
  
  void operator()(int n_operations)
  {
    for(int x=0;x<n_operations;x++)
      {
        int number=min_+rand()%(max_);
        list_->borrar(number);
      }
  }
};


int main()
{
    srand(time(NULL));
    Lista<int> A;
    ADD<int> Add1(A,1,100);
    BORRAR<int> borrar1(A,1,100);
    Add1(10);
    A.print();
    borrar1(10);
    A.print();
}