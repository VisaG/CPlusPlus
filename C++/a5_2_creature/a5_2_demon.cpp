/*
 THIS IS FILE :- a5_2_demon.cpp

 Created on: June 10, 2013, Author: visalakshi Gopalakrishnan
 Class: CS 2B, Instructor name: Dave Harden.

 This is the implementation for the class demon
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "a5_2_demon.h"

demon::demon() : creature() {
}



demon::demon(int newStrength, int newPoints) :
        creature(newStrength, newPoints) {
}



int demon::getDamage() {

    int demonDamage;

    demonDamage = creature::getDamage();

    //cout << " attacks for " << demonDamage << " points!" << endl;

    if ((rand() % 100) < 25) {

        cout << "Demonic attack inflicts 50 additional damage points!" << endl;

        demonDamage = demonDamage + 50;

    }

    return demonDamage;

}



string demon::getSpecies(){

    return "demon";
}




