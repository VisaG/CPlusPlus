/*
 The file is FHflowGraph.h

 Created on: Dec 11th, 2013, Author: Visalakshi Gopalakrishnan
 Class: CS 2C, Instructor name: Dave Harden.
 Assignment 9.1

 */

#ifndef FHFLOWGRAPH_H_
#define FHFLOWGRAPH_H_
#include <limits.h>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <iostream>
#include <functional>
using namespace std;

// CostType is some numeric type that expresses cost of edges
// Object is the non-graph data for a vertex
template<class Object, typename CostType>
class FHflowVertex {
	// internal typedefs to simplify syntax
	typedef FHflowVertex<Object, CostType>* VertPtr;
	typedef map<VertPtr, CostType> EdgePairList;

public:
	static int nSortKey;
	static stack<int> keyStack;
	static enum {
		SORT_BY_DATA, SORT_BY_DIST
	} eSortType;
	static bool setNSortType(int whichType);
	static void pushSortKey() {
		keyStack.push(nSortKey);
	}
	static void popSortKey() {
		nSortKey = keyStack.top();
		keyStack.pop();
	}
	;

	static int const INFINITY = INT_MAX;  // defined in limits.h

	EdgePairList flowAdjList, resAdjList;

	Object data;
	CostType dist;
	VertPtr nextInPath;  // used for client-specific info

	FHflowVertex(const Object & x = Object());

	void addToFlowAdjList(VertPtr neighbor, CostType cost);
	void addToResAdjList(VertPtr neighbor, CostType cost);
	bool operator<(const FHflowVertex<Object, CostType> & rhs) const;
	const FHflowVertex<Object, CostType> & operator=(
			const FHflowVertex<Object, CostType> & rhs);
	void showFlowAdjList();
	void showResAdjList();
};

// static const initializations for Vertex --------------
template<class Object, typename CostType>
int FHflowVertex<Object, CostType>::nSortKey =
		FHflowVertex<Object, CostType>::SORT_BY_DATA;

template<class Object, typename CostType>
stack<int> FHflowVertex<Object, CostType>::keyStack;
// ------------------------------------------------------

template<class Object, typename CostType>
bool FHflowVertex<Object, CostType>::setNSortType(int whichType) {
	switch (whichType) {
	case SORT_BY_DATA:
	case SORT_BY_DIST:
		nSortKey = whichType;
		return true;
	default:
		return false;
	}
}





template<class Object, typename CostType>
FHflowVertex<Object, CostType>::FHflowVertex(const Object & x) :
		data(x), dist((CostType) INFINITY), nextInPath(NULL) {

}




template<class Object, typename CostType>
void FHflowVertex<Object, CostType>::addToFlowAdjList(
		FHflowVertex<Object, CostType> *neighbor, CostType cost) {
	flowAdjList[neighbor] = cost;
}





template<class Object, typename CostType>
void FHflowVertex<Object, CostType>::addToResAdjList(
		FHflowVertex<Object, CostType> *neighbor, CostType cost) {
	resAdjList[neighbor] = cost;
}





template<class Object, typename CostType>
bool FHflowVertex<Object, CostType>::operator<(
		const FHflowVertex<Object, CostType> & rhs) const {
	switch (nSortKey) {
	case SORT_BY_DIST:
		return (dist < rhs.dist);
	case SORT_BY_DATA:
		return (data < rhs.data);
	default:
		return false;
	}
}





template<class Object, typename CostType>
const FHflowVertex<Object, CostType> & FHflowVertex<Object, CostType>::operator=(
		const FHflowVertex<Object, CostType> & rhs) {
	resAdjList = rhs.resAdjList;
	data = rhs.data;
	dist = rhs.dist;
	nextInPath = rhs.nextInPath;

	return *this;
}




template<class Object, typename CostType>
void FHflowVertex<Object, CostType>::showFlowAdjList() {
	typename EdgePairList::iterator iter;

	cout << "Adj Flow List for " << data << ": ";
	for (iter = flowAdjList.begin(); iter != flowAdjList.end(); ++iter)
		cout << iter->first->data << "(" << iter->second << ") ";
	cout << endl;
}





template<class Object, typename CostType>
void FHflowVertex<Object, CostType>::showResAdjList() {
	typename EdgePairList::iterator iter;

	cout << "Adj Res List for " << data << ": ";
	for (iter = resAdjList.begin(); iter != resAdjList.end(); ++iter)
		cout << iter->first->data << "(" << iter->second << ") ";
	cout << endl;
}




template<class Object, typename CostType>
class FHflowGraph {
	// internal typedefs to simplify syntax
	typedef FHflowVertex<Object, CostType> Vertex;
	typedef FHflowVertex<Object, CostType>* VertPtr;
	typedef map<VertPtr, CostType> EdgePairList;
	typedef set<VertPtr> VertPtrSet;
	typedef set<Vertex> VertexSet;

private:
	VertPtrSet vertPtrSet;
	VertexSet vertexSet;
	VertPtr startVertPtr, endVertPtr;

public:
	FHflowGraph() {	}

	void addEdge(const Object &source, const Object &dest, CostType cost);
	VertPtr addToVertexSet(const Object & object);
	void showFlowAdjTable();
	void showResAdjTable();

	void clear();

	// algorithms
	bool establishNextFlowPath();

	bool setStartVert(const Object &x);
	bool setEndVert(const Object &x);
	CostType findMaxFlow();

private:
	VertPtr getVertexWithThisData(const Object & x);
	CostType getLimitingFlowOnResPath();
	bool adjustPathByCost(CostType cost);
	CostType getCostOfResEdge(VertPtr src, VertPtr dst);
	bool addCostToResEdge(VertPtr src, VertPtr dst, CostType cost);
	bool addCostToFlowEdge(VertPtr src, VertPtr dst, CostType cost);
};






template<class Object, typename CostType>
FHflowVertex<Object, CostType>* FHflowGraph<Object, CostType>::addToVertexSet(
		const Object & object) {
	pair<typename VertexSet::iterator, bool> retVal;
	VertPtr vPtr;

	// save sort key for client
	Vertex::pushSortKey();
	Vertex::setNSortType(Vertex::SORT_BY_DATA);

	// build and insert vertex into master list
	retVal = vertexSet.insert(Vertex(object));

	// get pointer to this vertex and put into vert pointer list
	vPtr = (VertPtr) &*retVal.first;
	vertPtrSet.insert(vPtr);

	Vertex::popSortKey();  // restore client sort key
	return vPtr;
}





template<class Object, typename CostType>
void FHflowGraph<Object, CostType>::clear() {
	vertexSet.clear();
	vertPtrSet.clear();
}





template<class Object, typename CostType>
void FHflowGraph<Object, CostType>::addEdge(const Object &source,
		const Object &dest, CostType cost) {
	VertPtr src, dst;

	// put both source and dest into vertex list(s) if not already there
	src = addToVertexSet(source);
	dst = addToVertexSet(dest);
	src->addToFlowAdjList(dst, 0);

	src = addToVertexSet(source);
	dst = addToVertexSet(dest);
	src->addToResAdjList(dst, cost);

	src = addToVertexSet(dest);
	dst = addToVertexSet(source);
	src->addToResAdjList(dst, 0);

}





template<class Object, typename CostType>
void FHflowGraph<Object, CostType>::showFlowAdjTable() {
	typename VertPtrSet::iterator iter;

	cout << "------------------------ \n";
	for (iter = vertPtrSet.begin(); iter != vertPtrSet.end(); ++iter)
		(*iter)->showFlowAdjList();
	cout << endl;
}





template<class Object, typename CostType>
void FHflowGraph<Object, CostType>::showResAdjTable() {
	typename VertPtrSet::iterator iter;

	cout << "------------------------ \n";
	for (iter = vertPtrSet.begin(); iter != vertPtrSet.end(); ++iter)
		(*iter)->showResAdjList();
	cout << endl;
}





template<class Object, typename CostType>
bool FHflowGraph<Object, CostType>::setStartVert(const Object & x) {

	startVertPtr = getVertexWithThisData(x);
	return true;
}





template<class Object, typename CostType>
bool FHflowGraph<Object, CostType>::setEndVert(const Object & x) {

	endVertPtr = getVertexWithThisData(x);
	return true;
}






template<class Object, typename CostType>
bool FHflowGraph<Object, CostType>::establishNextFlowPath() {
	typename VertPtrSet::iterator vIter;
	typename EdgePairList::iterator edgePrIter;
	VertPtr wPtr, sPtr, vPtr;
	CostType costVW;
	queue<VertPtr> partiallyProcessedVerts;
	bool donePath = false;

	sPtr = startVertPtr;
	if (sPtr == NULL)
		return false;

	// initialize the vertex list and place the starting vert in p_p_v queue
	for (vIter = vertPtrSet.begin(); vIter != vertPtrSet.end(); ++vIter) {
		(*vIter)->dist = Vertex::INFINITY;
		(*vIter)->nextInPath = NULL;
	}

	sPtr->dist = 0;
	partiallyProcessedVerts.push(sPtr); // or, FHbinHeap::insert(), e.g.

	// outer dijkstra loop
	while (!partiallyProcessedVerts.empty()) {
		vPtr = partiallyProcessedVerts.front();
		partiallyProcessedVerts.pop();

		// inner dijkstra loop: for each vert adj to v, lower its dist to s if you can
		for (edgePrIter = vPtr->resAdjList.begin();
				edgePrIter != vPtr->resAdjList.end() && !donePath;
				edgePrIter++) {
			wPtr = edgePrIter->first;
			costVW = edgePrIter->second;
			if (costVW != 0 && (vPtr->dist + costVW < wPtr->dist)) {

				wPtr->dist = vPtr->dist + costVW;
				wPtr->nextInPath = vPtr;

				partiallyProcessedVerts.push(wPtr);

			}

			if (vPtr == endVertPtr)
				donePath = true;
		}
	}

	return donePath;
}






template<class Object, typename CostType>
FHflowVertex<Object, CostType>* FHflowGraph<Object, CostType>::getVertexWithThisData(
		const Object & x) {
	typename VertexSet::iterator findResult;
	Vertex vert(x);

	Vertex::pushSortKey();  // save client sort key
	Vertex::setNSortType(Vertex::SORT_BY_DATA);
	findResult = vertexSet.find(vert);
	Vertex::popSortKey();  // restore client value

	if (findResult == vertexSet.end())
		return NULL;
	return (VertPtr) &*findResult; // the address of the vertex in the set of originals
}






template<class Object, typename CostType>
bool FHflowGraph<Object, CostType>::addCostToFlowEdge(VertPtr src, VertPtr dst,
		CostType cost) {
	typename EdgePairList::iterator iter;

	if (src == NULL || dst == NULL)
		return false;

	iter = src->flowAdjList.find(dst);
	if (iter->first == dst) {
		iter->second += cost;
		return true;
	}

// if we did not find dst in src's adj list, we are reversing
// flow along this edge -- subtract it from the edge
	iter = dst->flowAdjList.find(src);
	if (iter->first == src) {
		iter->second -= cost;
	}

	return true;

}






template<class Object, typename CostType>
bool FHflowGraph<Object, CostType>::addCostToResEdge(VertPtr src, VertPtr dst,
		CostType cost) {
	typename EdgePairList::iterator iter;

	if (src == NULL || dst == NULL)
		return false;

	iter = src->resAdjList.find(dst);
	if (iter->first == dst) {
		iter->second -= cost;
	}

	iter = dst->resAdjList.find(src);
	if (iter->first == src) {
		iter->second += cost;
	}

	return true;
}





template<class Object, typename CostType>
bool FHflowGraph<Object, CostType>::adjustPathByCost(CostType cost) {
	VertPtr vp, vpdst, start, stop;
	stack<VertPtr> pathStack;

	start = startVertPtr;
	stop = endVertPtr;
	if (start == NULL || stop == NULL)
		return false;

	for (vp = stop; vp != start; vp = vp->nextInPath) {
		if (vp->nextInPath == NULL) {
			return false;
		}
		pathStack.push(vp);
	}
	pathStack.push(vp);

	while (true) {
		vp = pathStack.top();
		pathStack.pop();

		if (pathStack.empty()) {
			break;
		}

		vpdst = pathStack.top();
		addCostToResEdge(vp, vpdst, cost);
		addCostToFlowEdge(vp, vpdst, cost);
	}
	return true;
}






template<class Object, typename CostType>
CostType FHflowGraph<Object, CostType>::getLimitingFlowOnResPath() {

	VertPtr vp, vpdst, start, stop;
	stack<VertPtr> pathStack;
	CostType lowCost = Vertex::INFINITY;
	CostType tmpCost;

	start = startVertPtr;
	stop = endVertPtr;
	if (start == NULL || stop == NULL)
		return false;

	for (vp = stop; vp != start; vp = vp->nextInPath) {
		if (vp->nextInPath == NULL) {
			return false;
		}
		pathStack.push(vp);
	}
	pathStack.push(vp);

	while (true) {
		vp = pathStack.top();
		pathStack.pop();

		if (pathStack.empty()) {
			break;
		}

		vpdst = pathStack.top();
		tmpCost = getCostOfResEdge(vp, vpdst);
		if (lowCost > tmpCost) {
			lowCost = tmpCost;
		}
	}
	return lowCost;

}





//CostType getCostOfResEdge(VertPtr src, VertPtr dst);
template<class Object, typename CostType>
CostType FHflowGraph<Object, CostType>::getCostOfResEdge(VertPtr src,
		VertPtr dst) {

	typename EdgePairList::iterator edgePrIter;
	bool done = false;

	CostType costVW = 0;

	for (edgePrIter = src->resAdjList.begin();
			edgePrIter != src->resAdjList.end() && !done; edgePrIter++) {
		if (edgePrIter->first == dst) {
			costVW = edgePrIter->second;
			done = true;
		}
	}
	return costVW;

}





template<class Object, typename CostType>
CostType FHflowGraph<Object, CostType>::findMaxFlow() {
	bool pathFound = true;
	CostType totalFlow = 0, limitingFlow = 0;
	while (pathFound) {
		pathFound = establishNextFlowPath();
		if (pathFound) {
			limitingFlow = getLimitingFlowOnResPath();
			adjustPathByCost(limitingFlow);
			totalFlow += limitingFlow;
		}
	}
	return totalFlow;
}

#endif /* FHFLOWGRAPH_H_ */
