// Sara Bullers
// Assignment 1 - Library

#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>

using namespace std;

// Class called Library that uses a private string array to store the list of books
// Supports the following methods: AddBook, RemoveBook,ListAllBooks and IsInLibrary

class Library
{
    public:
        explicit Library (string name);
        ~Library ();
        bool AddBook (string name);
        bool RemoveBook (string name);
        void ListAllBooks () const;
        bool IsInLibrary (string name) const;
        int findBook(string name) const;

    private:
        string name;
        string libraryName;
        static const int MAX = 100;
        string books[MAX];
        int numOfBooks;
        // friend function
        friend ostream &operator << (ostream &out, const Library &lib);
};

#endif // LIBRARY_H
