/*This file is implementation file :- fraction.cpp

 Created on: Apr 16, 2013, Author: visa
 Class: CS 2B, Instructor name: Dave Harden.

 The interface for class fraction is in the header file :- fraction.h

 Private


 **
 Data types
 int numerator
 int denominator
 **


 **
 Function calculates greatest common divisor between two integers
 friend int gcd(int n, int d)

 Pre-condition
 -int nr => numerator, int dr => denominator
 -Denominator > Numerator, Denominator and numerator both are not equal to 0
 Post-condition
 -Returns resulting value of gcd
 **


 **
 Function reduces unsimplified fractions to simplified fractions
 void reducefraction();

 Pre-condition
 -Evaluates absolute values of int numerator and int denominator
 -Divides numerator and denominator by gcdvalue to reduce fraction
 Post-condition
 -Fraction is stored in reduced form
 */

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <string>
#include "fraction.h"
using namespace std;

namespace cs2b_fraction {

fraction::fraction(int n, int d) {

    assert(d != 0);
    // Terminates program if denominator = 0.
    numerator = n;
    denominator = d;

    reducefraction();
}




/*Returns the greatest common divisor between two numbers (int nr) and (int dr)*/
int gcd(int nr, int dr) {

    int t = 0;
    while (dr > nr && dr != 0 && nr != 0) {
        dr = dr % nr;
        if (dr != 0) {
            t = nr;
            nr = dr;
            dr = t;
        }
    }
    return nr;    //gcd value
}




/*Reduces unsimplified fractions into reduced form by dividing
 numerator and denominator by gcd.*/

void fraction::reducefraction() {

    if (denominator < 0) {     //Adjustment to represent negative fractions
        denominator *= -1;
        numerator *= -1;
    }
    if (abs(denominator) > abs(numerator) && numerator != 0) {
        int gcdvalue = gcd(abs(numerator), abs(denominator));
        numerator /= gcdvalue;
        denominator /= gcdvalue;
    }
}




/*Prints correct format of fraction to console */

ostream& operator<<(ostream& out, const fraction& f) {

    if (f.denominator == 1 || f.numerator == 0) {     // Outputs whole number
        out << f.numerator;
    } else {
        if (abs(f.numerator) < f.denominator) { // Outputs fraction in simplified form
            out << f.numerator << "/" << f.denominator;
        } else {
            out << f.numerator / f.denominator;
            if (f.numerator % f.denominator != 0) { // Outputs fraction in mixed form
                out << "+" << abs(f.numerator % f.denominator) << "/"
                        << f.denominator;
            }
        }
    }
    return out;
}




/*Operator overloading function '<' compares two objects f1, f2 of type fraction
 or one object of type fraction and other of type integer */

bool operator<(const fraction& f1, const fraction& f2) {

    bool fValue = false;

    int left = f1.numerator * f2.denominator;
    int right = f2.numerator * f1.denominator;

    if (left < right) {
        fValue = true;
    }
    return fValue;
}




/*Operator overloading function '<=' compares two objects f1, f2 of type fraction
 or one object of type fraction and other of type integer */

bool operator<=(const fraction& f1, const fraction& f2) {

    if (f1 == f2) {
        return true;
    }
    return (f1 < f2);
}




/*Operator overloading function '>' compares two objects f1, f2 of type fraction
 or one object of type fraction and other of type integer */

bool operator>(const fraction& f1, const fraction& f2) {

    return !((f1 < f2) || (f1 == f2));
}




/*Operator overloading function '>=' compares two objects f1, f2 of type fraction
 or one object of type fraction and other of type integer */

bool operator>=(const fraction& f1, const fraction& f2) {

    return !(f1 < f2);
}




/*Operator overloading function '==' compares two objects f1, f2 of type fraction
 or one object of type fraction and other of type integer */

bool operator==(const fraction& f1, const fraction& f2) {

    bool fValue = false;

    int left = f1.numerator * f2.denominator;
    int right = f2.numerator * f1.denominator;

    if (left == right) {
        fValue = true;
    }
    return fValue;
}




/*Operator overloading function '!=' compares two objects f1, f2 of type fraction
 or one object of type fraction and other of type integer */

bool operator!=(const fraction& f1, const fraction& f2) {

    return !(f1 == f2);
}




/*Operator overloading function adds two objects f1, f2 of type fraction or
 one object of type fraction and other of type integer */

fraction operator+(const fraction& f1, const fraction& f2) {

    fraction f;

    f.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    f.denominator = f1.denominator * f2.denominator;

    f.reducefraction();
    return f;
}




/*Operator overloading function subtracts two objects f1, f2 of type fraction or
 one object of type fraction and other of type integer */

fraction operator-(const fraction& f1, const fraction& f2) {

    fraction f;

    f.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    f.denominator = f1.denominator * f2.denominator;

    f.reducefraction();
    return f;
}




/*Operator overloading function multiplies two objects f1, f2 of type fraction or
 one object of type fraction and other of type integer */

fraction operator*(const fraction& f1, const fraction& f2) {

    fraction f;

    f.numerator = f1.numerator * f2.numerator;
    f.denominator = f1.denominator * f2.denominator;

    f.reducefraction();
    return f;
}




/*Operator overloading function divides two objects f1, f2 of type fraction or
 one object of type fraction and other of type integer */

fraction operator/(const fraction& f1, const fraction& f2) {

    fraction f;

    f.numerator = f1.numerator * f2.denominator;
    f.denominator = f1.denominator * f2.numerator;

    f.reducefraction();
    return f;
}




/*Operator overloading function "+=" between two objects of type fraction
 or between type fraction f1 and other of type integer*/

fraction fraction::operator+=(const fraction& f1) {

    *this = *this + f1;
    return *this;
}




/*Operator overloading function "-=" between two objects of type fraction
 or between type fraction f1 and other of type integer*/

fraction fraction::operator-=(const fraction& f1) {

    *this = *this - f1;
    return *this;
}




/*Operator overloading function "=" between two objects of type fraction
 or between type fraction f1 and other of type integer*/

fraction fraction::operator*=(const fraction& f1) {

    *this = *this * f1;
    return *this;
}




/*Operator overloading function "/=" between two objects of type fraction
 or between type fraction f1 and other of type integer*/

fraction fraction::operator/=(const fraction& f1) {

    *this = *this / f1;
    return *this;
}




/*Operator overloading function '++' for prefix increment*/
fraction fraction::operator++(int) {

    fraction temp(numerator, denominator);
    *this += 1;
    return temp;
}




/*Operator overloading function '++' for postfix increment*/
fraction fraction::operator++() {

    *this += 1;
    return *this;
}




/*Operator overloading function '++' for prefix decrement*/
fraction fraction::operator--(int) {

    fraction temp(numerator, denominator);
    temp -= 1;
    return temp;
}




/*Operator overloading function '++' for postfix decrement*/
fraction fraction::operator--() {

    *this -= 1;
    return *this;
}

}
