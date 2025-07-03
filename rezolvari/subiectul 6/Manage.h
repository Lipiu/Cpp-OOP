/*
(2p) Exemplify the use of a 1: 1 type “has a” relationship (one to one) by defining an additional class to manage a student's assessment. For the new class define the copy constructor. 
(1p) Exemplify the relationship between the constructors of the two classes, which are in the ratio of 1: 1, if the initial class does not have a default constructor. 
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Exam.h"
#include <iostream>
using namespace std;

class Manager {
private:
    Exam exam;
public:
    Manager(const Exam& e) : exam(e) { }
    Manager(const Manager& m) : exam(m.exam) { }
};