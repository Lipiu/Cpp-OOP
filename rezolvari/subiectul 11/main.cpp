#include "DoctorAppointment.h"
#include "Pacient.h"
#include <string>
#include <iostream>
using namespace std;

int main(){
    string name1 = "Liviu";
    Appointment a1(4, "08/07/2025", &name1);

    cout << "Date for a1: " << a1.get_date() << endl;

    cout << endl;

    a1++;
    cout << "Date for a1 after increment (postfix): " << a1.get_date() << endl;

    ++a1;
    cout << "Date for a1 after increment another increment (prefix): " << a1.get_date() << endl;

    cout << endl;

    Pacient p;
    p.pacient_app();
    cout << endl;

    //situations for copy constructor
    Appointment a2 = a1; // case 1
    //case 2 when we return the copy in the overloaded operator

    p += a1;
    p += a2;
    p.show_appointments();


    return 0;
}