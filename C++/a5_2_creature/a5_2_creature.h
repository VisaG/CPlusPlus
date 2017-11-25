/*
THIS FILE IS HEADER FILE :- a5_2_creature.h

 Created on: June 10, 2013, Author: visalakshi Gopalakrishnan
 Class: CS 2B, Instructor name: Dave Harden.

 This is the interface for the class creature
 This primarily intended to be used as a base class to derive
 classes for different kinds of creature
 */

#ifndef A5_2_CREATURE_H_
#define A5_2_CREATURE_H_

#include <iostream>
#include <string>
using namespace std;

class creature {

public:

    creature();
    creature(int newStrength,int newPoints);
    virtual int getDamage();
    int getStrength();
    int getHitpoints();
    void setHitpoints(int newHitpoints);
    void setStrength(int newStrength);
    virtual string getSpecies() = 0;

private :

    int strength;
    int hitPoints;

};



#endif /* A5_2_CREATURE_H_ */
