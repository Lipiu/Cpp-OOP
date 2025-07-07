#include "Casa.h"
#include "Vila.h"
#include <string>
#include <iostream>
using namespace std;

int main(){

    //Se definește operator() (int) (operator funcție) care primește numărul de locatari din acea casă.

    Casa c1("2000 m^2", 3, 3, true);

    Casa c2 = c1;

    //testare operator ==
    if(c1 == c2){
        cout << "Obiectele sunt de acelasi fel" << endl;
    }
    else{
        cout << "Obiectele sunt diferite" << endl;
    }

    cout << endl;

    Vila v1(100000, "4000 m^2", 2, 4, true);

    c1.do_something();
    v1.do_something();

    cout << c1;

    //early binding takes place at compile time while late binding takes place at run time
    //early binding uses non-static methods while late binding uses virtual methods
    //late binding uses a vtable for each polymorphic class. Objects carry a pointer to their class vtable.
    return 0;
}
