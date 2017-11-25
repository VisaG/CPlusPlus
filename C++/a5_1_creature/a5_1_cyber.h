/*
 THIS HEADER FILE IS :- a5_1_cyber.h

 Created on: June 10, 2013, Author: visalakshi Gopalakrishnan
 Class: CS 2B, Instructor name: Dave Harden.

 This is the interface for the class cyberdemon
 */

#ifndef A5_1_CYBER_H_
#define A5_1_CYBER_H_

#include <iostream>
#include <fstream>
#include <string>
#include "a5_1_demon.h"
using namespace std;

class cyberdemon : public demon
{
public:

    cyberdemon();
    cyberdemon(int newStrength, int newPoints);
    int getDamage();
    string getSpecies();

};



#endif /* A5_1_CYBER_H_ */
