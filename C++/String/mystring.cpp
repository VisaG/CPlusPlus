/** This file is implementation file :- fraction.cpp

 Created on: May 5th, 2013, Author: Visalakshi Gopalakrishnan
 Class: CS 2B, Instructor name: Dave Harden.

 The interface for class fraction is in the header file :- fraction.h

 The methods below perform the following operations

     -Testing basic String creation & printing
     -Reading myStrings from file word by word
     -Reading myStrings from file line by line
     -Testing access to characters (using const)
     -Testing access to characters (using non-const)
     -Testing relational operators between myStrings
     -Testing relations between myStrings and char *
     -Testing concatentation on myStrings
     -Testing concatentation between myString and char
     -Testing shorthand concat/assign on myStrings
     -Testing shorthand concat/assign using char *
     -Testing copy constructor and operator= on myStrings

 **
 Private Data Members
 ====================
  char * cString;

 **
*/

#include <fstream>
#include <cctype>      // for toupper()
#include <string>
#include <string.h>    // for strchr(), strstr(), etc.
#include <cassert>
#include <iostream>
#include "mystring.h"
using namespace std;

namespace cs2b_mystring {


    /* Default Constructor function */

    myString::myString() {

        cString = new char[1];
        strcpy(cString, "");
    }




    /* Constructor function */

    myString::myString(const char* instring) {

        cString = new char[strlen(instring) + 1];
        strcpy(cString, instring);
    }




    /* Copy Constructor function */

    myString::myString(const myString& right) {

        cString = new char[strlen(right.cString) + 1];
        strcpy(cString, right.cString);
    }




    /* Default Destructor function */

    myString::~myString() {

        delete[] cString;
    }




    /* Copy function using operator overload '=' */

    myString myString::operator=(const myString& right) {

        if (this != &right) {
            delete[] cString;
            cString = new char[strlen(right.cString) + 1];
            strcpy(cString, right.cString);
        }

        return *this;
    }




    /* Operator overloading function for output stream */

    ostream& operator<<(ostream& out, const myString& source) {

        out << source.cString;
        return out;
    }




    /* extraction operator (>>) function */

    istream& operator>>(istream& in, myString& mStr) {

        while (isspace(in.peek())) {
            in.ignore();
        }

        char temp[128];
        in.getline(temp, 127, ' ');

        int sLength = strlen(temp);

        delete[] mStr.cString;
        mStr.cString = new char[sLength + 1];

        if (temp[sLength - 1] == '\n') {  // Eliminate new line character
            temp[sLength - 1] = '\0';
        }

        strcpy(mStr.cString, temp);

        return in;
    }




    /* Read function */

    void myString::read(istream& in, char delimiter) {

        char temp[128];
        in.getline(temp, 127, delimiter);

        myString s(temp);

        *this = s;
    }




    /* Overload square brackets [ ] operator function
       allows read access to the chars */

    char myString::operator[](int index) const {
        assert(index >= 0 && index < strlen(cString));
        return cString[index];
    }




    /* Overload square brackets [ ] operator function returns the client
       a reference to the char so they can change the value. */

    char& myString::operator[](int index) {
        assert(index >= 0 && index < strlen(cString));
        return cString[index];
    }




    /* Length function returns number of character in the string */

    int myString::length() {

        return strlen(cString);
    }




    /* Const - Length function returns number of character in the string */

    int myString::length() const {

        return strlen(cString);
    }




    /* Operator overloading function '==' */
    bool operator ==(const myString& s1, const myString& s2) {

        if (strcmp(s1.cString, s2.cString) == 0) {

            return true;
        }
        return false;
    }




    /* Operator overloading function '!=' */

    bool operator !=(const myString& s1, const myString& s2) {

        return !(s1 == s2);
    }




    /* Operator overloading function '<' */

    bool operator <(const myString& s1, const myString& s2) {

        if (strcmp(s1.cString, s2.cString) < 0) {

            return true;
        }

        return false;
    }




    /* Operator overloading function '<=' */

    bool operator <=(const myString& s1, const myString& s2) {

        if (strcmp(s1.cString, s2.cString) <= 0) {

            return true;
        }

        return false;
    }




    /* Operator overloading function '>' */

    bool operator >(const myString& s1, const myString& s2) {

        return !(s1 <= s2);
    }




    /* Operator overloading function '>=' */

    bool operator >=(const myString& s1, const myString& s2) {

        return !(s1 < s2);
    }




    /* binary + operator overloading function */

    myString operator+(const myString& s1, const myString& s2) {

        myString temp;

        temp.cString = new char[strlen(s1.cString) + strlen(s2.cString) + 1];

        strcpy(temp.cString, s1.cString);
        strcat(temp.cString, s2.cString);

        return temp;
    }




    /* Operator overloading function for shorthand operator */

    myString myString::operator+=(const myString& s2) {

        *this = *this + s2;
        return *this;

    }
}
