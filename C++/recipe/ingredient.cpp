/*
 ** This file is implementation file :- measure.cpp

 The interface for class measure is in the header file :- ingredient.h.

 CLASS INVARIANT:

 Following are the private data members in this class.

 Measure measure;
 measure represents object of Measure class

 cs2b_mystring::myString ingString;
 ingString represents ingredient name as string

 */

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <string>
#include "ingredient.h"

using namespace std;

ostream& operator<<(ostream& out, const Ingredient &printMe) {

    out << printMe.measure << " " << printMe.ingString;
    return out;
}




istream& operator>>(istream& in, Ingredient &readMe) {

    in >> readMe.measure;
    readMe.ingString.read(in, '\n');
    return in;
}




/*(*=) operator scales the measure of the ingredient depending on the serving size*/

Ingredient Ingredient::operator*=(const cs2b_fraction::fraction &right) {
    this->measure *= right;
    return *this;
}
