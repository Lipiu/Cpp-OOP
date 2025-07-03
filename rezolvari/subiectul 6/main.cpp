#include "Exam.h"
#include "Manage.h"
#include <iostream>
#include <fstream>
using namespace std;


int main(){
    int points[] = {1,2,3};
    Exam e1("OOP", points, 3, "08/07/2025", "OOP Basics");
    Exam e2("Java", points, 3, "09/07/2025", "TCP/UDP, Multithreading");

    ofstream os("output.txt");

    if(!os.is_open()){
        cout << "Error: could not open file";
        return 1;
    }
    os << e1;
    os << e2;

    os.close();

    return 0;
}