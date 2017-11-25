/*The file is a header file -  FHsplayTree.h

 Created on: Nov 10th, 2013, Author: Visalakshi Gopalakrishnan
 Class: CS 2C, Instructor name: Dave Harden.
 Assignment 5.1

 ------------------------------------------------------------------------------
 THE PROGRAM IMPLEMENTS TOP DOWN SPLAYING OF TREE
 TO INSERT, FIND AND REMOVE DATA(X). THIS HEADER FILE IS DERIVED FROM
 BASE CLASS FHsearch_tree
 --------------------------------------------------------------------------------
 The program does the following:-
 -Implement top down splaying of tree method for search, insert and remove
 of node
 -For operations that involve insert, find, contain and remove, the program performs
 splay operation on tree, relative to data(x), restructure tree, so that x will be
 at the root tree after the operation
 -Restructuring involves rotateWithLeftChild(root) if (x < root->lftChild->data)
 or rotateWithRightChild(root) if (x > root->rtChild->data), till data(x) is the
 root of the tree
 -Insert data(x) only if x != root, splay tree to search for data(x), if not found
 insert data(x)
 -Find data(x) using top down splay of tree
 -Remove data(x), perform splay operation on tree, delete data(x), restructure tree.
 */

#ifndef FHSPLAYTREE_H_
#define FHSPLAYTREE_H_
#include "FHsearch_tree.h"
using namespace std;

template<class Comparable>
class FHsplayTree: public FHsearch_tree<Comparable> {
public:

	bool insert(const Comparable &x);
	bool remove(const Comparable &x);
	const Comparable &find(const Comparable &x);
	bool contains(const Comparable &x);
	const Comparable &showRoot() {return this->mRoot->data;	}

protected:
	void splay(FHs_treeNode<Comparable> * & root, const Comparable & x);
	void rotateWithLeftChild(FHs_treeNode<Comparable> * & k2);
	void rotateWithRightChild(FHs_treeNode<Comparable> * & k2);
};

// FHsplayTree.h private method definitions -----------------------------

//Top down splay method
template<class Comparable>
void FHsplayTree<Comparable>::splay(FHs_treeNode<Comparable> * & root,
		const Comparable & x) {

	FHs_treeNode<Comparable> *rightTree, *leftTree, *rightTreeMin, *leftTreeMax;
	rightTree = leftTree = rightTreeMin = leftTreeMax = NULL;
	bool done = false;

	while (root != NULL && !done) {
		if (x < root->data) {
			if (root->lftChild == NULL) {
				done = true;
			} else if (x < root->lftChild->data) {
				rotateWithLeftChild(root);
				if (root->lftChild == NULL) {
					done = true;
				}
			}
			if (!done) {
				if (rightTree == NULL) {
					rightTree = root;
				} else {
					rightTreeMin->lftChild = root;
				}
				rightTreeMin = root;
				root = root->lftChild;
			}
		} else if (x > root->data) {
			if (root->rtChild == NULL) {
				done = true;
			} else if (x > root->rtChild->data) {
				rotateWithRightChild(root);
				if (root->rtChild == NULL) {
					done = true;
				}
			}
			if (!done) {
				if (leftTree == NULL) {
					leftTree = root;
					leftTreeMax = root;
				} else {
					leftTreeMax->rtChild = root;
				}
				leftTreeMax = root;
				root = root->rtChild;
			}
		} else {
			done = true;
		}
	}
	//Re-assemble tree
	if (!(leftTree == NULL)) {

		leftTreeMax->rtChild = root->lftChild;
		root->lftChild = leftTree;
	}
	if (!(rightTree == NULL)) {

		rightTreeMin->lftChild = root->rtChild;
		root->rtChild = rightTree;
	}
	//Set data(x) as root
	this->mRoot = root;
}





template<class Comparable>
void FHsplayTree<Comparable>::rotateWithRightChild(
		FHs_treeNode<Comparable> * & k2) {

	FHs_treeNode<Comparable> *k1 = k2->rtChild;
	k2->rtChild = k1->lftChild;
	k1->lftChild = k2;
	k2 = k1;
}





template<class Comparable>
void FHsplayTree<Comparable>::rotateWithLeftChild(
		FHs_treeNode<Comparable> * & k2) {

	FHs_treeNode<Comparable> *k1 = k2->lftChild;
	k2->lftChild = k1->rtChild;
	k1->rtChild = k2;
	k2 = k1;
}





// FHsplayTree.h private method definitions -----------------------------

template<class Comparable>
bool FHsplayTree<Comparable>::insert(const Comparable &x) {

	FHs_treeNode<Comparable> *root = this->mRoot;

	if (root == NULL) {
		FHs_treeNode<Comparable> *newNode = new FHs_treeNode<Comparable>(x,
				NULL, NULL);
		this->mRoot = newNode;
		this->mSize++;
		return true;
	} else {
		splay(root, x);
		FHs_treeNode<Comparable> *newNode = new FHs_treeNode<Comparable>(x,
				NULL, NULL);

		//Handles mSize, in case of reinsert of same data(x)
		if (x < root->data || x > root->data)
			this->mSize++;

		if (x < root->data) {

			FHs_treeNode<Comparable> *leftPtr;
			leftPtr = newNode->lftChild;
			newNode->lftChild = root->lftChild;
			newNode->rtChild = root;
			root->lftChild = leftPtr; //Handle splayed root's left child
			this->mRoot = newNode;
			return true;

		} else if (x > root->data) {
			FHs_treeNode<Comparable> *rightPtr;
			rightPtr = newNode->rtChild;
			newNode->lftChild = root;
			newNode->rtChild = root->rtChild;
			root->rtChild = rightPtr; //Handle splayed root's right child
			this->mRoot = newNode;
			return true;
		}

		return false;
	}
}





template<class Comparable>
const Comparable &FHsplayTree<Comparable>::find(const Comparable & x) {

	FHs_treeNode<Comparable> *root = this->mRoot;

	if (root == NULL)
		return NULL;
	splay(root, x);
	if (x < root->data || x > root->data) {
		throw typename FHsearch_tree<Comparable>::NotFoundException();
	}
	return root->data;
}





template<class Comparable>
bool FHsplayTree<Comparable>::remove(const Comparable & x) {

	FHs_treeNode<Comparable> *root = this->mRoot;
	FHs_treeNode<Comparable> *newRoot = NULL;

	if (root == NULL)
		return NULL;
	splay(root, x);
	if (x < root->data || x > root->data)
		return false;
	if (root->lftChild == NULL) {
		newRoot = root->rtChild;
	} else {
		newRoot = root->lftChild;
		splay(newRoot, x);
		newRoot->rtChild = root->rtChild;
	}
	delete root;
	this->mSize--;
	this->mRoot = newRoot;
	return true;
}




template<class Comparable>
bool FHsplayTree<Comparable>::contains(const Comparable &x) {

	try {
		find(x);
		return true;
	} catch (...) {
		return false;
	}
}

#endif /* FHSPLAYTREE_H_ */
