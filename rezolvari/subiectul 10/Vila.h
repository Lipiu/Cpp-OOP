//Exemplificați conceptul de relație de tip „is a” prin specializarea clasei Casa.
//Testați soluția prin instanțierea noii clase. 

#include "Casa.h"
#include <iostream>
#include <string>
using namespace std;

class Vila : public Casa{
private:
    int pret = 0;
public:
    Vila(int pret, char* suprafata, int numar_locatari, int numar_camere, bool cu_etaj) : 
    Casa(suprafata, numar_locatari, numar_camere, cu_etaj){
        this->pret = pret;
    }

    void do_something() override{
        cout << "Method from Vila.h" << endl;
    }
};