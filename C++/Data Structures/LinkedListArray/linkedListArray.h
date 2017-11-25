/*
 *Name:Visalakshi Gopalakrishnan
 Date:June 27 2013
 Assignment Number:CS2B a7
 Instructor:Dave Harden
 File: linkedListArray.h

 This is the header file linkedListArray.h, an interface for the class
 linkedListArray

 */

#ifndef LINKEDLISTARRAY_H_
#define LINKEDLISTARRAY_H_

#include <iostream>
using namespace std;

class linkedListArray {

public:
    typedef std::size_t size_type;
    size_type getSize();
    string getEntry(int index);
    linkedListArray();
    linkedListArray(const linkedListArray& copyRight);
    ~linkedListArray();
    linkedListArray operator =(const linkedListArray &rightSide);
    void addEntry(string newString);

    bool deleteEntry(string delEntry);

private:

    struct node {
        string data;
        node* next;
    };

    node* list;

};
#endif /* LINKEDLISTARRAY_H_ */
