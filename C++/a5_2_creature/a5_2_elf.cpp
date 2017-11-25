/*
 THIS IS FILE :- a5_2_elf.cpp

 Created on: June 10, 2013, Author: visalakshi Gopalakrishnan
 Class: CS 2B, Instructor name: Dave Harden.

 This is the implementation for the class cyberdemon
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "a5_2_elf.h"

elf::elf() : creature() {
}




elf::elf(int newStrength, int newPoints) :
        creature(newStrength, newPoints) {
}




int elf::getDamage() {

    int elfDamage;

    elfDamage = creature::getDamage();

  //  cout << "The Elf attacks for " << elfDamage << " points!" << endl;

    if ((rand() % 50) == 0) {

        cout << "Magical attack inflicts " << elfDamage
                << " additional damage points!" << endl;

        elfDamage = elfDamage * 2;

    }

    return elfDamage;

}




string elf::getSpecies() {

    return "elf";
}





