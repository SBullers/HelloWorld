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
        Library (const string &libraryName); 
        ~Library ();
        bool AddBook (const string name);
        bool RemoveBook (const string name);
        void ListAllBooks () const;
        bool IsInLibrary (const string &name) const;     

    private:
        string name;
        string libraryName;
        static const int MAX = 100;
        string *books = new string[MAX];
        int numOfBooks;
        int findBook(const string& name) const;

    // friend function
    friend ostream &operator << (ostream &out, const Library &lib);
    
};

#endif // LIBRARY_H
