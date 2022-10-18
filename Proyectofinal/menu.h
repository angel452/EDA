#include <iostream>
using namespace  std;

int showMenu()
{
    cout << "--------------- Priority Queue ----------------" << endl;
    cout << " Insert a Element ------------------ 1 " << endl;
    cout << " Delete a Element ------------------ 2 " << endl;
    cout << " Search a Element ------------------ 3 " << endl;
    cout << " Show queue  ----------------------- 4 " << endl;
    cout << " Insert Elements from .txt  -------- 5 " << endl;
    cout << " Exit ------------------------------ 0 " << endl;
    cout << "-----------------------------------------------" << endl;

    int answer;
    cout << "Answer: "; cin >> answer;

    return answer;
}