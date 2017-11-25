//============================================================================
// Name        : Recursion2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cctype>
#include <cstdlib>

using namespace std;

/*Function evaluates string entered by the user and determines if the string is a palindrome */
bool isAPalindrome(char *inString, int firstLetter, int lastLetter);

int main() {

    char inString[128];
    bool quit = false;

    /*Exits program when the user enters "quit" */
    while (!quit) {

        cout << "Enter a String: ";
        cin.getline(inString, 127);

        if (strcmp(inString, "quit") == 0) {

            quit = true;

        } else if (isAPalindrome(inString, 0, strlen(inString) - 1)) {

            cout << inString << " is a palindrome." << endl;

        } else {

            cout << inString << " is not a palindrome." << endl;
        }
    }

    return 0;
}




bool isAPalindrome(char *inString, int first, int last) {

    /*Ignores white space and punctuation while evaluating string */
    if (first != last) {

        while (((isspace(inString[first]) || ispunct(inString[first])) && (first < last))) first++;

        while (((isspace(inString[last]) || ispunct(inString[last]))  && (first < last))) last--;
    }

    /*Temporarily converts lowercase character to upper case for evaluation*/
    if (toupper(inString[first]) == toupper(inString[last])) {

        if ((first == last) || ((first + 1) == last)) {

            return true;

        } else {

            return isAPalindrome(inString, first + 1, last - 1);

        }
    }

    return false;
}
