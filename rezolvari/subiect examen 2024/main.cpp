#include "ElectionCandidate.h"
#include <iostream>
using namespace std;

int main(){

    Candidate c("Nicusor Dan", Independent, 3000000, "Bucuresti");
    Candidate c2("George Simion", Terminat, 1, "Pleaca fram");
    Candidate c3 = c;
    cout << c.get_name() << endl;

    c.set_name("John");
    cout << c.get_name();

    cout << "\nDestructor test:\n";
    Candidate* c_ptr = new Candidate("Test", Republican, 1, "test");
    delete c_ptr;

    cout << "\nCopy constructor test:\n";
    Candidate copy_test = c;
    cout << copy_test.get_name();

    c.print_total();

    cout << endl;

    Candidate operator_equal_test("Test", Republican, 1, "test");
    Candidate operator_equal_test2("Test2", Independent, 2, "test2");

    operator_equal_test = operator_equal_test2;
    cout << operator_equal_test.get_name() << endl;
    cout << operator_equal_test2.get_name() << endl;

    cout << endl;

    cout << c << endl;
    cout << c3 << endl;

    // ++c;
    // cout << c << endl;

    if(c == c3){
        cout << "True";
    }
    else{
        cout << "False";
    }

    cout << endl;

    c.check_name("John");

    c.calculatePopularityIndex();

    return 0;
}