/*

 Name:Visalakshi Gopalakrishnan
 Date:June 18 2013
 Assignment Number:CS2B a6
 Instructor:Dave Harden
 File: dynamicTemplateArray.h

 This is the header file dynamicTemplateArray.h. This is the interface
 for the class dynamicTemplateArray. Objects of this type are partially filled
 arrays with base of type <T>

 Objective
 ==========
 Template based class for implementation for all data types.
 Sets size of array
 Adds elements to the array
 Delete specified element from the array
 Gets element of specified index from array

 **

 **
 Public functions
 ================

 Default Constructor.
 dynamicTemplateArray();
 Post-condition
 -Object is set to null
 -Size set to zero
 **


 **
 Copy Constructor
 dynamicTemplateArray(const dynamicTemplateArray<T>& rightSide);
 Post-condition
 -Makes copy of the input object's dynamicArray
 **


 **
 Assignment operator
 dynamicTemplateArray& operator =(const dynamicTemplateArray<T>& rightSide);
 Post-condition
 -Objects of dynamicArray is properly copied to the target object
 **


 **
 int getSize() const;

 Post-condition
 -Allows access to get the value of private member "size"
 -Returns size of array

 **


 **
 void addEntry(T newString);

 Pre-condition
 -The array is not filled
 Post-condition
 -Fills arrays with base of type <T>
 **


 **
 bool deleteEntry(T input);

 Pre-condition
 -Takes input of type<T>
 -Search array for input of type<T>
 Post-condition
 -Returns false if same input base of type<T> is not found
 (does not delete anything from the array)
 -Returns true if same input base of type<T> is found.
 -Delete input, copy all elements except the input into array.
 -Return new array
 **


 **
 T getEntry(int index) const;

 Pre-condition
 -Takes integer as input
 Post-Condition
 -Returns the base of type<T> at that index in dynamicArray
 -Asset index is within dynamicArray's bounds
 **


 **
 Destructor function
 ~dynamicTemplateArray();
 Post-Condition
 -Frees up memory allocated to dynamicArray
 **
 */

#ifndef DYNAMICTEMPLATEARRAY_H_
#define DYNAMICTEMPLATEARRAY_H_

#include <iostream>
using namespace std;

namespace dynamicTemplate {

template<class T>
class dynamicTemplateArray {

public:

    dynamicTemplateArray();
    dynamicTemplateArray(
            const dynamicTemplateArray<T>& rightSide);
    ~dynamicTemplateArray();
    dynamicTemplateArray& operator =(
            const dynamicTemplateArray<T>& rightSide);
    int getSize() const;
    void addEntry(T newElement);
    bool deleteEntry(T input);
    T getEntry(int index) const;

private:

    T *dynamicArray;
    int size;

};
}

#endif /* DYNAMICTEMPLATEARRAY_H_ */
