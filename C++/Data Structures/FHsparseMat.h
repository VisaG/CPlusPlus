/*
 The file is a header file -  FHsparemat.h

 Created on: Oct 7th, 2013, Author: Visalakshi Gopalakrishnan
 Class: CS 2C, Instructor name: Dave Harden.
 Assignment 2.1

 ------------------------------------------------------------------------------
 THE PROGRAM DESIGNS A CLASS TEMPLATE - SparseMat, TO IMPLEMENT
 A SPARSE MATRIX USING FHvector WITH ELEMENTS OF TYPE FHlist.
 THE FHlists HAVE ELEMENTS OF TYPE MatNode
 ------------------------------------------------------------------------------

 Class supports functions to perform the following:-
 -Establish size and default value (0) for all elements
 -Store and manipulate data in Sparse matrix without changing size
 -Get stored data from matrix
 -Print matrix of required size
 -Clear matrix of all data, replace with default without changing size
 -Handle exceptions if matrix bounds are violated.

 Client Input
 ============
 -Store data, get data and print matrix

 Output
 ======
 -Matrix manipulation based on different operations as per inputs

 **

 ==============================================================================
 CLASS MATNODE
 =============

 Public functions
 ================

 MatNode(int cl = 0, Object dt = Object()) :
 col(cl), data(dt) { };
 Constructor function

 Pre-condition
 -Initializes node at column(0) with default data (0)
 Post-condition
 -Creates a node at column (col) and assigns data(dt) to node
 **


 **
 int getCol() const { return col;}

 Post Condition
 -Returns/access column/node position (int c) from the list
 **

 **
 const Object & operator=(const Object &x) {
 return (data = x); }

 Pre-condition
 -Manipulates data(x) in that node/column
 Post-condition
 -Returns data(x)

 DATA MEMBERS
 ============
 protected:
 int col;

 public:
 Object data;

 ==============================================================================
 CLASS SPARSEMAT
 ===============

 Public functions
 ================

 SparseMat(int r, int c, const Object & defaultVal);
 Constructor function

 Post-condition
 -Allocates required size for sparse matrix using FHvector with
 elements of type FhList
 -Every element of FHvector is assigned an FhList. Each FhList
 is initialized with a matNode.
 -FhLists are populated with elements of matNode with default data
 **


 **
 const Object & get(int r, int c) const;

 Post-condition
 -Accessor that returns the object(x) stored in row r and column c.
 -Throws a user-defined exception if arrays bounds are violated
 **


 **
 bool set(int r, int c, const Object &x);

 Pre-condition
 -A mutator that places data x in row r and column c

 Post-condition
 -Returns false if bounds are violated when (r < 0 || r >= rows.size())
 -Manipulates and stores data without changing size of matrix
 -Removes any existing node from structure, if data(x) is default value
 -If row empty of data, set() will add node with new data(x) other than default
 **


 **
 void showSubSquare(int start, int size);

 Pre-condition
 -Display method that shows square sub-Matrix
 -Valid Rows    -  start to (start+size)-1
 -Valid Columns -  start to (start+size)-1

 Post-condition
 -Prints square sub-Matrix
 **


 **
 void clear();

 Post-condition
 -Clears all the rows
 -Set all values to the defaultVal
 -Matrix size remains unchanged
 **


 **
 class OutOfBoundsException {};

 Post-condition
 -Throws exception in the accessor function(int getCol() const)
 when bounds are violated if (r < 0 || r > rows.size())

 Data Member
 ============

 protected:
 typedef FHlist<MatNode<Object> > MatRow;
 typedef FHvector<MatRow> MasterCol;
 MasterCol rows;
 Object data;

 */

#ifndef FHSPARSEMAT_H_
#define FHSPARSEMAT_H_

using namespace std;

#include <stdlib.h>
#include <iostream>
#include "FHvector.h"
#include "FHlist.h"

template<class Object>
class MatNode {
protected:
	int col;

public:
	Object data;
	// we need a default constructor for lists
	MatNode(int cl = 0, Object dt = Object()) :
			col(cl), data(dt) {
	}
	int getCol() const {
		return col;
	}

	const Object & operator=(const Object &x) {
		return (data = x);
	}
};






template<class Object>
class SparseMat {

public:

	SparseMat(int r, int c, const Object & defaultVal);

	const Object & get(int r, int c) const;
	bool set(int r, int c, const Object &x);
	void showSubSquare(int start, int size);
	void clear();
	class OutOfBoundsException {
	};

protected:

	typedef FHlist<MatNode<Object> > MatRow;
	typedef FHvector<MatRow> MasterCol;

	MasterCol rows;
	Object data;
	int rowSize, colSize;

};





/*Constructor */
template<class Object>
SparseMat<Object>::SparseMat(int r, int c, const Object &x) {

	rowSize = r;
	colSize = c;
	data = x;

	for (int i = 0; i < r; i++) {
		MatRow tempList;
		rows.push_back(tempList);
	}

}





/*Function to print square sub-matrix to console */
template<class Object>
void SparseMat<Object>::showSubSquare(int start, int size) {

	typename MatRow::iterator iter;
	MatRow tempList;

	for (int i = start; i <= ((start + size) - 1); i++) {
		tempList = rows[i];
		iter = tempList.begin();

		for (int j = start; j <= ((start + size) - 1); j++) {
			if (!tempList.empty() && iter != tempList.end()
					&& (*iter).getCol() == j) {

				cout << (*iter).data << " ";

				iter++;
			} else {

				cout << data << " ";
			}
		}

		cout << endl;
	}

}






/*Mutator function that manipulates data x at row r and column c */
template<class Object>
bool SparseMat<Object>::set(int r, int c, const Object &x) {

	bool setList = false;

	/*Check to see if bounds are violated */
	if (!(r < 0 || r >= rowSize ||
			c < 0 || c >= colSize)) {

		typename MatRow::iterator iter, theHead, theTail;
		theHead = rows[r].begin();
		theTail = rows[r].end();

		MatNode<Object> tempNode(c, x);

		/*Add node with data x if list empty */
		if (rows[r].empty()) {
			rows[r].push_front(tempNode);
			setList = true;
		} else {

			/*Compare location of new element with last element
			 * (non default) previous to tail */
			if (rows[r].back().getCol() < c) {
				rows[r].push_back(tempNode);
				setList = true;
			} else {

				for (iter = theHead; ((!setList) && iter != theTail); iter++) {
					if ((*iter).getCol() > c) {

						/* Sort the node as per ascending order
						 * of col in the list */
						rows[r].insert(iter, tempNode);
						setList = true;

					} else if ((*iter).getCol() == c) {

						/* Remove existing node if value x to be set
						 * is the default value */
						if (x == data)
							rows[r].erase(iter);
						else
							(*iter).data = x;
						setList = true;
					}
				}

			}

		}
	}

	return setList;
}





/*Accessor function that returns data x at row r and column c */
template<class Object>
const Object& SparseMat<Object>::get(int r, int c) const {

	/*Check to see if bounds are violated */
	if (r < 0 || r >= rowSize ||
			c < 0 || c >= colSize)  {

		throw OutOfBoundsException();
	} else {

		typename MatRow::const_iterator iter;
		MatRow tempRow;
		tempRow = rows[r];

		for (iter = tempRow.begin();
				((*iter).getCol() < c && iter != tempRow.end()); iter++)
			;
		return (*iter).data;
	}
}






/*Clears row, set value to default without changing size */
template<class Object>
void SparseMat<Object>::clear() {

	typename MatRow::iterator iter;
	for (int i = 0; i < rowSize; i++) {
		for (iter = rows[i].begin(); iter != rows[i].end(); iter++) {
			(*iter).data = data;
		}
	}
}
#endif /* FHSPARSEMAT_H_ */
