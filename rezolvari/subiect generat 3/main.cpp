#include "Student.h"
#include <iostream>
using namespace std;

int main(){

    int grades[] = {9, 8, 10};

    Student s("Marius", 3, grades, 20);
    
    int* getter_test = s.get_grades();
    for(int i = 0; i < s.get_no_grades(); i++){
        cout << "Grade: " << (i+1) << ": " << getter_test[i] << endl;
    }
    

    Student s2 = s;

    if(s == s2){
        cout << "Objects are the same" << endl;
    }
    else{
        cout << "Objects are different" << endl;
    }

    cout << endl;

    ++s;
    cout << s.get_age() << endl;

    s++;
    cout << s.get_age() << endl;

    Student s3("XSlayder", 3, grades, 25);

    if(s < s3){
        cout << "Marius este mai tanar decat XSlayder" << endl;
    }
    else{
        cout << "XSlayder este mai tanar decat Marius" << endl;
    }

    Student s4;
    s4 = s;

    cout << s4;

    cout << endl;

    return 0;
}