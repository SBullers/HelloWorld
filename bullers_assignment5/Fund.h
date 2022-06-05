//
// Assignment 5 - Jolly Banker
// Created by Sara Bullers on 5/24/22.
//

#ifndef BULLERS_ASSIGNMENT5_FUND_H
#define BULLERS_ASSIGNMENT5_FUND_H

#pragma once

#include <string>
#include <iostream>

using namespace std;

class Fund {

public:
    // constructor
    Fund();
    // destructor
    ~Fund();
    // getter for fundBalance
    int getFundBalance() const;

    // getter for fundName
    string getFundName() const;

    // setter for fundName
    void setFundName(string name);

    // setter for fundBalance
    void setFundBalance(int balance);

    // method that deposits into fund
    void fundDeposit(int amount);

    // method that withdraw from fund
    void fundWithdraw(int amount);

    //method that add record
    void addFundRecord(const string& record);

    // displays fundRecord
    void displayFundRecord();

private:
    int fundBalance = 0;
    string fundName;
    string fundRecord;
};

#endif //BULLERS_ASSIGNMENT5_FUND_H
