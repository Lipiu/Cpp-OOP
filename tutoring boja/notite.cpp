#include <string>
#include <iostream>

using namespace std;

//overloading operators

class Faculty{
private:
    int no_students;
    string name;
    int student_per_year[3] = {100, 200, 150};

public:
    Faculty(string name, int no_students){
        this->no_students = no_students;
        this->name = name;
    }

    friend void operator<<(ostream& os, Faculty f);
};

//global to avoid the extra parameter "this" from the class
void operator<<(ostream& os, Faculty f){ //pass by reference because ostream is a really big buffer
    os << "Faculty name: " << f.name << "\n";
    os << "Number of students: " << f.no_students;
}

Faculty operator+(int value, Faculty f1){
     
}

int main(){
    Faculty csie("CSIE", 1000);

    //stream operators
    cout << csie;
    // cin >> csie; 
    // cout << endl << csie;

    // /*
    // operator = (mandatory if we have dynamic fields)
    // Faculty f1("", 0);
    // f1 = csie;

    // Faculty f2 = csie; //copy constructor, not operator =
    // */

    // //binary math operators
    // Faculty temp = csie + 10;
    // temp = 20 + c;
    // temp = csie - 10;
    // int result = 10 - csie;
    // temp = csie * 2;
    // temp = csie / 2;

    // //unary operators (still binary operators)
    // csie += 2;
    // csie -= 10;
    // csie *= 5;
    // csie /= 6;

    // //unary math operators
    // f1 = csie++; //post
    // f1 = ++csie; //pre
    // //same for --

    //logic operators
    // if(f1 == csie)
    //     cout << endl << "Same name";
    // else
    //     cout << endl << "Different name";

    // if(f1 > csie){
    //     cout << endl << "f1 has more students";
    // }

    // //same for <, <=, >=, !=
    // // ! operator (not)
    // if(!csie){
    //     cout << endl << "There are no students";
    // }

    // int result = csie(10, 2000); //function operator

    // int no_students_in_2nd_year = csie[1]; //index operator
    // csie[2] = 500;

    //cast operator -> always ask for explicit form, never implicit
    // int no_students = (int)csie; //explicit cast operator

}