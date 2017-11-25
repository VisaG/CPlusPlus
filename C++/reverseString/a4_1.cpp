//============================================================================
// Name        : Recursion.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

/* Recursive function called by reverseCstring */
void reverseWithinBounds(char *list, int lowerBound, int upperBound);

/* Function to reverse a string */
void reverseCstring(char *str);

int main() {

    char phrase[] = {"C++ is fun"};

    cout << "Before reverse = " << phrase << endl;

    reverseCstring(phrase);

    cout << "After reverse = " << phrase;

    return 0;
}



void reverseWithinBounds(char *list, int lowerBound, int upperBound) {

    char temp;

    if (lowerBound < upperBound) {

        temp = list[lowerBound];
        list[lowerBound] = list[upperBound];
        list[upperBound] = temp;
        lowerBound++;
        upperBound--;

        reverseWithinBounds(list, lowerBound, upperBound);
    }
}




void reverseCstring(char *str) {

    int lowerBound = 0;
    int upperBound = strlen(str) - 1;

    reverseWithinBounds(str, lowerBound, upperBound);

}
