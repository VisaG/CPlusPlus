/*
 THIS IS FILE :- a5_1_human.cpp

 Created on: June 10, 2013, Author: visalakshi Gopalakrishnan
 Class: CS 2B, Instructor name: Dave Harden.

 This is the implementation for the class human
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
#include "a5_1_human.h"

human::human() :
        creature() {
}




human::human(int newStrength, int newPoints) :
        creature(newStrength, newPoints) {
}




int human::getDamage() {

    int hdamage;

    hdamage = creature::getDamage();

    cout << "The Human attacks for " << hdamage << " points!" << endl;

    return hdamage;

}




string human::getSpecies() {

    return "human";
}

