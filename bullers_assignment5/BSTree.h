//
// Assignment 5 - Jolly Banker
// Created by Sara Bullers on 5/24/22.
//

#ifndef BULLERS_ASSIGNMENT5_BSTREE_H
#define BULLERS_ASSIGNMENT5_BSTREE_H

#pragma once

#include "Account.h"
#include <iostream>


class BSTree {

public:
    // constructor
    BSTree();
    // destructor
    ~BSTree();

// Insert new account
    bool Insert(Account* account);

    // Retrieve account
    // returns true if successful AND *Account points to account
    bool Retrieve(const int& accountNumber, Account*& account) const;

    // Display information on all accounts
    void Display();

    // check if tree is empty
    bool isEmpty() const;


private:
    class Node {
    public:
        explicit Node(Account* account)
                : AccountPtr{account}, Right{nullptr}, Left{nullptr} {}

        Account* AccountPtr;
        Node* Right;
        Node* Left;
    };

    Node* root;

    // Insert recursive helper
    bool insertHelper(Node* node, Account* newAccount);

    // delete all information in AccountTree
    void clear(Node* node);

    // Retrieve Helper
    bool retrieveHelper(Node* node, int accountNumber,
            // NOLINTNEXTLINE
                        Account*& accountPtr) const;

    // inOrderPrint
    void inOrderPrint(Node* current);
};


#endif //BULLERS_ASSIGNMENT5_BSTREE_H
