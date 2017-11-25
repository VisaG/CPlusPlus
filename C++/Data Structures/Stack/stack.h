/*
 * stack.h
 *
 *  Created on: Jun 27, 2013
 *      Author: visa
 */

#ifndef STACK_H
#define STACK_H

#include "exception.cpp"

namespace StackSavitch {
template<class T>
class Node {
public:
    Node(T theData, Node<T>* theLink) :
            data(theData), link(theLink) {
    }
    Node<T>* getLink() const {
        return link;
    }
    const T getData() const {
        return data;
    }
    void setData(const T& theData) {
        data = theData;
    }
    void setLink(Node<T>* pointer) {
        link = pointer;
    }
private:
    T data;
    Node<T> *link;
};

template<class T>
class Stack {
public:
    Stack();
    //Initializes the object to an empty stack.

    Stack(const Stack<T>& aStack);

    Stack<T>& operator =(const Stack<T>& rightSide);

    virtual ~Stack();

    void push(T stackFrame);
    //Postcondition: stackFrame has been added to the stack.

    T pop();
    //Precondition: The stack is not empty.
    //Returns the top stack frame and removes that top
    //stack frame from the stack.

    bool isEmpty() const;
    //Returns true if the stack is empty. Returns false otherwise.
private:
    Node<T> *top;
};

}        //StackSavitch
#endif //STACK_H


