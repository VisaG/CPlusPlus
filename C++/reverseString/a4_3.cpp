//============================================================================
// Name        : Recursion3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

using namespace std;

/*Function sorts numbers in ascending order*/
void sortAscendingOrder(int *numArray, int firstIndex, int lastIndex);

/*Function finds smallest number*/
void findSmallestNumber(int *numArray, int firstIndex, int lastIndex);

/*Prints list of numbers*/
void printArray(int *numArray, int size);

int main() {

    int numArray[] = { 1, 112, 1221, 4, 98, 27, 15, 23, 44, 7, 8, 11, -2 };
    int sizeOfArray = 13;

    cout << "List of unsorted numbers ";
    printArray(numArray, sizeOfArray);
    cout << endl;

    sortAscendingOrder(numArray, 0, sizeOfArray - 1);
    cout << "List of numbers sorted in ascending order ";
    printArray(numArray, sizeOfArray);
    cout << endl;

    return 0;
}



/*Finds smallest integer from the Array at the given index */
void findSmallestNumber(int *numArray, int *firstIndex, int lastIndex) {

    int temp;

    for (int counter = *firstIndex; counter < lastIndex; counter++) {

        if (numArray[*firstIndex] > numArray[counter + 1]) {

            temp = numArray[*firstIndex];
            numArray[*firstIndex] = numArray[counter + 1];
            numArray[counter + 1] = temp;
        }
    }

    (*firstIndex)++;

}




/*Calls function recursively untill all numbers are in ascending order*/
void sortAscendingOrder(int *numArray, int firstIndex, int lastIndex) {

    findSmallestNumber(numArray, &firstIndex, lastIndex);

    if (firstIndex < lastIndex) {

        sortAscendingOrder(numArray, firstIndex, lastIndex);
    }
}




void printArray(int numberArray[], int size) {

    for (int i = 0; i < size; i++) {

        cout << numberArray[i] << ' ';

    }

}
