//============================================================================
// Name        : HashTest.cpp
// Author      : Khang Vinh Tran, Tri Doan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
# include "HashTable.h"





/*
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

	cout << "print out information on price and prejudice" << endl;
	cout << pp.get_title() << " " << pp.get_author() << " " << pp.get_price() << " " << pp.get_isbn() << endl;


	cout << endl <<  "********* Test insert ********" << endl;
	// Test Insert
	ht.insert(pp);
	ht.insert(c);
	ht.insert(hg);
	ht.insert(mhc);
	ht.insert(bh);

	cout << endl <<  "********* Test countBucket ********" << endl;
	// Test countBucket
	cout << "- Count number of book in bucket 9. Should print out 2" << endl;
	cout << ht.countBucket(9) << endl;
	HashTable ht2;
	cout << "- Count number of book in bucket 9 of an empty bucket. Should print 0" << endl;
	cout << ht2.countBucket(9) << endl;


	cout << endl <<  "********* Test search and remove ********" << endl;
	cout << "- Search for the bucket of the hunger game. Should print out 9" << endl;
	cout << ht.search(hg) << endl;
	cout << "- remove the hunger game" << endl;
	ht.remove(hg);
	cout << "- search hunger game again. Should print -1" << endl;
	cout << ht.search(hg) << endl;


	cout << endl <<  "********* Test printBucket ********" << endl;
	// test printBucket (also tested the << overload of Book.h)
	ht.printBucket(cout, 9);

	cout << endl <<  "********* Test printTable ********" << endl;
	// Test printTable()
	ht.printTable(cout);
	cout << "Test print table on an empty hash table. Should print out Books in the Catalogue:, then nothing" << endl;
	ht2.printTable(cout);



	return 0;
}
*/



/*
********* Test HashTable constructor and Book constructor ********
print out information on price and prejudice
Pride and Prejudice Jane Austen 4.95 1234567

********* Test insert ********

********* Test countBucket ********
- Count number of book in bucket 9. Should print out 2
2
- Count number of book in bucket 9 of an empty bucket. Should print 0
0

********* Test search and remove ********
- Search for the bucket of the hunger game. Should print out 9
9
- remove the hunger game
- search hunger game again. Should print -1
-1

********* Test printBucket ********
The Man in the High Castle by Philip K Dick
$15.95
ISBN#: 95959595



********* Test printTable ********
Books in the Catalogue:
Group 1
Bleak House by Charles Dickens
$8
ISBN#: 473890238

+0 more similar book(s)


Group 3
Pride and Prejudice by Jane Austen
$4.95
ISBN#: 1234567

+0 more similar book(s)


Group 5
Contact by Carl Sagan
$9.95
ISBN#: 99993339

+0 more similar book(s)


Group 10
The Man in the High Castle by Philip K Dick
$15.95
ISBN#: 95959595

+0 more similar book(s)


Test print table on an empty hash table. Should print out Books in the Catalogue:, then nothing
Books in the Catalogue:
*/


