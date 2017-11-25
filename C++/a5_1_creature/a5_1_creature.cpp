/*
 THIS IS FILE :- a5_1_creature.cpp

 Created on: June 10, 2013, Author: visalakshi Gopalakrishnan
 Class: CS 2B, Instructor name: Dave Harden.

 This is the implementation for the class creature
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "a5_1_creature.h"

using namespace std;

creature::creature() {

    strength = 10;
    hitPoints = 10;

}




creature::creature(int newStrength, int newPoints) {

    strength = newStrength;
    hitPoints = newPoints;

}




int creature::getDamage() {

    int damage;
    damage = (rand() % strength) + 1;
    return damage;

}




int creature::getHitpoints() {

    return hitPoints;

}




int creature::getStrength() {

    return strength;

}




void creature::setStrength(int newStrength) {

    strength = newStrength;

}
