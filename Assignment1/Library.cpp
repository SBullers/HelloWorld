// Sara Bullers
// Assignment 1 - Library

#include "Library.h"

#include <string>
#include <iostream>

using namespace std;

// constructor: initializes number of books in the library
Library::Library(const string name)
{
    libraryName = name;
    numOfBooks = 0;
}

// deconstructor
Library::~Library()
= default;

// AddBook: After checking if the book exists in the library, returns true if adding book successfully.
// returns false if book is already in the library.

bool Library:: AddBook(const string name)
{
    string value = books[numOfBooks];
    int bookIndex = Library::findBook(name);
    if(numOfBooks < MAX && bookIndex == -1)
    {
        books[numOfBooks] = name;
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
    int bookIndex = Library::findBook(name);
    // if there's only one book in the library
    if (bookIndex > -1 && numOfBooks == 1)
    {
        books[bookIndex] = "";
    }
    if (bookIndex > -1)
    {
        string lastBook = books[numOfBooks -1];
        books[bookIndex] = lastBook;
        books[numOfBooks - 1] = "";
        numOfBooks--;
        return true;
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
bool Library:: IsInLibrary (const string name) const
{
    if (numOfBooks == 0)
    {
        cout << "There are 0 books in library; nothing to remove.\n";
        return false;
    }
    int bookIndex = Library::findBook(name);
    bool returnVal = false;
    if (bookIndex > -1) {
        returnVal = true;
    }
    return returnVal;
}

// findBook:
int Library::findBook(const string name) const {
    // didn't find the book scenario
    int index = -1;
    for (int i = 0; i < numOfBooks; i++)
    {
        if(name.compare(books[i])== 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

ostream &operator << (ostream out, const Library)
{

    out << "Sara's Library: " << endl;
    return out;
};





