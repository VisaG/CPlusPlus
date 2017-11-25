/*Name:Visalakshi Gopalakrishnan
 Date:June 27 2013
 Assignment Number:CS2B a8
 Instructor:Dave Harden
 File: exception.cpp

 This is an implementation file exception.cpp*/



#include <iostream>
#include <string>
using namespace std;

class PopEmptyStackException
{
public:
    PopEmptyStackException() {}
    PopEmptyStackException(string theMessage): message(theMessage) {}
    string getMessage( ) const { return message; }
private:
    string message;
};


