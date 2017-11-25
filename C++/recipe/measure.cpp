/*
 ** This file is implementation file :- measure.cpp

 The interface for class measure is in the header file :- measure.h.

 CLASS INVARIANT:

 Following are the data members in this class.
 static const int LARGEST_UNIT = 11;
 static const int SMALLEST_UNIT = 0;
 These two constants:  we'll be using a system where
 dram = 0, tsp = 1, tbsp = 2, and so on.  So the
 smallest unit (dram) is represented by 0, and the
 largest unit (acre_ft) is represented by 11.

 static const int NUM_UNITS = 12;
 The maximum number of units

 static const cs2b_fraction::fraction conversionTable[NUM_UNITS];
 Const array initialized with measurement fraction

 static const cs2b_mystring::myString unitStrings[NUM_UNITS];
 Const array initialized with measurement units

 cs2b_fraction::fraction amount;

 int unit;    //if unit = 0, the unit is dram.
 //if unit = 1, the unit is tsp, and so on.

 void Measure::simplify()
 Post-condition
 -Make the amount bigger if it is less than 1, unless the unit is already
 "dram" (in which case the amount can't be made any bigger).
 -Make the amount smaller if it can be made smaller without making it
 less than 1, unless the unit is already acre_ft (in which case the
 amount can't be made any smaller)

 */

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <string>
#include "measure.h"

using namespace std;

const cs2b_fraction::fraction Measure::conversionTable[] = {
        cs2b_fraction::fraction(4, 3), 3, 2, 8, 2, 2, 4, 2, 4,
        cs2b_fraction::fraction(55, 7), 6000 };


const cs2b_mystring::myString Measure::unitStrings[] =
        { "dram", "tsp", "tbsp", "oz", "cup", "pint", "qt", "gal", "peck",
                "bushel", "barrel", "acre_ft" };


ostream& operator<<(ostream& out, const Measure &printMe) {

    out << printMe.amount << " " << printMe.unitStrings[printMe.unit];
    return out;
}




istream& operator>>(istream& in, Measure &readMe) {

    cs2b_mystring::myString tempStr;
    int count = 0;

    in >> readMe.amount >> tempStr;
    while (tempStr != Measure::unitStrings[count]) {
        count++;
        assert(count < Measure::NUM_UNITS);
    }
    readMe.unit = count;
    readMe.simplify();
    return in;
}




/*Operator overloading for *=*/
Measure Measure::operator*=(const cs2b_fraction::fraction &right) {

    amount *= right;
    simplify();

    return *this;
}




void Measure::simplify() {

    /*Make the amount bigger if it is less than 1, unless the unit is already
      "dram" (in which case the amount can't be made any bigger)*/

    while (amount < 1 && unit > SMALLEST_UNIT) {
        amount = amount * conversionTable[unit - 1];
        unit--;
    }

    /*Make the amount smaller if it can be made smaller without making it
      less than 1, unless the unit is already acre_ft (in which case the
      amount can't be made any smaller)*/

    bool done = false;
    cs2b_fraction::fraction temp;
    temp = amount;

    while (temp >= conversionTable[unit] && unit < LARGEST_UNIT) {
        temp = temp / conversionTable[unit];

        if (temp < 1) {
            done = true;
        } else {
            amount = temp;
            unit++;
        }
    }
}

