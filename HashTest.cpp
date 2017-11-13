//============================================================================
// Name        : Hash.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

# include "HashTable.h"





int main() {

	cout << endl <<  "********* Test HashTable constructor and Book constructor ********" << endl;
	// Test Create Book
	HashTable ht;
	Book pp("Pride and Prejudice", "Jane Austen", 4.95, 1234567);
	Book c("Contact", "Carl Sagan", 9.95, 99993339);
	Book hg("The Hunger Games", "Suzanne Collins", 13.55, 12388888);
	Book hp("Harry Potter", "J.K. Rowlings", 12.99, 55555678);
	Book mhc("The Man in the High Castle", "Philip K Dick", 15.95, 95959595);
	Book bh("Bleak House", "Charles Dickens", 8.00, 473890238);

	cout << endl <<  "********* Test insert ********" << endl;
	// Test Insert
	ht.insert(pp);
	ht.insert(c);
	ht.insert(hg);
	ht.insert(mhc);
	ht.insert(bh);

	cout << endl <<  "********* Test countBucket ********" << endl;
	// Test countBucket
	cout << ht.countBucket(9) << endl;

	cout << endl <<  "********* printBucket ********" << endl;
	// test printBucket (also tested the << overload of Book.h)
	ht.printBucket(cout, 9);

	cout << endl <<  "********* Test printTable ********" << endl;
	// Test printTable()
	ht.printTable(cout);



	return 0;
}

/************* Access Functions *************/
int HashTable::hash(string key) const
{
    int index, sum = 0;
    for(int i = 0; i < key.length(); i++)
        sum += (int) key[i]; //summing the ASCII values for each character in the string
    index = sum % SIZE; //dividing the summed ASCII values by 35 && storing remainder as my index
    return index;
}

int HashTable::countBucket(int index) const
{
	assert(index >= 0);
	assert(index < SIZE);
	return Table[index].getSize();
}



void HashTable::printBucket(ostream& out, int index) const
{
	assert(index >= 0);
	assert(index < SIZE);
	Table[index].print();
}


void HashTable::printTable(ostream& out) const
{
	cout << "Books in the Catalogue:" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (!Table[i].isEmpty())
		{
			cout << "Group " << i+1 << endl;
			cout << Table[i].getStart() << endl;
			cout << "+" << countBucket(i) - 1 <<" more similar book(s)" << endl << endl << endl;
			//cout << "+" << Table.countBucket(i) - 1 <<" more similar book(s)" << endl << endl << endl;
		}
	}
}



/************* Manipulation Procedures *************/

void HashTable::insert(Book b)
{
	string key = b.get_title() + b.get_author();
	int index = hash(key);
	Table[index].insertStop(b);
}

