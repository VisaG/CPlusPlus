/*
 Name:Visalakshi Gopalakrishnan
 Date:May 20 2013
 Assignment Number:CS2B a3
 Instructor:Dave Harden
 Phase 3: Recipe Class
 File: recipe.h

 The Recipe class Phase Three of recipe program will consist of a name,
 an array of ingredients, the instructions, and other data members.
 Both the name and the instructions are stored as myString objects.
 There is no limit on the number of ingredients in the recipe.


 Output
 ======
 Selection of recipe
 A line asking choice of recipe
 A line asking number of servings
 A line indicating the name of the recipe
 A line indicating how many servings the recipe makes
 A line indicating how many ingredients are in the recipe
 A line for each ingredient
 A blank line
 One or more lines of recipe instructions
 A blank line at the end to mark the end of the instructions
 Re-selection process till user enters negative to quit.

 **

 **
 Public functions
 ================

 friend ostream& operator<<(ostream& out, const Measure &printMe);

 Pre-condition
 -The object ostream out is ready for writing
 Post-condition
 -The contents of "printMe" (name, servings, numIngredient, ingredients, instruction)
 have been inserted into "out".

 **


 **
 friend istream& operator>>(istream& in, MyString &readMe);

 Pre-condition
 -The object istream in is ready for reading.
 Post-condition
 -The readMe is filled with name, servings, numIngredient, ingredients, instruction
 **


 **
 Recipe();
 Post-condition
 -Ingredient object is created and initialized to array.
 -Number of ingredients is initialized

 **


 **
 Recipe(const Recipe &right);
 Post-condition
 -A copy of "right" is stored in the calling object

 **
 Recipe operator=(const Recipe& right);
 Post-condition
 -Right object is copied to the returning recipe object

 **


 **
 Recipe operator*(const cs2b_fraction::fraction &right);

 Pre-condition
 -Calls operator overload of cs2b_fraction fraction class.
 Post-condition
 -Assigns the serving size to the left operand. Calculates the scale
 for the ingredients based on the serving size.
 -Returns the modified Recipe object.

 **


 **
 cs2b_mystring::myString getName();

 Post-condition
 -Allows access to get the value of private member "name"
 -Returns myString object

 **
 */

#ifndef RECIPE_H_
#define RECIPE_H_

#include <iostream>
#include "mystring.h"
#include "fraction.h"
#include "measure.h"
#include "ingredient.h"

using namespace std;

class Recipe {
public:
    friend ostream& operator<<(ostream& out, const Recipe &printMe);
    friend istream& operator>>(istream& in, Recipe &readMe);
    Recipe();
    ~Recipe();
    Recipe(const Recipe &right);
    Recipe operator=(const Recipe& right);
    Recipe operator*(const cs2b_fraction::fraction &right);
    cs2b_mystring::myString getName();

private:
    int numIngredients;
    Ingredient *ingredients;
    cs2b_fraction::fraction servings;
    cs2b_mystring::myString name;
    cs2b_mystring::myString instructions;

};

#endif /* RECIPE_H_ */
