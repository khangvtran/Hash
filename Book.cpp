/*
 * Book.cpp
 *
 *  Created on: Nov 11, 2017
 *      Author: KVTran
 */




#include "Book.h"
#include <iostream>
#include <iomanip>

Book::Book():title(""), author(""), price(0.0), isbn(0){};

Book::Book(string t, string a, double p, unsigned i) {
    title = t;
    author = a;
    price = p;
    isbn = i;
}

/**Access Functions*/

string Book::get_title() {
    return title;
}

string Book::get_author() {
    return author;
}

unsigned Book::get_isbn() {
    return isbn;
}

double Book::get_price() {
    return price;
}

/**Manipulation Procedures*/

void Book::set_title(string t){
    title = t;
}

void Book::set_author(string a) {
    author = a;
}

void Book::set_isbn(unsigned i) {
    isbn = i;
}

void Book::set_price(double p) {
    price = p;
}

/**Additional Functions*/

ostream& operator<<(ostream& os, const Book& book)
{
	os << book.title << " by " << book.author << endl;
	os << "$" << book.price << endl;
	os << "ISBN#: " << book.isbn << endl;
	return os;
}

bool Book::operator==(const Book& book) {
    return (title == book.title && author==book.author);
}

bool Book::operator<(const Book& book)
{
	if (title.compare(book.title) < 0) return true;
	else if (title.compare(book.title) == 0)
	{
		if (author.compare(book.author) < 0) return true;
	}
	return false;
}

bool Book::operator>(const Book& book)
{
//compares two books to determine if one comes after the other
//alphabetically by title and secondarily by author if the two
//books contain the same title
//returns false if the two books are the same
	if (title.compare(book.title) > 0) return true;
	else if (title.compare(book.title) == 0 && author.compare(book.author) > 0) return true;
	return false;
}


