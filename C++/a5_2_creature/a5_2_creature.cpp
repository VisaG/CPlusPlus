/*
 THIS IS FILE :- a5_2_creature.cpp

 Created on: June 10, 2013, Author: visalakshi Gopalakrishnan
 Class: CS 2B, Instructor name: Dave Harden.

 This is the implementation for the class creature
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "a5_2_creature.h"

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

    cout << "The " << getSpecies() << " attacks for " << damage << " points!"
            << endl;

    return damage;

}




int creature::getHitpoints() {

    return hitPoints;

}




void creature::setHitpoints(int newHitpoints) {

    hitPoints = newHitpoints;
}




int creature::getStrength() {

    return strength;

}




void creature::setStrength(int newStrength) {

    strength = newStrength;

}
