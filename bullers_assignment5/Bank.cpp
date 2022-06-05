//
// Assignment 5 - Jolly Banker
// Created by Sara Bullers on 5/24/22.
//

#include "Bank.h"
#include "Account.h"
#include <queue>
#include <sstream>

using namespace std;

// constructors
Bank::Bank() = default;

// destructor
Bank::~Bank() = default;

// reads a file then process transactions by calling associated methods
void Bank::processTransactions(const string& fileName) {

    ifstream input(fileName);
    string line;

    // store line by line into queue
    while (getline(input, line)) {
        transactionQueue.push(line);
    }
    // Everything is in queue at this point

    string transaction;

    // output and pop line by line
    while (!transactionQueue.empty()) {
        transaction = transactionQueue.front();
        transactionQueue.pop();

        // parse first character and call appropriate function
        if (transaction[0] == 'O') {
            open(transaction);
        }

        if (transaction[0] == 'D') {
            deposit(transaction);
        }

        if (transaction[0] == 'W') {
            withdraw(transaction);
        }

        if (transaction[0] == 'T') {
            transfer(transaction);
        }

        if (transaction[0] == 'H') {
            history(transaction);
        }
    }
}

// display all accounts and balances
void Bank::displayAllBankBalances() {
    std::ofstream outfile;
    outfile.open("BankTransOut.txt", ios_base::app);
    outfile << "\nProcessing Done. Final Balances" << endl;

    // Display the BST
    accountBST.Display();
}

// open an account, insert it into the BSTtree
// return true if successful
bool Bank::open(const string& transaction) {
    string firstName;
    string lastName;
    int accountNum = 0;
    string word;
    queue<string> tempQueue;

    std::ofstream outfile;
    outfile.open("BankTransOut.txt", std::ios_base::app);

    istringstream iss(transaction, istringstream::in);

    while (iss >> word) {
        tempQueue.push(word);
    }

    // parse given string
    tempQueue.pop();
    lastName = tempQueue.front();
    tempQueue.pop();
    firstName = tempQueue.front();
    tempQueue.pop();
    accountNum = stoi(tempQueue.front());
    tempQueue.pop();

    Account* current = nullptr;
    if (accountBST.Retrieve(accountNum, current)) {
        // Output Error Message
        outfile << "ERROR: Account " << accountNum
                << " is already open. Transaction refused." << endl;
        return false;
    }

    // making a new account
    auto* newAccount = new Account(firstName, lastName, accountNum);

    // Add account to BST
    accountBST.Insert(newAccount);

    return false;
}

// deposit into fund of an account
bool Bank::deposit(const string& transaction) {
    int fund = 0;
    int accountNum = 0;
    int amount = 0;
    string word;
    queue<string> tempQueue;

    std::ofstream outfile;
    outfile.open("BankTransOut.txt", ios_base::app);

    istringstream iss(transaction, istringstream::in);

    while (iss >> word) {
        tempQueue.push(word);
    }

    // parse given string
    tempQueue.pop();
    word = tempQueue.front();
    fund = stoi(word.substr(4, 1));
    word.pop_back();
    accountNum = stoi(word);
    tempQueue.pop();
    amount = stoi(tempQueue.front());
    tempQueue.pop();

    Account* current = nullptr;
    if (!accountBST.Retrieve(accountNum, current)) {
        // Output Error Message
        outfile << "Can't deposit, this account does not exist" << endl;
        return false;
    }

    // deposit into account and log
    current->subAccDeposit(fund, amount);
    current->writeAccountRecord(transaction, fund);
    return false;
}

// withdraw from fund in account
bool Bank::withdraw(const string& transaction) {
    int fund = 0;
    int accountNum = 0;
    int amount = 0;
    string word;
    queue<string> tempQueue;

    std::ofstream outfile;
    outfile.open("BankTransOut.txt", ios_base::app);

    istringstream iss(transaction, istringstream::in);

    while (iss >> word) {
        tempQueue.push(word);
    }

    // parse given string
    tempQueue.pop();
    word = tempQueue.front();
    fund = stoi(word.substr(4, 1));
    word.pop_back();
    accountNum = stoi(word);
    tempQueue.pop();
    amount = stoi(tempQueue.front());
    tempQueue.pop();


    // return false if account does not exist
    Account* current = nullptr;
    if (!accountBST.Retrieve(accountNum, current)) {
        // Output Error Message
        outfile << "ERROR: Can't withdraw, this account does not exist" << endl;
        return false;
    }

    // return false if insufficient funds
    if (!current->subAccWithdraw(fund, amount)) {
        string failedLine = transaction;
        if (failedLine[failedLine.size() - 1] == '\r') {
            failedLine.erase(failedLine.size() - 1);
        }
        current->writeAccountRecord(failedLine + " (Failed)", fund);
        outfile << "ERROR: Not enough funds to withdraw " << amount <<
            " from " << current->getFirstName() << " " << current->getLastName() << " " <<
            current->getSubAccName(fund) << endl;
        return false;
    }

    // log to account record
    current->writeAccountRecord(transaction, fund);
    return true;
}

// transfer between two funds
bool Bank::transfer(const string& transaction) {
    int fromFund = 0;
    int toFund = 0;
    int fromAccountNum = 0;
    int toAccountNum = 0;
    int amount = 0;
    string word;
    queue<string> tempQueue;

    ofstream outfile;
    outfile.open("BankTransOut.txt", ios_base::app);

    istringstream iss(transaction, istringstream::in);

    while (iss >> word) {
        tempQueue.push(word);
    }

    tempQueue.pop();

    // parse given string starting with "fromAccount"
    word = tempQueue.front();
    fromFund = stoi(word.substr(4, 1));
    word.pop_back();
    fromAccountNum = stoi(word);
    tempQueue.pop();
    // Get the amount
    amount = stoi(tempQueue.front());
    tempQueue.pop();
    // Getting "toAccount" fund info
    word = tempQueue.front();
    toFund = stoi(word.substr(4, 1));
    word.pop_back();
    toAccountNum = stoi(word);
    tempQueue.pop();

    // Get pointer to fromAccount
    Account* fromAccountPtr = nullptr;
    if (!accountBST.Retrieve(fromAccountNum, fromAccountPtr)) {
        // Output Error Message
        outfile << "ERROR: Could not find Account " << fromAccountNum
                << " Transfer cancelled." << endl;
        return false;
    }

    // Get pointer to toAccount
    Account* toAccountPtr = nullptr;
    if (!accountBST.Retrieve(toAccountNum, toAccountPtr)) {
        // Output Error Message
        outfile << "ERROR: Could not find Account " << toAccountNum
                << " Transfer cancelled." << endl;
        return false;
    }

    // try to withdraw, deposit if successful
    if (fromAccountPtr->subAccWithdraw(fromFund, amount)) {
        toAccountPtr->subAccDeposit(toFund, amount);
        fromAccountPtr->writeAccountRecord(transaction, fromFund);
        return true;
    }

    return false;
}

// display account history for 1 fund or all funds
bool Bank::history(const string& transaction) {

    int fund = -1;
    int accountNum = 0;
    string word;
    queue<string> tempQueue;

    std::ofstream outfile;
    outfile.open("BankTransOut.txt", std::ios_base::app);

    istringstream iss(transaction, istringstream::in);

    while (iss >> word) {
        tempQueue.push(word);
    }

    tempQueue.pop();
    word = tempQueue.front();
    // if length is 5, we are showing history for 1 fund only, get fund#
    if (word.length() == 5) {
        fund = stoi(word.substr(4, 1));
        word.pop_back();
    }
    accountNum = stoi(word);
    tempQueue.pop();


    Account* current = nullptr;
    if (!accountBST.Retrieve(accountNum, current)) {
        // Output Error Message
        outfile << "Can't display, this account does not exist" << endl;
        return false;
    }

    // call function to display all funds or 1 fund
    if (fund == -1) {
        // Display everything
        current->displayAccountRecord();
    } else {
        outfile << "Displaying Transaction History for "
                << current->getFirstName() << " " << current->getLastName()
                << "'s ";
        outfile.close();
        current->displaySubAccountRecord(fund);
    }
    return true;
}