/*
 THIS IS FILE :- a5_2_cyper.cpp

 Created on: June 10, 2013, Author: visalakshi Gopalakrishnan
 Class: CS 2B, Instructor name: Dave Harden.

 This is the implementation for the class cyberdemon
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
#include "a5_2_cyber.h"

cyberdemon::cyberdemon() : demon() {
}




cyberdemon::cyberdemon(int newStrength, int newPoints) :
        demon(newStrength, newPoints) {
}




string cyberdemon::getSpecies() {

    return "cyberdemon";
}

