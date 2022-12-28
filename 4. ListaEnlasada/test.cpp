#include <iostream>
using namespace std;

bool valide( bool pred, bool current)
{
    if (!pred || !current)
    {
        cout << "Falso" << endl;
        return false;
    }
    cout << "Verdad" << endl ;
    return true;
}

int main(){

    bool aux1 = true;
    bool aux2 = true;

    if(valide(aux1, aux2)){
        cout << "Entra" << endl;
    }
    else{
        cout << "noEntra" << endl;
    }



    if(aux1 == true && aux2 == true){
        cout << "Entra 2" << endl;
    }
    else{
        cout << "noEntrano 2" << endl;
    }
    

    return 0;
}