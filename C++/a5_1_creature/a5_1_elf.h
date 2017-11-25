/*
 THIS HEADER FILE IS :- a5_1_elf.h

 Created on: June 10, 2013, Author: visalakshi Gopalakrishnan
 Class: CS 2B, Instructor name: Dave Harden.

 This is the interface for the class elf
 */


#ifndef A5_1_ELF_H_
#define A5_1_ELF_H_

#include <iostream>
#include <fstream>
#include <string>
#include "a5_1_creature.h"
using namespace std;

class elf : public creature
{
public:

    elf();
    elf(int newStrength, int newPoints);
    int getDamage();
    string getSpecies();

};




#endif /* A5_1_ELF_H_ */
