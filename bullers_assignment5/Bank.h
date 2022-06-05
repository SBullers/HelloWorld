//
// Assignment 5 - Jolly Banker
// Created by Sara Bullers on 5/24/22.
//

#ifndef BULLERS_ASSIGNMENT5_BANK_H
#define BULLERS_ASSIGNMENT5_BANK_H

#pragma once

#include "BSTree.h"
#include <fstream>
#include <queue>
#include <string>

using namespace std;

class Bank {
public:
    // constructor
    Bank();
    // destructor
    ~Bank();

    // method that processes transactions in given file
    void processTransactions(const string& fileName);
    // methods that display all accounts and balances
    void displayAllBankBalances();

    // Transaction Types
    bool deposit(const string& transaction);
    bool withdraw(const string& transaction);
    bool open(const string& transaction);
    bool transfer(const string& transaction);
    bool history(const string& transaction);

private:
    BSTree accountBST;
    // queue to hold transactions for processing
    queue<string> transactionQueue;
};

#endif //BULLERS_ASSIGNMENT5_BANK_H
