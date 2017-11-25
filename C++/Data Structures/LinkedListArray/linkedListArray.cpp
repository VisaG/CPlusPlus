/*Name:Visalakshi Gopalakrishnan
 Date:June 27 2013
 Assignment Number:CS2B a7
 Instructor:Dave Harden
 File: linkedListArray.cpp

 */

#include <iostream>
#include <string>
#include <string.h>    // for strchr(), strstr(), etc.
#include <cassert>
using namespace std;
# include "linkedListArray.h"




/*Default Constructor*/
linkedListArray::linkedListArray() {

    list = NULL;
}



/*Function that returns index*/
linkedListArray::size_type linkedListArray::getSize() {

    int index = 0;
    node* tempNode = list;
    while (tempNode != NULL) {
        index++;
        tempNode = tempNode->next;
    }
    return index;

}




/*Function that gets data at that index*/
string linkedListArray::getEntry(int index) {

    int tempIndex = 0;
    node* currentptr = list;

    assert(index < this->getSize());

    while (currentptr != NULL && tempIndex != index) {
        currentptr = currentptr->next;
        tempIndex++;
    }

    if (currentptr != NULL) {

        return currentptr->data;
    }

}




/*Function adds data in new node */
void linkedListArray::addEntry(string newString) {

    node* temp = new node;
    temp->data = newString;
    temp->next = list;
    list = temp;

}




/*Function deletes data (node) */
bool linkedListArray::deleteEntry(string input) {
    bool found;
    if (list != NULL && list->data == input) {
        node* tempptr = list;
        list = list->next;
        delete tempptr;
        found = true;
    } else {

        node* currentData = list;
        node* prevData = list;

        while (currentData != NULL && currentData->data != input) {
            prevData = currentData;
            currentData = currentData->next;
        }

        if (currentData != NULL) {
            found = true;
            prevData->next = currentData->next;
            delete currentData;
        } else {
            found = false;
        }

    }
    return found;
}




/*Destructor*/
linkedListArray::~linkedListArray() {

    node* temp = list;
    while (temp != NULL) {
        list = list->next;
        delete temp;
        temp = list;
    }

}




/*Deep copy constructor*/
linkedListArray::linkedListArray(const linkedListArray& copyRight) {

    node* tempNode = copyRight.list;
    list = NULL;

    while (tempNode != NULL) {

        addEntry(tempNode->data);
        tempNode = tempNode->next;

    }
}




/*Assignment operator */
linkedListArray linkedListArray::operator =(const linkedListArray &copyRight) {

    if (this != &copyRight) {
        node* tempPtr = list;
        while (tempPtr != NULL) {
            list = list->next;
            delete tempPtr;
            tempPtr = list;
        }
    }
    node* tempNode = copyRight.list;
    list = NULL;

    while (tempNode != NULL) {

        addEntry(tempNode->data);
        tempNode = tempNode->next;

    }
}

