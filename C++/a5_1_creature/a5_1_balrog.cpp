/*
 THIS IS FILE :- a5_1_balrog.cpp

 Created on: June 10, 2013, Author: visalakshi Gopalakrishnan
 Class: CS 2B, Instructor name: Dave Harden.

 This is the implementation for the class balrog
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "a5_1_balrog.h"

balrog::balrog() : demon() {
}



balrog::balrog(int newStrength, int newPoints) :
        demon(newStrength, newPoints) {
}



int balrog::getDamage() {

    int damage1, damage2, balDamage;

    cout << "The balrog ";

    damage1 = demon::getDamage();
    damage2 = (rand() % creature::getStrength()) + 1;

    cout << "Balrog speed attack inflicts "<<damage2 << " additional damage points!" << endl;

    balDamage = damage1 + damage2;

    return balDamage;

}




string balrog::getSpecies(){

    return "balrog";
}
