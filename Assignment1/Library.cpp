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

// default deconstructor
Library::~Library()
= default;

// AddBook: uses findBook to check if the book is currently in the library.
// If not (-1), it adds book to the library

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

// RemoveBook: Checks if there are any books in the library.
// If there are no books, it returns false
// Then it checks if there is only one book in the library. If yes, it removes book without index dipping below zero
// If there are more than one book, it removes the book, shifts the last book to the place of the removed book and sets
// the last book's memory to empty

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
        // overload of ostream
        cout << *this;
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

// findBook: searches to see if the name of the given book is in the library by using compare
// returns index if the book is in the library
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

// friend
ostream &operator << (ostream &out, const Library &lib )
{
    out << lib.libraryName << ": " << endl;
    return out;
};





