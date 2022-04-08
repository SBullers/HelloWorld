// Sara Bullers
// Assignment 1 - Library

#include "Library.h"

#include <string>
#include <iostream>

using namespace std;

// constructor: initializes number of books in the library
Library::Library(const string &libraryName)
{
    numOfBooks = 0;
}

// destructor: deletes new objects created in the book array.
Library::~Library()
{
    cout << books;
    delete []books;
}

// AddBook: After checking if the book exists in the library, returns true if adding book successfully.
// returns false if book is already in the library.

bool Library:: AddBook(const string name)
{
    if(numOfBooks < MAX)
    {
        for (int i = 0; i < numOfBooks; i++)
        {
            if (name.compare(books[i]) == 0) return false;
        }
        books[numOfBooks++] = name;
        numOfBooks++;
        return true;
    }
    else
        {
            return false;
        }
}

// RemoveBook:  returns true if book is removed successfully.
// Returns false if books is not the library.
bool Library:: RemoveBook (const string name)
{

    if (numOfBooks == 0)
    {
        cout << "There are 0 books in library; nothing to remove.\n";
        return false;
    }
    for (int i = 0; i < numOfBooks; i++)
    {
        if(name.compare(books[i]) == 0)
        {
            books[i] = books[numOfBooks -1];
            numOfBooks--;
            return true;
        }
    }
    return false;
}

// ListAllBooks: Checks if there are books in the library. If yes, it lists all books.
// If there are no books, it prints "There are no books in library".
void Library:: ListAllBooks () const
{
    if(numOfBooks == 0)
    {
        cout << "There are no books in library. \n";
    }
    else
    {
        cout << "Sara's Library: \n";
        for (int i = 0; i < numOfBooks; i++)
        {
            cout << books[i] << endl;
        }

    }
}

// IsInLibrary: Checks if there are books in the library.
// Returns true if book is found in the library, false if the library is empty.
bool Library:: IsInLibrary (const string &name) const
{
    if (numOfBooks == 0)
    {
        cout << "There are 0 books in library; nothing to remove.\n";
        return false;
    }
    for (int i = 0; i < numOfBooks; i++)
    {
        if(name.compare(books[i])== 0)
        {
            return true;
        }
    }
    return false;
}

ostream &operator << (ostream &out, const Library &lib)
{
    out << "Sara's Library: " << endl;
    return out;
};





