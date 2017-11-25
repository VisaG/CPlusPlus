/*
 THIS HEADER FILE IS :- a5_2_balrog.h

 Created on: June 10, 2013, Author: visalakshi Gopalakrishnan
 Class: CS 2B, Instructor name: Dave Harden.

 This is the interface for the class balrog
 */

#ifndef A5_2_BALROG_H_
#define A5_2_BALROG_H_

#include <iostream>
#include <fstream>
#include <string>
#include "a5_2_demon.h"
using namespace std;

class balrog : public demon
{
public:

    balrog();
    balrog(int newStrength, int newPoints);
    int getDamage();
    string getSpecies();

};


#endif /* A5_2_BALROG_H_ */
