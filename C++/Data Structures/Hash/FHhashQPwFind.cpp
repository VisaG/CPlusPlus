/*
 The file is FHhashQPwFind.cpp

 Created on: Nov 11th, 2013, Author: Visalakshi Gopalakrishnan
 Class: CS 2C, Instructor name: Dave Harden.
 Assignment 6.1

 */

#include <iostream>
#include <cstdlib>
#include "EBookEntry.h"
#include "FHhashQPwFind.h"
#include "Foothill_Sort.h"
using namespace std;

int getKey(const EBookEntry & item);
// string getKey(const EBookEntry & item);

int Hash(const EBookEntry & item);
int Hash(const string & key);
int Hash(int key);
void displayOneEBook(EBookEntry book);

int main() {
	int k;
	int NUM_RANDOM_INDICES = 25;
	int randNum = 0;
	int randomIndices[NUM_RANDOM_INDICES];
	EBookEntryReader bookInput("catalog-short4.txt");

	FHhashQPwFind<EBookEntry, int> hash_table;
	// FHhashQPwFind<EBookEntry, string> hash_table; // for any string equality

	EBookEntry book;
	srand(time(NULL));

	if (bookInput.readError()) {
		cout << "couldn't open " << bookInput.getFileName() << " for input.\n";
		exit(1);
	}

	EBookEntry::setSortType(EBookEntry::SORT_BY_ID);
	// EBookEntry::setSortType(EBookEntry::SORT_BY_CREATOR);

	cout << bookInput.getFileName() << endl;
	cout << bookInput.getNumBooks() << endl;

	for (k = 0; k < bookInput.getNumBooks(); k++) {

		hash_table.insert(bookInput[k]);
	}

	cout << "size " << hash_table.size() << endl;

	EBookEntry *bookArray = new EBookEntry[NUM_RANDOM_INDICES];

	for (k = 0; k < NUM_RANDOM_INDICES; k++) {

		randNum = (rand() % (2 * bookInput.getNumBooks()));
		randomIndices[k] = randNum;

		if (randNum < bookInput.getNumBooks()) {
			bookArray[k] = bookInput[randomIndices[k]];
		}
	}

	arraySort(bookArray, NUM_RANDOM_INDICES);

	for (k = 0; k < NUM_RANDOM_INDICES; k++) {
		displayOneEBook(bookArray[k]);
	}

	cout << "End of display " << endl << endl;


	for (k = 0; k < NUM_RANDOM_INDICES; k++) {

		try {

			book = hash_table.find(bookInput[randomIndices[k]].getETextNum());
			// book = hash_table.find(bookInput[randomIndices[k]].getCreator());
			displayOneEBook(book);

		} catch (...) {
			cout << "Not Found.  ";
		}
		cout << endl;
	}
	try {
		book = hash_table.find(-3);
		// book = hash_table.find("Jack Kerouac");

	} catch (...) {
		cout << "Not Found.  " << endl;

	}
	try {
		book = hash_table.find(30190);
		// book = hash_table.find("Winnie the Pooh");

	} catch (...) {
		cout << "Not Found.  " << endl;

	}
	try {
		book = hash_table.find(1);
		// book = hash_table.find("Mickey Mouse");

	} catch (...) {
		cout << "Not Found.  " << endl;

	}
	return 0;
}




int getKey(const EBookEntry & item) {
	return item.getETextNum();
}




/* string getKey(const EBookEntry & item) {
 return item.getCreator();
 } */




int Hash(const EBookEntry & item) {
	return Hash(getKey(item));
}



// a hash routine for strings that admits negative returns
int Hash(const string & key) {
	unsigned int k, retVal = 0;

	for (k = 0; k < key.length(); k++)
		retVal = 37 * retVal + key[k];

	return retVal;
}




int Hash(int key) {
	return key;
}




void displayOneEBook(EBookEntry book) {
	cout << "   # " << book.getETextNum() << "  ---------------" << endl;
	cout << "   \"" << book.getTitle() << "\"" << endl;
	cout << "   by " << book.getCreator() << endl;
	cout << "   re: " << book.getSubject() << endl << endl;
}
