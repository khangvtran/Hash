/*
 * Catalogue.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: KVTran
 */



# include "HashTable.h"
# include <fstream>
# include <iostream>
using namespace std;

void promptUser();

int main()
{
	// check file opening
	ifstream fin;
	fin.open("Catalogue.txt");
	if (fin.fail())
	{
		cout << "Fail to open input file" << endl;
		exit(-1);
	}

	// Create an empty Hash Table
	HashTable ht;

	// Create buffer values
	string title, author;
	double price;
	unsigned isbn;
	string buf;

	// read in the file and create a book for every 5 lines of input
	while (getline(fin, buf))
	{
		title = buf;
		getline(fin, buf);
		author = buf;
		getline(fin, buf);
		price = stod(buf);
		getline(fin, buf);
		isbn = stoi(buf);
		getline(fin, buf);

		Book book(title, author, price, isbn);
		ht.insert(book);
		//cout << book << endl;
	}

	// prompt user
	cout << "Welcome to the Best Reads App!" << endl;

	int userInput = 0;
	int groupNumber = 0;
	while (userInput != 6)
	{
		promptUser();
		cin >> userInput;
		cin.ignore();
		switch(userInput)
		{
		case 1:
			ht.printTable(cout);
			break;
		case 2:
			cout << "Enter the group number (1-10): ";
			cin >> groupNumber;
			cin.ignore();  //or cin >> ws
			cout << endl;
			cout << "The books in this group are:" << endl << endl;
			ht.printBucket(cout, groupNumber - 1);
			break;
		case 3:
		{
			cout << "Enter the title: ";
			getline(cin, title);
			cout << "Enter the author: ";
			getline(cin, author);
			cout << "Enter the price: ";
			getline(cin, buf);
			price = stod(buf);
			cout << "Enter the isbn: ";
			getline(cin, buf);
			isbn = stoi(buf);

			Book newBook(title, author, price, isbn);
			ht.insert(newBook);
			cout << title << " has been added to the catalogue" << endl << endl;
			break;
		}
		case 4:
			cout << "123" << endl;
			break;
		case 5:
			cout << "456" << endl;
			break;

		}

	}


	// close the file
	fin.close();
	return 0;
}

void promptUser()
{
	cout << "What would you like to do?" << endl;
	cout << "1. Browse catalogue" << endl;
	cout << "2. Explore a book group (1-10)" << endl;
	cout << "3. Insert a new book" << endl;
	cout <<  "4. Remove a book" << endl;
	cout << "5. Search for a book" << endl;
	cout << "6. Quit" << endl;
	cout << endl;
	cout << "Enter your choice: ";
}













