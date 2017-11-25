/*

 The file is a header file -  FHhashQPwFind.h

 Created on: Nov 11th, 2013, Author: Visalakshi Gopalakrishnan
 Class: CS 2C, Instructor name: Dave Harden.
 Assignment 6.1

 ------------------------------------------------------------------------------------------
 THE PROGRAM DESIGNS A CLASS TEMPLATE - FHhashQPwFind.h DERIVED FROM BASE CLASS
 FHhashQP, TO IMPLEMENT METHOD find() OF OBJECT(EBookEntry) FROM HASH TABLES
 USING IDEAS PRESENTED IN MODUles
 ------------------------------------------------------------------------------------------

 Class supports functions to perform the following:-

 -Read data from file "catalog-short4.txt"
 -Insert data in to a hash table
 -Generate 25 random integers (scaled to the number of EBookEntries) to
  use as special indices
 -Display 25 books (based on EtextNum or Creator) from the original
  vector (provided by the EBookEntryReader class)
 -25 find() calls (based on EtextNum or Creator) , which report success
  (show some part of the found book) or throw exception (failure with "not found" string).
 -Test few more cases of know find() failures.
 -Implements above methods once using the int eTextNum as a key field, and a second time
  using a string key field, like title or creator
 */


#ifndef FHHASHQPWFIND_H_
#define FHHASHQPWFIND_H_

#include "FHvector.h"
#include "FHhashQP.h"
#include <cmath>
using namespace std;

template<class Object, typename KeyType>
class FHhashQPwFind: public FHhashQP<Object> {
protected:

	int myHashKey(const KeyType & key) const;
	int findPosKey(const KeyType & key) const;

public:

	const Object find(const KeyType & key);
	class NotFoundException {};
};



//Protected methods definition
template<class Object, typename KeyType>
int FHhashQPwFind<Object, KeyType>::myHashKey(const KeyType & key) const {

	int hashVal;

	hashVal = Hash(key) % this->mTableSize;
	if (hashVal < 0)
		hashVal += this->mTableSize;

	return hashVal;
}




template<class Object, typename KeyType>
int FHhashQPwFind<Object, KeyType>::findPosKey(const KeyType & key) const {

	int kthOddNum = 1;
	int index = myHashKey(key);

	   while ( this->mArray[index].state != FHhashQP<Object>::EMPTY
	      && getKey(this->mArray[index].data) != key )
	   {
	      index += kthOddNum;  // k squared = (k-1) squared + kth odd #
	      kthOddNum += 2;   // compute next odd #
	      if ( index >= this->mTableSize )
	         index -= this->mTableSize;
	   }

	   return index;

}




//Public method definition
template<class Object, typename KeyType>
const Object FHhashQPwFind<Object, KeyType>::find(const KeyType & key) {

	typename FHhashQP<Object>::HashEntry searchResult = this->mArray[findPosKey(key)];

	//return searchResult.data;
	if (!(searchResult.state == FHhashQP<Object>::ACTIVE))
		throw NotFoundException();
	return searchResult.data;

}
#endif /* FHHASHQPWFIND_H_ */
