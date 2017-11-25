/*
 Name:Visalakshi Gopalakrishnan
 Date:May 20 2013
 Assignment Number:CS2B a3
 Instructor:Dave Harden
 Phase 4: Client program
 File: recipeclient.cpp
 ,
 The interface for class measure is in the header file :- ingredient.h, measure.h,
 recipe.h, fraction.h, mystring.h

 The program will read in the list of recipes from the input file into an array of recipes.
 There will be no more than 100 recipes.
 The program should then enter a loop where a list of choices is printed, the user is asked
 to enter a recipe number and a number of servings, and then the recipe is converted appropriately
 and printed out. If the user requests 0 servings, the recipe will not be printed.
 After User types a negative number to quit, the program should print out the recipes
 in their original form.
 */

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <string>
#include "ingredient.h"
#include "measure.h"
#include "recipe.h"
#include "fraction.h"
#include "mystring.h"

using namespace std;

/*Max size of array (recipes)*/
const int LIST_OF_RECIPES = 100;

/*Reads objects of recipe in to array*/
int readAllRecipes(Recipe *recipeList);

int main() {

    Recipe recipeList[LIST_OF_RECIPES];
    int numberOfRecipes = 0;
    int choiceStr;
    cs2b_fraction::fraction servSize;


    /*Selection true till user enters negative number to quit or enters
     serving size = 0 or when the choice of recipe is more than the
     number of recipes stored*/

    bool selection = true;

    numberOfRecipes = readAllRecipes(recipeList);

    while (selection) {

        cout << "Please select a recipe:" << endl;

        for (int i = 0; i < numberOfRecipes; i++) {

            cout << "   " << i << ". " << recipeList[i].getName() << endl;
        }

        cout << "Enter choice (negative number to quit) " << ">> ";
        cin >> choiceStr;

        /*Exits program if user inputs negative number or choice > recipe selection*/
        if (choiceStr < 0 || choiceStr > (numberOfRecipes - 1)) {
            selection = false;
        }

        if (selection) {

            cout << "How many servings of " << recipeList[choiceStr].getName()
                    << "? ";
            cin >> servSize;

            /*Exits program if serving size = 0 */
            if (servSize > 0) {
                Recipe temp;
                temp = recipeList[choiceStr];
                temp = temp * servSize;
                cout << temp;

            } else {

                selection = false;
            }
        }
    }

    /*Prints all recipes from file in original format */
    for (int count = 0; count < numberOfRecipes; count++) {
        cout << recipeList[count];
    }

    return 0;

}




/*Reads object of recipe in to array*/

int readAllRecipes(Recipe *recipeList) {
    Recipe temp;
    ifstream inFile;
    int count = 0;

    inFile.open("recipe.txt");

    if (inFile.is_open()) {
        while (inFile.good() && count < LIST_OF_RECIPES && !inFile.eof()) {

            inFile >> temp;
            recipeList[count] = temp;
            count++;
        }

        inFile.close();
    }

    return count;
}



