/*
 Name:Visalakshi Gopalakrishnan
 Date:May 20 2013
 Assignment Number:CS2B a3
 Instructor:Dave Harden
 Phase 2: Ingredient Class
 File: ingredient.h

 The Ingredient class Phase Two of recipe program is simply a
 measure and ingredient name stored as a myString.

 **
 Public functions
 ================

 friend ostream& operator<<(ostream& out, const Measure &printMe);

 Pre-condition
 -The object ostream out is ready for writing
 Post-condition
 -The contents of "printMe" (measure object and ingredient name as string )
 have been inserted into "out".

 **


 **
 friend istream& operator>>(istream& in, MyString &readMe);

 Pre-condition
 -The object istream in is ready for reading.
 Post-condition
 -The readMe is filled with measure and ingredient name

 **


 **
 Measure operator*=(const cs2b_fraction::fraction &right);

 Pre-condition
 -Calls operator overload of cs2b_fraction fraction class.
 Post-condition
 -Calculates the product of the calling object measure and right.  Assigns
 this quantity to the calling object and returns the same quantity.

 **
 */

#ifndef INGREDIENT_H_
#define INGREDIENT_H_
#include <iostream>
#include "mystring.h"
#include "fraction.h"
#include "measure.h"

using namespace std;

class Ingredient {

public:
    friend ostream& operator<<(ostream& out, const Ingredient &printMe);
    friend istream& operator>>(istream& in, Ingredient &readMe);
    Ingredient operator*=(const cs2b_fraction::fraction &right);

private:

    Measure measure;
    cs2b_mystring::myString ingString;

};
#endif /* INGREDIENT_H_ */
