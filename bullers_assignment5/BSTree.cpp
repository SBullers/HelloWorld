//
// Assignment 5 - Jolly Banker
// Created by Sara Bullers on 5/24/22.
//


#include "BSTree.h"
#include <fstream>

// constructor set to nullptr
BSTree::BSTree() {root = nullptr;}

//destructor
BSTree::~BSTree()
{
    clear(root);
}

bool BSTree::Insert(Account* account )
{
    // Calls recursive helper
    return insertHelper(root, account);
}

bool BSTree::insertHelper(Node* node, Account* newAccount) {

    if (node == nullptr) {
        root = new Node(newAccount);
        return true;
    }

    // If newAccount < node then start going down left side
    if (newAccount->getAccountNum() < node->AccountPtr->getAccountNum()) {
        if (node->Left == nullptr) {
            node->Left = new Node(newAccount);
            return true;
        }
        return insertHelper(node->Left, newAccount);
    }

    // Else if newAccount > node then start going down right side
    if (newAccount->getAccountNum() > node->AccountPtr->getAccountNum()) {
        if (node->Right == nullptr) {
            node->Right = new Node(newAccount);
            return true;
        }
        return insertHelper(node->Right, newAccount);
    }
    return false;
}

// Retrieve account
// returns true if successful, points account to found account
bool BSTree::Retrieve(const int& accountNumber, Account*& account) const
{

    return (retrieveHelper(root, accountNumber, account));
}

// recursive Retrieve Helper, points account to found account
bool BSTree::retrieveHelper(Node* node, int accountNumber,
                                 Account*& accountPtr) const {
    if (node == nullptr) {
        return false;
    }

    if (node->AccountPtr->getAccountNum() == accountNumber) {
        accountPtr = node->AccountPtr;
        return true;
    }

    if (accountNumber < node->AccountPtr->getAccountNum()) {
        return retrieveHelper(node->Left, accountNumber, accountPtr);
    }

    return retrieveHelper(node->Right, accountNumber, accountPtr);
}

// Display information on all accounts
void BSTree::Display()
{
    inOrderPrint(root);
}

// Display helper - traverses inorder
void BSTree::inOrderPrint(Node* current) {
    if (current != nullptr) {
        inOrderPrint(current->Left);

        ofstream outfile;
        outfile.open("BankTransOut.txt", std::ios_base::app);

        outfile << current->AccountPtr->getLastName() << " ";
        outfile << current->AccountPtr->getFirstName();
        outfile << " Account ID: ";
        outfile << current->AccountPtr->getAccountNum() << endl;

        for (int i = 0; i < 10; i++) {
            outfile << "        " << current->AccountPtr->getSubAccName(i)
                    << ": $" << current->AccountPtr->getSubAccBalance(i)
                    << endl;
        }
        outfile << endl;
        inOrderPrint(current->Right);
        outfile.close();
    }
}

// delete all information in AccountTree
void BSTree::clear(Node* node) {
    if (node != nullptr) {
        clear(node->Left);
        clear(node->Right);
        // delete accounts and nodes
        delete node->AccountPtr;
        delete node;
    }
}

// check if tree is empty
bool BSTree::isEmpty() const { return root == nullptr; }
