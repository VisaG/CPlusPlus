/*  THIS FILE IS HEADER FILE :- fraction.h

 Created on: Apr 16, 2013, Author: visalakshi Gopalakrishnan
 Class: CS 2B, Instructor name: Dave Harden.

 This file has the base class fraction under namespace cs2b_fraction and handles
 objects of type fraction and integers.

 Class supports functions using operator overloading to perform the following:-
 -Comparison between fractions or between fraction and integer values.
 -Evaluates relational operators
 -Performs basic arithmetic function between fractions or between
 fraction and integer values.
 -Perform shorthand arithmetic assignment operators between fractions
 or between fraction and integer values.
 -Performs increment and decrement operation between fractions or
 between fraction and integer

 Client Input
 -Type integers for numerator and denominator. Can be in the following format
 -Input Format
 Negative fraction (eg -9/13)
 positive fractions (eg 9/13)
 Unsimplified fractions (eg -21/14 or 50/100)

 Output of fraction is always in reduced form
 -whole numbers (eg -9 or 9, denominator = 1)
 -Simplified fractions (eg 2/6 = 1/3)
 -Improper fractions as a mixed number with a + sign (eg 5/3 = 1+2/3)
 -Negative fractions with leading minus sign (eg -9/3)
 **

 **
 Public functions:-

 fraction(int n = 0, int d = 1)
 Constructor function takes a single int argument and treats that
 single argument numerator

 Pre-condition
 -Takes integer values as parameter of function.
 -int n = numerator and int d = denominator.
 -Denominator cannot be 0.
 Post-condition
 -If denominator = 0, terminates the program.
 -Stores reduced fractions.
 **


 **
 friend ostream& operator<<(ostream& out, const fraction& f)
 Operator overloading function for output stream

 Pre-condition
 -Evaluates absolute value of numerator and denominator of reduced fraction
 Post-condition
 -Prints fractions always in reduced form of following types
 -whole numbers (eg -9 or 9, denominator = 1)
 -Simplified fractions (eg 2/6 = 1/3)
 -Improper fractions as a mixed number with a + sign (eg 5/3 = 1+2/3)
 -Negative fractions with leading minus sign (eg -9/3)
 **


 **
 Operator overloading functions for relational operators
 friend bool operator<(const fraction& f1, const fraction& f2);
 friend bool operator<=(const fraction& f1, const fraction& f2);
 friend bool operator==(const fraction& f1, const fraction& f2);
 friend bool operator>(const fraction& f1, const fraction& f2);
 friend bool operator>=(const fraction& f1, const fraction& f2);
 friend bool operator!=(const fraction& f1, const fraction& f2);

 Pre-condition
 -Fraction should be in  simplified (reduced) form for evaluation.
 -Either fractions or integers can appear on either side of the binary comparison operator
 Post-condition -
 -Returns true or false, based on relational operator evaluation
 **


 **
 Operator overloading functions for arithmetic operators
 friend fraction operator+(const fraction& f1, const fraction& f2);
 friend fraction operator-(const fraction& f1, const fraction& f2);
 friend fraction operator*(const fraction& f1, const fraction& f2);
 friend fraction operator/(const fraction& f1, const fraction& f2);

 Pre-condition
 -Fraction should be in  simplified (reduced) form for evaluation.
 -Either fractions or integers can appear on either side of the binary comparison operator
 Post-condition -
 -Returns the resulting fraction based on arithmetic operation in reduced form
 **


 **
 Operator overloading functions for shorthand arithmetic operators
 fraction operator+=(const fraction& f1);
 fraction operator-=(const fraction& f1);
 fraction operator*=(const fraction& f1);
 fraction operator/=(const fraction& f1);

 Pre-condition
 -Fraction should be in  simplified (reduced) form for evaluation.
 -Either fractions or integers can appear on either side of the binary comparison operator
 Post-condition -
 -Returns the resulting fraction based on arithmetic operation in reduced form
 **


 **
 Operator overloading functions for postfix and prefix operators
 fraction operator++();
 fraction operator++(int);
 fraction operator--();
 fraction operator--(int);

 Pre-condition
 -Fraction should be in  simplified (reduced) form for evaluation.
 -Either fractions or integers can appear on either side of the binary comparison operator
 Post-condition -
 -Returns the resulting fraction based on arithmetic operation in reduced form
 */

#ifndef FRACTION_H_
#define FRACTION_H_
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace cs2b_fraction {

class fraction {

private:

    int numerator;
    int denominator;
    friend int gcd(int n, int d);
    void reducefraction();

public:

    fraction(int n = 0, int d = 1);
    friend ostream& operator<<(ostream& out, const fraction& f);
    friend bool operator<(const fraction& f1, const fraction& f2);
    friend bool operator<=(const fraction& f1, const fraction& f2);
    friend bool operator==(const fraction& f1, const fraction& f2);
    friend bool operator>(const fraction& f1, const fraction& f2);
    friend bool operator>=(const fraction& f1, const fraction& f2);
    friend bool operator!=(const fraction& f1, const fraction& f2);
    friend fraction operator+(const fraction& f1, const fraction& f2);
    friend fraction operator-(const fraction& f1, const fraction& f2);
    friend fraction operator*(const fraction& f1, const fraction& f2);
    friend fraction operator/(const fraction& f1, const fraction& f2);
    fraction operator+=(const fraction& f1);
    fraction operator-=(const fraction& f1);
    fraction operator*=(const fraction& f1);
    fraction operator/=(const fraction& f1);
    fraction operator++();
    fraction operator++(int);
    fraction operator--();
    fraction operator--(int);

};

}

#endif /* FRACTION_H_ */
