/*
 THIS HEADER FILE IS :- a5_1_human.h

 Created on: June 10, 2013, Author: visalakshi Gopalakrishnan
 Class: CS 2B, Instructor name: Dave Harden.

 This is the interface for the class human
 */

#ifndef A5_1_HUMAN_H_
#define A5_1_HUMAN_H_

#include <iostream>
#include <fstream>
#include <string>
#include "a5_1_creature.h"
using namespace std;

class human : public creature {

public:

    human();
    human(int newStrength, int newPoints);
    int getDamage();
    string getSpecies();

};

#endif /* A5_1_HUMAN_H_ */
