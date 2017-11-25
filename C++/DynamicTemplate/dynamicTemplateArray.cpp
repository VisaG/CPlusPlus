/*
 Name:Visalakshi Gopalakrishnan
 Date:June 18 2013
 Assignment Number:CS2B a6
 Instructor:Dave Harden
 File: T.cpp

 This is an implementation file dynamicTemplateArray.cpp, of the template
 class<T>.
 The interface for this file is in the file dynamicTemplateArray.h

 */

#include <string>
#include <string.h>    // for strchr(), strstr(), etc.
#include <cassert>
#include <iostream>
#include <assert.h>
#include "dynamicTemplateArray.h"
using namespace std;

namespace dynamicTemplate {

/*Default constructor */
template<class T>
dynamicTemplateArray<T>::dynamicTemplateArray() {

    dynamicArray = NULL;
    size = 0;
}




/*Copy constructor */
template<class T>
dynamicTemplateArray<T>::dynamicTemplateArray(
        const dynamicTemplateArray<T>& rightSide) {

    size = rightSide.size;
    dynamicArray = new T[size];
    for (int i = 0; i < size; i++) {
        dynamicArray[i] = rightSide.dynamicArray[i];
    }
}




/*Destructor */
template<class T>
dynamicTemplateArray<T>::~dynamicTemplateArray() {
    if (size > 0) {
        delete[] dynamicArray;
    }
}




/*Assignment operator */
template<class T>
dynamicTemplateArray<T>& dynamicTemplateArray<
        T>::operator =(const dynamicTemplateArray& rightSide) {
    if (size != rightSide.size) {

        delete[] dynamicArray;
        dynamicArray = new T[rightSide.size];
    }

    size = rightSide.size;

    for (int i = 0; i < size; i++) {

        dynamicArray[i] = rightSide.dynamicArray[i];
    }

    return *this;
}




template<class T>
int dynamicTemplateArray<T>::getSize() const {

    return size;
}




template<class T>
void dynamicTemplateArray<T>::addEntry(
        T newElement) {

    /*Create newArray one element more than dynamicArray */
    T *newArray = new T[size + 1];

    /*Copy elements into newArray */
    for (int i = 0; i < size; i++) {
        newArray[i] = dynamicArray[i];
    }

    /*Add element at the end of newArray */
    newArray[size] = newElement;

    size++;

    delete[] dynamicArray;

    /*Set dynamicArray to newArray */
    dynamicArray = newArray;

}




template<class T>
bool dynamicTemplateArray<T>::deleteEntry(
        T input) {

    bool match = false;
    int matchIndex = 0;

    /*Find index of element to be deleted, if detected, match is set to true */
    for (int i = 0; (i < size && !match); i++) {
        if (dynamicArray[i] == input) {
            matchIndex = i;
            match = true;
        }
    }

    /*Copies everything except element of index(matchIndex) to be deleted */
    if (match) {

        /*Create newArray one element less than dynamicArray */
        T *newDynamicArray = new T[size - 1];

        /*Copy elements of dynamic array into newDynamicArray
          except the input element to be deleted */
        for (int i = 0, j = 0; i < size; i++) {
            if (i != matchIndex) {
                newDynamicArray[j] = dynamicArray[i];
                j++;
            }
        }

        delete[] dynamicArray;
        size--;

        /*Set dynamicArray to newDynamicArray */
        dynamicArray = newDynamicArray;
    }
    /*match = true, if input element matches element to be deleted
      match = false, if no match to the input element */
    return match;
}





template<class T>
T dynamicTemplateArray<T>::getEntry(
        int index) const {

    /*Asserts index is within bounds*/
    assert(index < size);

    return dynamicArray[index];
}
}
