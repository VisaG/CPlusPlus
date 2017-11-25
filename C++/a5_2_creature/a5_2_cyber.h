/*
 THIS HEADER FILE IS :- a5_2_cyber.h

 Created on: June 10, 2013, Author: visalakshi Gopalakrishnan
 Class: CS 2B, Instructor name: Dave Harden.

 This is the interface for the class cyberdemon
 */

#ifndef A5_2_CYBER_H_
#define A5_2_CYBER_H_

#include <iostream>
#include <fstream>
#include <string>
#include "a5_2_demon.h"
using namespace std;

class cyberdemon : public demon
{
public:

    cyberdemon();
    cyberdemon(int newStrength, int newPoints);
    //int getDamage();
    string getSpecies();

};




#endif /* A5_2_CYBER_H_ */
