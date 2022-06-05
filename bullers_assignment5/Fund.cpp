//
// Assignment 5 - Jolly Banker
// Created by Sara Bullers on 5/24/22.
//

#include "Fund.h"
#include <fstream>
#include <string>
#include <utility>

using namespace std;

// constructor
Fund::Fund() = default;
// destructor
Fund::~Fund() = default;

// getter for fundBalance
int Fund::getFundBalance() const { return fundBalance; }

// getter for fundName
string Fund::getFundName() const { return fundName; }

// setter for fundName
void Fund::setFundName(string name) { fundName = std::move(name); }

// setter for fundBalance
void Fund::setFundBalance(int balance) { fundBalance = balance; }

// method for depositing into a fund
void Fund::fundDeposit(int amount) { fundBalance += amount; }

// method that withdraw from fund
void Fund::fundWithdraw(int amount) { fundBalance -= amount; }

// add new record to a fund
void Fund::addFundRecord(const string& record) {
    fundRecord += (record + '\n');
}

// displays fundRecord
void Fund::displayFundRecord() {
    std::ofstream outfile;
    outfile.open("BankTransOut.txt", std::ios_base::app);
    outfile << fundName << ": $" << fundBalance << endl;
    outfile << fundRecord;
}