#include "Printer.h"
#include "UpgradedPrinter.h"
#include <iostream>
using namespace std;

int main(){

    Printer p1("HP", "HP Printer", 100, 23);
    Printer p2("DELL", "DELL Printer", 120, 26);

    cout << "General info about printers:" << endl;
    p1.print_info();
    cout << endl;
    p2.print_info();

    p1.my_method();

    UpgradedPrinter up;
    up.my_method();

    return 0;
}