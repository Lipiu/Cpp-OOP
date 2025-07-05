#include "Exam.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){

    int points[] = {1, 2, 3};
    Exam e1("OOP", 3, points, "08/07/2025", 1);

    cout << "exam" + e1;
    cout << endl;
    cout << e1.get_title() << endl;

    //writing to file
    ofstream file("exam.txt");
    if(file.is_open()){
        file << e1;
        file.close();
    }

    Exam* e_ptr = new Exam("Test", 3, points, "Test", 2);
    delete e_ptr;
    cout << e_ptr->get_title();

    return 0;
}