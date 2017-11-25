/*
 Name:Visalakshi Gopalakrishnan
 Date:May 20 2013
 Assignment Number:CS2B a3
 Instructor:Dave Harden
 Phase 1: Measure Class
 File: measure.h

 The measure class Phase One of recipe program and will consists of a
 fractional amount and an associated English unit. The measure class will be
 responsible for converting the amount to the most "reasonable" unit,
 which is the largest unit where the amount is greater than or equal to 1
 if such a unit exists. Otherwise, the unit should be the smallest known unit
 and an associated English unit.
 Measure class scales the fractional amount based on number of servings
 and assign an associated English unit


 Provides the following functionality
 ====================================
 Scaled Fractional amount based on number of servings
 and an associated English unit

 **

 **
 Public functions
 ================

 friend ostream& operator<<(ostream& out, const Measure &printMe);

 Pre-condition
 -The object ostream out is ready for writing
 Post-condition
 -The contents of "printMe" have been inserted into "out".
 **


 **
 friend istream& operator>>(istream& in, MyString &readMe);

 Pre-condition
 -The object istream in is ready for reading.
 Post-condition
 -The readMe is filled with the correct units and adjusted measure
 according to conversion table.
 **


 **
 Measure operator*=(const cs2b_fraction::fraction &right);

 Pre-condition
 -Calls operator overload of cs2b_fraction fraction class.
 Post-condition
 -Calculates the product of the calling object and right.  Assigns
 this quantity to the calling object and returns the same quantity.

 **
 */

#ifndef MEASURE_H_
#define MEASURE_H_

#include <iostream>
#include "mystring.h"
#include "fraction.h"

using namespace std;

class Measure {
public:
    friend ostream& operator<<(ostream& out, const Measure &printMe);
    friend istream& operator>>(istream& in, Measure &readMe);
    Measure operator*=(const cs2b_fraction::fraction &right);
private:

    void simplify();

    static const int LARGEST_UNIT = 11;
    static const int SMALLEST_UNIT = 0;
    // these two constants:  we'll be using a system where
    // dram = 0, tsp = 1, tbsp = 2, and so on.  So the
    // smallest unit (dram) is represented by 0, and the
    // largest unit (acre_ft) is represented by 11.
    static const int NUM_UNITS = 12;
    static const cs2b_fraction::fraction conversionTable[NUM_UNITS];
    static const cs2b_mystring::myString unitStrings[NUM_UNITS];
    cs2b_fraction::fraction amount;
    int unit;    //if unit = 0, the unit is dram.
                 //if unit = 1, the unit is tsp, and so on.
};

#endif /* MEASURE_H_ */
