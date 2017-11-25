/*
 The file is a header file -  mystring.h

 Created on: May 5th, 2013, Author: Visalakshi Gopalakrishnan
 Class: CS 2B, Instructor name: Dave Harden.

 This file has the base class myString under namespace cs2b_mystring and handles
 string manipulation operations.

 Class supports functions to perform the following:-
 -Testing basic string creation and printing
 -Reading from file word by word
 -Reading from file line by line
 -Testing access to characters(using const and non-const)
 -Testing relational comparison operations between myStrings and between
  myStrings and char.
 -Testing concatenation between myStrings, and between myString and char
  using overload binary + operator and short hand assignment operator
 -Testing deep copying using the copy constructor or the operator = overload

 Client Input
 ============
 -Array of objects of type myString
 -myString accepts string literal as input

 Output
 ======
 -String manipulation based on different operations

 **

 **
 Public functions
 ================

 myString();
 Default Constructor function

 Pre-condition
     -Evaluates object of type myString
 Post-condition
     -Creates a null string and assigns it to object of type myString
 **


 **
 ~myString();
 Default destructor function.

 Pre-condition
     -Called when objects of type myString are destroyed or deleted
 Post-condition
     -cleans up or de-allocates memory from the heap

 **


 **
 myString(const char* inString);
 Constructor function

 Pre-condition
     -Takes input pointer to a character
     -Specify length of array to be just big enough to store the C-string inString
     -Use new to allocate memory for a C-string.
 Post-condition
     -Copy information into a C-string pointed to by cString

 **


 **
 myString(const myString& right);
 Copy Constructor function

 Pre-condition
     -Pass an myString object to the function using pass-by-reference
     -Allocates specific length of array to store the C-string inString
     -Make a copy of an object, when the assignment operator is not being used
 Post-condition
     -Create a new object without modifying an existing object
     -Make deep copy of the object

 **


 **
 myString operator=(const myString& right);
 Copy function

 Pre-condition
     -Make a copy of an object, when the assignment operator is called
     -In case of self-assignment, the value of the calling object does not get destroyed
     -Deletes unused memory from heap
     -Allocates specific length of array to store the C-string inString
 Post-condition
     -Returns value assigned to calling object
     -Make deep copy of the object

 **


 **
 friend ostream& operator<<(ostream& out, const myString& source);
 Operator overloading function for output stream

 Pre-condition
     -Reads character of object into stream
 Post-condition
     -Prints out character

 **


 **
 friend istream& operator>>(istream& in, myString& file);
 extraction operator (>>) function

 Pre-condition
     -Should not skip any leading spaces
     -Read characters into the string to the first whitespace character
     -Each string read by function will consist of no more than 127 characters
 Post-condition
     -Read into a myString from a stream

 **


 **
 void read(istream& in, char delimiter);
 Read function

 Pre-condition
     -Take two arguments, a stream and the delimiting character
     -Should not skip any leading spaces
     -Read characters into the string to the first whitespace character
     -Each string read by function will consist of no more than 127 characters
 Post-condition
     -Read into a myString from a stream based on clients delimiting condition

 **


 **
 char operator[](int index) const;
 char& operator[](int index);
 Overload square brackets [ ] operator function

 Pre-condition
     -Allow direct access to the individual characters of the string
     -Should range-check and assert if the index is out of bounds
 Post-condition
     -Const version that allows read access to the chars
     -Non-const version that returns the client a reference to the char
      so they can change the value.

 **


 **
 int length();
 int length() const;
 Length function

 Pre-condition
     -Called when using Overload square brackets [ ] operator function
 Post-condition
     -Returns number of character in the string

 **


 **
 Operator overloading functions for relational operators
 friend bool operator ==(const myString& s1, const myString& s2);
 friend bool operator !=(const myString& s1, const myString& s2);
 friend bool operator <(const myString& s1, const myString& s2);
 friend bool operator <=(const myString& s1, const myString& s2);
 friend bool operator >(const myString& s1, const myString& s2);
 friend bool operator >=(const myString& s1, const myString& s2

 Pre-condition
     -Compare myString objects to other myStrings as well as myStrings to char *s
      myStrings or char * should be able to appear on either side of the comparison operator
     -Checks if the contents of rhs and  lhs equal
     -Checks each character in lhs has equivalent character in rhs at the same position
     -Compares the contents of lhs and rhs lexicographically
 Post-condition -
     -Returns true or false, based on relational operator evaluation

 **


 **
 friend myString operator+(const myString& s1, const myString& s2);
 binary + operator overloading function

 Pre-condition
     -Perform string concatenation
     -Either myString objects or char * can appear on either side of the binary +
 Post-condition -
     -Returns the resulting string concatenation

 **


 **
 myString operator+=(const myString& s2);
 Operator overloading function for shorthand operator

 Pre-condition
     -Shorthand += to combine concatenation and assignment
     -Either myString objects or char * can appear on the right hand side of the +=.
     -Only myStrings can be on the left-hand side of a += operation.
 Post-condition -
     -Returns the resulting string concatenation

 **


 */

#ifndef MYSTRING_H_
#define MYSTRING_H_

#include <iostream>
using namespace std;

namespace cs2b_mystring {

    class myString {
    public:
        myString();
        ~myString();
        myString(const char* inString);
        myString(const myString& right);
        myString operator=(const myString& right);
        friend ostream& operator<<(ostream& out, const myString& source);
        friend istream& operator>>(istream& in, myString& file);
        void read(istream& in, char delimiter);
        char operator[](int index) const;
        char& operator[](int index);
        int length();
        int length() const;
        friend bool operator ==(const myString& s1, const myString& s2);
        friend bool operator !=(const myString& s1, const myString& s2);
        friend bool operator <(const myString& s1, const myString& s2);
        friend bool operator <=(const myString& s1, const myString& s2);
        friend bool operator >(const myString& s1, const myString& s2);
        friend bool operator >=(const myString& s1, const myString& s2);
        friend myString operator+(const myString& s1, const myString& s2);
        myString operator+=(const myString& s2);

    private:

        char * cString;

    };
}

#endif /* MYSTRING_H_ */
