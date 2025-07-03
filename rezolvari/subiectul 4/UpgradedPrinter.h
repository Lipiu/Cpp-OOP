#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Printer.h"
#include <iostream>
using namespace std;

class UpgradedPrinter : public Printer{
public:
    UpgradedPrinter() : Printer(){}

    UpgradedPrinter(const char* manufacturer, const char* model, int new_no_printer_pages, float new_temperature) : Printer(manufacturer, model, new_no_printer_pages, new_temperature){}

    void my_method(){
        cout << "my_method from UpgradedPrinter.h" << endl;
    }
};