/*
 THIS IS FILE :- a5_1_cyber.cpp

 Created on: June 10, 2013, Author: visalakshi Gopalakrishnan
 Class: CS 2B, Instructor name: Dave Harden.

 This is the implementation for the class cyberdemon
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
#include "a5_1_cyber.h"

cyberdemon::cyberdemon() :
        demon() {
}



cyberdemon::cyberdemon(int newStrength, int newPoints) :
        demon(newStrength, newPoints) {
}



int cyberdemon::getDamage() {

    int cyberDamage;

    cout << "The cyberdemon ";

    cyberDamage = demon::getDamage();

    return cyberDamage;

}




string cyberdemon::getSpecies() {

    return "cyberdemon";
}

