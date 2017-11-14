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
			cin.ignore();
			break;
		}
		case 4:
		{
			cout << "Enter the title of the book to remove: ";
			getline(cin, title);
			cout << "Enter the author: ";
			getline(cin, author);
			Book bookToBeRemoved(title, author, 1, 1234567);
			ht.remove(bookToBeRemoved);
			cout << title << " has been removed from the catalogue" << endl << endl;
			break;
		}

		case 5:
		{
			cout << "Enter the title of the book to search: ";
			getline(cin, title);
			cout << "Enter the author: ";
			getline(cin, author);
			Book bookToBeSearchedFor(title, author, 1, 1234567);
			int searchResult = ht.search(bookToBeSearchedFor);
			if (searchResult == -1)
			{
				cout << title <<" is not in the catalogue." << endl;
			}
			else cout << title << " is found at group " << searchResult+1 << " (or index " << searchResult << ")"<< endl;
			cout << endl;
			break;
		}
		case 6:
			cout << endl << "Happy Reading!" << endl;
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
	cout << "4. Remove a book" << endl;
	cout << "5. Search for a book" << endl;
	cout << "6. Quit" << endl;
	cout << endl;
	cout << "Enter your choice: ";
}



/*
Welcome to the Best Reads App!
What would you like to do?
1. Browse catalogue
2. Explore a book group (1-10)
3. Insert a new book
4. Remove a book
5. Search for a book
6. Quit

Enter your choice: 1
Books in the Catalogue:
Group 1
Bleak House by Charles Dickens
$8.99
ISBN#: 3567897

+1 more similar book(s)


Group 3
Ramona Blue by Julie Murphy
$9.99
ISBN#: 9328311

+0 more similar book(s)


Group 4
The Time in Between by Maria Duenas
$9.86
ISBN#: 4345344

+3 more similar book(s)


Group 5
Middlemarch by George Elliot
$12.5
ISBN#: 1256743

+0 more similar book(s)


Group 6
A Face like Glass by Frances Hardinge
$15.95
ISBN#: 4455443

+2 more similar book(s)


Group 7
The Woman in White by Wilkie Collins
$10.75
ISBN#: 3256789

+0 more similar book(s)


Group 10
A Room with a View by E.M. Forster
$7.5
ISBN#: 1177889

+2 more similar book(s)


What would you like to do?
1. Browse catalogue
2. Explore a book group (1-10)
3. Insert a new book
4. Remove a book
5. Search for a book
6. Quit

Enter your choice: 3
Enter the title: Harry Potter
Enter the author: JK Rowling
Enter the price: 1
Enter the isbn: 1234567
Harry Potter has been added to the catalogue


What would you like to do?
1. Browse catalogue
2. Explore a book group (1-10)
3. Insert a new book
4. Remove a book
5. Search for a book
6. Quit

Enter your choice: 5
Enter the title of the book to search: Harry Potter
Enter the author: JK Rowling
Harry Potter is found at group 8 (or index 7)

What would you like to do?
1. Browse catalogue
2. Explore a book group (1-10)
3. Insert a new book
4. Remove a book
5. Search for a book
6. Quit

Enter your choice: 2
Enter the group number (1-10): 8

The books in this group are:

Harry Potter by JK Rowling
$1
ISBN#: 1234567


What would you like to do?
1. Browse catalogue
2. Explore a book group (1-10)
3. Insert a new book
4. Remove a book
5. Search for a book
6. Quit

Enter your choice: 4
Enter the title of the book to remove: Harry Potter
Enter the author: JK Rowling
Harry Potter has been removed from the catalogue

What would you like to do?
1. Browse catalogue
2. Explore a book group (1-10)
3. Insert a new book
4. Remove a book
5. Search for a book
6. Quit

Enter your choice: 5
Enter the title of the book to search: Harry Potter
Enter the author: JK Rowling
Harry Potter is not in the catalogue.

What would you like to do?
1. Browse catalogue
2. Explore a book group (1-10)
3. Insert a new book
4. Remove a book
5. Search for a book
6. Quit

Enter your choice: 6

Happy Reading!
*/










