/*
 The file is FHflowGraph.cpp

 Created on: Dec 11th, 2013, Author: Visalakshi Gopalakrishnan
 Class: CS 2C, Instructor name: Dave Harden.
 Assignment 9.1

 */


#include <string>
using namespace std;
#include "FHflowGraph.h"

// string is the data of the vertex; int is the cost type of edges
// --------------- main ---------------
int main() {
	FHflowGraph<string, int> myG, myG1;
	int finalFlow;

	myG.addEdge("s", "a", 3);
	myG.addEdge("s", "b", 2);
	myG.addEdge("a", "b", 1);
	myG.addEdge("a", "c", 3);
	myG.addEdge("a", "d", 4);
	myG.addEdge("b", "d", 2);
	myG.addEdge("c", "t", 2);
	myG.addEdge("d", "t", 3);

	myG.setStartVert("s");
	myG.setEndVert("t");

	// show the original flow graph
	myG.showResAdjTable();
	cout << endl;
	myG.showFlowAdjTable();

	finalFlow = myG.findMaxFlow();
	cout << "Final Flow " << finalFlow << endl;

	myG.showResAdjTable();
	cout << endl;
	myG.showFlowAdjTable();

	myG1.addEdge("a", "b", 5);
	myG1.addEdge("b", "d", 5);
	myG1.addEdge("b", "e", 5);
	myG1.addEdge("d", "f", 15);
	myG1.addEdge("a", "c", 15);
	myG1.addEdge("c", "d", 5);
	myG1.addEdge("c", "e", 5);
	myG1.addEdge("e", "f", 5);

	myG1.setStartVert("a");
	myG1.setEndVert("f");

	// show the original flow graph
	myG1.showResAdjTable();
	cout << endl;
	myG1.showFlowAdjTable();

	cout << endl;
	finalFlow = myG1.findMaxFlow();
		cout << "Final Flow " << finalFlow << endl;

		myG1.showResAdjTable();
		cout << endl;
		myG1.showFlowAdjTable();

	return 0;
}
