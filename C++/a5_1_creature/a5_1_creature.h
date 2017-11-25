/*
  THIS FILE IS HEADER FILE :- a5_1_creature.h

 Created on: June 10, 2013, Author: visalakshi Gopalakrishnan
 Class: CS 2B, Instructor name: Dave Harden.

 This is the interface for the class creature
 This primarily intended to be used as a base class to derive
 classes for different kinds of creature
 */

#ifndef A5_1_CREATURE_H_
#define A5_1_CREATURE_H_

#include <iostream>
using namespace std;

class creature {

public:

    creature();
    creature(int newStrength,int newPoints);
    int getDamage();
    int getStrength();
    int getHitpoints();
    void setStrength(int newStrength);

private :

    int strength;
    int hitPoints;

};




#endif /* A5_1_CREATURE_H_ */
