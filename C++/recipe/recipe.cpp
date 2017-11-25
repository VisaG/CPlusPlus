/*
 This file is implementation file :- recipe.cpp

 The interface for class measure is in the header file :- recipe.h

 CLASS INVARIANT:

 Following are the private data members in this class.

 int numIngredients;
 Number of ingredients

 Ingredient *ingredients;
 Array of ingredients

 cs2b_fraction::fraction servings;
 Servings stored as fraction

 cs2b_mystring::myString name;
 name stored as myString

 cs2b_mystring::myString instructions;
 instructions stored as myString
 **
 */

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <string>
#include "recipe.h"

using namespace std;


// Default Constructor
Recipe::Recipe() {

    numIngredients = 1;
    ingredients = new Ingredient[1];

}




// Destructor
Recipe::~Recipe() {

    delete[] ingredients;
}




Recipe::Recipe(const Recipe& right) {

    ingredients = new Ingredient[right.numIngredients];

    for (int i = 0; i < right.numIngredients; i++) {
        ingredients[i] = right.ingredients[i];
    }

    name = right.name;
    instructions = right.instructions;
    servings = right.servings;
    numIngredients = right.numIngredients;

}




// Copy function using operator overload '='
Recipe Recipe::operator=(const Recipe &right) {

    if (this != &right) {
        delete[] ingredients;
        ingredients = new Ingredient[right.numIngredients];

        for (int i = 0; i < right.numIngredients; i++) {
            ingredients[i] = right.ingredients[i];
        }

        name = right.name;
        instructions = right.instructions;
        servings = right.servings;
        numIngredients = right.numIngredients;
    }

    return *this;

}




//Correctly adjust serving size based on user input
//Scales the ingredient measure and unit based adjusted serving size

Recipe Recipe::operator*(const cs2b_fraction::fraction &right) {

    cs2b_fraction::fraction scale = right/servings;
    for (int i = 0; i < numIngredients; i++) {
        //right/servings;
        ingredients[i] *= scale; // Scales serving size if > 1 according to user input
    }
    servings = right;
    return *this;
}




ostream& operator<<(ostream& out, const Recipe &printMe) {

    out << printMe.name << endl;
    out << printMe.servings << " servings" << endl << endl;
    //out << printMe.numIngredients << " ingredients " << endl;

    for (int i = 0; i < printMe.numIngredients; i++) {

        out << printMe.ingredients[i] << endl;
    }

    out << endl << printMe.instructions << endl;

    return out;
}




istream& operator>>(istream &in, Recipe &readMe) {
    cs2b_mystring::myString temp;
    readMe.name.read(in, '\n');
    in >> readMe.servings;
    in.ignore(10000, '\n');
    in >> readMe.numIngredients;
    delete[] readMe.ingredients;
    readMe.ingredients = new Ingredient[readMe.numIngredients];
    in.ignore(10000, '\n');
    for (int count = 0; count < readMe.numIngredients; count++) {
        in >> readMe.ingredients[count];
    }
    in.ignore(10000, '\n');
    readMe.instructions = "";
    temp.read(in, '\n');
    while (temp != "") {
        readMe.instructions = readMe.instructions + temp + "\n";
        temp.read(in, '\n');
    }
    return in;
}




cs2b_mystring::myString Recipe::getName() {

    return name;

}

