/*
 THIS HEADER FILE IS :- a5_1_demon.h

 Created on: June 10, 2013, Author: visalakshi Gopalakrishnan
 Class: CS 2B, Instructor name: Dave Harden.

 This is the interface for the class demon
 This is primarily intended to be used as sub base class
 for different kinds of demon
 */

#ifndef A5_1_DEMON_H_
#define A5_1_DEMON_H_

#include <iostream>
#include "a5_1_creature.h"
using namespace std;

class demon : public creature
{
public:

    demon();
    demon(int newStrength, int newPoints);
    int getDamage();
    string getSpecies();

};


#endif /* A5_1_DEMON_H_ */
