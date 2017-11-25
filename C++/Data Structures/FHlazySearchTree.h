/*The file is a header file -  FHlazySearchTree.h

 Created on: Oct 31th, 2013, Author: Visalakshi Gopalakrishnan
 Class: CS 2C, Instructor name: Dave Harden.
 Assignment 4.1

 ------------------------------------------------------------------------------
 THE PROGRAM TAKES BINARY SEARCH TREE IMPLEMENTED IN MODULES AND MODIFIES IT TO
 USE LAZY DELETION RATHER THAN EXPLICIT HARD DELETION
 ------------------------------------------------------------------------------

 Class supports functions to perform the following:-
 -int mSizeHard member => Tracks the number of "hard" nodes in a tree (deleted and undeleted)
 -mSize reflects the number of undeleted node(s).
 -Tags the node to be deleted later when hard remove is called
 -Inserts a node in the tree
 -Traverse the tree and print nodes in ascending order
 -Hard delete nodes, when garbage collection (lazy deletion) is called

 Client Input
 ============
 -Manipulate binary tree by insertion, deletion and printing of nodes

 Output
 ======
 -Tree manipulation based on different operations as per inputs

 **

 ==============================================================================
 CLASS FHs_treeNode
 ===================

 Public functions
 ================

 FHs_treeNode(const Comparable & d = Comparable(), FHs_treeNode *lt = NULL,
 FHs_treeNode *rt = NULL, bool deleted = false) :
 lftChild(lt), rtChild(rt), data(d), deleted(deleted) { };
 Constructor function

 Pre-condition
 -Initializes root with left child = NULL, right child = NUll, bool deleted = false.
 Post-condition
 -Creates a mRoot with left child(lt), right child(rt)
 and assigns data(dt), deleted(deleted)

 ==============================================================================
 CLASS FHsearch_tree
 ===================

 Public/Private functions
 ========================

 FHsearch_tree() {
 mSize = 0;
 mSizeHard = 0;
 mRoot = NULL;
 }
 Default Constructor

 Pre-condition
 -Set mHardSize, mSize to zero.
 -mRoot = Null
 **


 **
 Public Method
 const Comparable &find(const Comparable &x) const;
 Protected Method
 FHs_treeNode<Comparable> *find(FHs_treeNode<Comparable> *root,
 const Comparable &x) const;

 Pre-Condition
 -Evaluates user input node to be found

 Post-Condition
 -If the node to be found is NULL or if it is tagged for lazy deletion
 will call class NotFoundException { };
 -Else return node
 **


 **
 Public method
 int sizeHard() const { return mSizeHard;}

 Post-Condition
 -Returns the number of "hard" nodes in a tree (both deleted and undeleted).
 **


 **
 Public method
 const FHsearch_tree & operator=(const FHsearch_tree &rhs);
 Protected method
 FHs_treeNode<Comparable> *clone(FHs_treeNode<Comparable> *root) const;

 Pre-Condition
 -Makes sure does not self copy
 -Invokes protected method clone
 -Copies values of both mSize and MSizeHard

 Post-Condition
 -Makes deep copy of the tree
 **


 **
 Public Method
 bool insert(const Comparable &x);
 Protected Method
 bool insert(FHs_treeNode<Comparable> * &root, const Comparable &x);

 Pre-Condition
 -Traverse through tree to find appropriate sub tree where data(x) to be inserted
 -If root = NULL, create new root with data(x) and ltchild, rtchild = NULL
 -If (x < root->data), insert on left side
 -If (root->data < x), insert on right side
 -Else if (root->data == x && root->deleted), set root->deleted = false;

 Post-Condition
 -Insert right child or left child of the correct sub tree
 -Increment mSize++ and mHardSize++
 **


 **
 Public Method
 bool remove(const Comparable &x);
 Protected Method
 bool remove(FHs_treeNode<Comparable> * &root, const Comparable &x);

 Pre-Condition
 -Traverse through tree to find node to be marked for deletion by hard removal
 -If (root == NULL) return false;
 -If (x < root->data) mark left child of correct sub tree for removal
 -If (root->data < x) mark right child of correct sub tree for removal
 return remove(root->rtChild, x);
 -Take care of a condition when the root is already marked for removal

 Post-Condition
 -Perform the following actions if node was not already marked for removal prior
 Mark node for deletion later by lazy deletion method
 Decrement msize--
 **


 **
 Public Method
 void collectGarbage();
 Protected method
 void collectGarbage(FHs_treeNode<Comparable> *treeNode);

 Pre-Condition
 -Traverse through left side tree and find nodes to delete
 -If (treeNode == NULL)	return;
 -If found (treeNode->deleted), invoke method removeHard()
 -If (treeNode != NULL), then traverse through right side to find
 nodes to deleted
 -If found (treeNode->deleted), invoke method removeHard()

 Post-Condition
 -Hard delete node by invoking protected method removeHard()
 **


 **
 Protected Method
 bool removeHard(FHs_treeNode<Comparable> * &root, const Comparable &x);

 Post Condition
 -Hard deletes node
 -Decrement mHardSize--



 **/

#ifndef FHLAZYSEARCHTREE_H_
#define FHLAZYSEARCHTREE_H_
#include <iostream>
// ---------------------- FHs_treeNode Prototype --------------------------
template<class Comparable>
class FHs_treeNode {
public:
	FHs_treeNode(const Comparable & d = Comparable(), FHs_treeNode *lt = NULL,
			FHs_treeNode *rt = NULL, bool deleted = false) :
			lftChild(lt), rtChild(rt), data(d), deleted(deleted) {
	}

	FHs_treeNode *lftChild, *rtChild;
	Comparable data;
	bool deleted;

	// for use only with AVL Trees
	virtual int getHeight() const {
		return 0;
	}
	virtual bool setHeight(int height) {
		return true;
	}

};

// ---------------------- FHsearch_tree Prototype --------------------------
template<class Comparable>
class FHsearch_tree {
protected:
	int mSize;
	int mSizeHard;

	FHs_treeNode<Comparable> *mRoot;

public:
	FHsearch_tree() {
		mSize = 0;
		mSizeHard = 0;
		mRoot = NULL;
	}

	FHsearch_tree(const FHsearch_tree &rhs) {
		mRoot = NULL;
		mSize = 0;
		mSizeHard = 0;
		*this = rhs;
	}
	~FHsearch_tree() {
		clear();
	}

	const Comparable &findMin() const;
	const Comparable &findMax() const;
	const Comparable &find(const Comparable &x) const;

	bool empty() const {
		return (mSize == 0);
	}
	int size() const {
		return mSize;
	}
	int sizeHard() const {
		return mSizeHard;
	}
	void clear() {
		makeEmpty(mRoot);
	}
	const FHsearch_tree & operator=(const FHsearch_tree &rhs);

	bool insert(const Comparable &x);
	bool remove(const Comparable &x);

	bool contains(const Comparable &x) const {
		return find(mRoot, x) != NULL;
	}
	void collectGarbage();

	template<class Processor>
	void traverse(Processor func) const {
		traverse(mRoot, func);
	}
	int showHeight() const {
		return findHeight(mRoot);
	}

protected:
	FHs_treeNode<Comparable> *clone(FHs_treeNode<Comparable> *root) const;
	FHs_treeNode<Comparable> *findMin(FHs_treeNode<Comparable> *root) const;
	FHs_treeNode<Comparable> *findMax(FHs_treeNode<Comparable> *root) const;
	FHs_treeNode<Comparable> *find(FHs_treeNode<Comparable> *root,
			const Comparable &x) const;
	bool insert(FHs_treeNode<Comparable> * &root, const Comparable &x);
	bool remove(FHs_treeNode<Comparable> * &root, const Comparable &x);

	void collectGarbage(FHs_treeNode<Comparable> *treeNode);
	bool removeHard(FHs_treeNode<Comparable> * &root, const Comparable &x);

	void makeEmpty(FHs_treeNode<Comparable> * &subtreeToDelete);

	template<class Processor>
	void traverse(FHs_treeNode<Comparable> *treeNode, Processor func,
			int level = -1) const;
	int findHeight(FHs_treeNode<Comparable> *treeNode, int height = -1) const;

public:
	// for exception throwing
	class EmptyTreeException {	};
	class NotFoundException {	};
};



// FHsearch_tree public method definitions -----------------------------
template<class Comparable>
const Comparable & FHsearch_tree<Comparable>::findMin() const {
	if (mRoot == NULL)
		throw EmptyTreeException();
	return findMin(mRoot)->data;
}




template<class Comparable>
const Comparable & FHsearch_tree<Comparable>::findMax() const {
	if (mRoot == NULL)
		throw EmptyTreeException();
	return findMax(mRoot)->data;
}




template<class Comparable>
const Comparable &FHsearch_tree<Comparable>::find(const Comparable &x) const {
	FHs_treeNode<Comparable> *resultNode;

	resultNode = find(mRoot, x);
	if (resultNode == NULL)
		throw NotFoundException();
	return resultNode->data;
}




template<class Comparable>
const FHsearch_tree<Comparable> &FHsearch_tree<Comparable>::operator=(
		const FHsearch_tree &rhs) {
	if (&rhs != this) {
		clear();
		mRoot = clone(rhs.mRoot);
		mSize = rhs.size();
		mSizeHard = rhs.sizeHard();
	}
	return *this;
}




template<class Comparable>
bool FHsearch_tree<Comparable>::insert(const Comparable &x) {
	if (insert(mRoot, x)) {
		mSize++;
		mSizeHard++; // Increment MHardSize
		return true;
	}
	return false;
}




template<class Comparable>
bool FHsearch_tree<Comparable>::remove(const Comparable &x) {
	if (remove(mRoot, x)) {
		mSize--;
		return true;
	}
	return false;
}




template<class Comparable>
void FHsearch_tree<Comparable>::collectGarbage() {
	collectGarbage(mRoot);
}




template<class Comparable>
template<class Processor>
void FHsearch_tree<Comparable>::traverse(FHs_treeNode<Comparable> *treeNode,
		Processor func, int level) const {

	if (treeNode == NULL)
		return;
	// we're not doing anything with level but its there in case we want it
	traverse(treeNode->lftChild, func, level + 1);
	//Handle case of node tagged for deletion
	if (!treeNode->deleted)
		func(treeNode->data);
	traverse(treeNode->rtChild, func, level + 1);
}




// FHsearch_tree private method definitions -----------------------------
template<class Comparable>
FHs_treeNode<Comparable> *FHsearch_tree<Comparable>::clone(
		FHs_treeNode<Comparable> *root) const {

	FHs_treeNode<Comparable> *newNode;
	if (root == NULL)
		return NULL;

	newNode = new FHs_treeNode<Comparable>(root->data, clone(root->lftChild),
			clone(root->rtChild));
	return newNode;
}




template<class Comparable>
FHs_treeNode<Comparable> *FHsearch_tree<Comparable>::findMin(
		FHs_treeNode<Comparable> *root) const {
	if (root == NULL)
		return NULL;
	if (root->lftChild == NULL)
		return root;
	return findMin(root->lftChild);
}




template<class Comparable>
FHs_treeNode<Comparable> *FHsearch_tree<Comparable>::findMax(
		FHs_treeNode<Comparable> *root) const {
	if (root == NULL)
		return NULL;
	if (root->rtChild == NULL)
		return root;
	return findMax(root->rtChild);
}




template<class Comparable>
FHs_treeNode<Comparable>* FHsearch_tree<Comparable>::find(
		FHs_treeNode<Comparable> *root, const Comparable &x) const {
	  if (root == NULL)
	      return NULL;

	   if (x < root->data)
	      return find(root->lftChild, x);
	   if (root->data < x)
	      return find(root->rtChild, x);
	   // Handle case of if found node tagged for deletion
	   if(!root->deleted)
	   return root;

}



//Implements lazy deletion method
template<class Comparable>
void FHsearch_tree<Comparable>::collectGarbage(
		FHs_treeNode<Comparable> *treeNode) {

	if (treeNode == NULL)
		return;

	//Collect garbage left side of tree
	collectGarbage(treeNode->lftChild);

	//If found node for deletion, call removeHard()
	if (treeNode->deleted)
		removeHard(treeNode, treeNode->data);

	//If treeNode not NULL, collectGarbage right side of tree
	if (treeNode != NULL)
		collectGarbage(treeNode->rtChild);
}




template<class Comparable>
bool FHsearch_tree<Comparable>::insert(FHs_treeNode<Comparable> * &root,
		const Comparable &x) {
	if (root == NULL) {
		root = new FHs_treeNode<Comparable>(x, NULL, NULL);
		return true;
	} else if (x < root->data)
		return insert(root->lftChild, x);
	else if (root->data < x)
		return insert(root->rtChild, x);

	//Does not re-insert data if already there and marked for deletion
	//Remove tag for deletion
	else if (root->data == x && root->deleted) {
		root->deleted = false;
		mSize++;
	}

	return false; // duplicate
}




template<class Comparable>
bool FHsearch_tree<Comparable>::remove(FHs_treeNode<Comparable> * &root,
		const Comparable &x) {
	if (root == NULL)
		return false;

	if (x < root->data)
		return remove(root->lftChild, x);
	if (root->data < x)
		return remove(root->rtChild, x);

	//If found node, mark for deletion
	if (root->deleted == false) {
		root->deleted = true;
		return true;
	}

	return false;

}




template<class Comparable>
bool FHsearch_tree<Comparable>::removeHard(FHs_treeNode<Comparable> * &root,
		const Comparable &x) {

	// found the node
	if (root->lftChild != NULL && root->rtChild != NULL) {
		FHs_treeNode<Comparable> *minNode = findMin(root->rtChild);
		root->data = minNode->data;
		root->deleted = minNode->deleted;
		removeHard(root->rtChild, minNode->data);
		if (root->deleted) {
			removeHard(root, root->data);
		}

	} else {
		FHs_treeNode<Comparable> *nodeToRemove = root;
		root = (root->lftChild != NULL) ? root->lftChild : root->rtChild;

		delete nodeToRemove;
		//Decrement hard size
		mSizeHard--;

	}

	return true;
}




template<class Comparable>
void FHsearch_tree<Comparable>::makeEmpty(
		FHs_treeNode<Comparable> * &subtreeToDelete) {
	if (subtreeToDelete == NULL)
		return;

	// remove children
	makeEmpty(subtreeToDelete->lftChild);
	makeEmpty(subtreeToDelete->rtChild);

	// clear client's pointer
	delete subtreeToDelete;
	subtreeToDelete = NULL;
	--mSize;
}





template<class Comparable>
int FHsearch_tree<Comparable>::findHeight(FHs_treeNode<Comparable> *treeNode,
		int height) const {
	int leftHeight, rightHeight;

	if (treeNode == NULL)
		return height;
	height++;
	leftHeight = findHeight(treeNode->lftChild, height);
	rightHeight = findHeight(treeNode->rtChild, height);
	return (leftHeight > rightHeight) ? leftHeight : rightHeight;
}

#endif /* FHLAZYSEARCHTREE_H_ */
