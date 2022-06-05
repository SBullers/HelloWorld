//
// Assignment 5 - Jolly Banker
// Created by Sara Bullers on 5/24/22.
//
#ifndef BULLERS_ASSIGNMENT5_ACCOUNT_H
#define BULLERS_ASSIGNMENT5_ACCOUNT_H

#pragma once

#include "Fund.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {

public:
    // Account constructor w/ parameters
    Account(string first, string last, int account);

    // Account destructor
    ~Account();

    // Getter for the account number
    int getAccountNum();

    // getter for the name of a subaccount
    string getSubAccName(int fundNum);

    // getter for the balance of a subaccount
    int getSubAccBalance(int fundNum);

    // getter for the firstName
    string getFirstName();

    // getter for the lastName
    string getLastName();

    //method that deposits certain amount into a subaccount
    bool subAccDeposit(int fundNum, int amount);

    // method that withdraws certain amount from a subaccount
    bool subAccWithdraw(int fundNum, int amount);

    // method writes record to a subaccount
    void writeAccountRecord(const string& record, int fundNum);

    // display records for a single subaccount
    void displaySubAccountRecord(int fundNum);

    // display records for all subaccounts
    void displayAccountRecord();

private:
    int accountNum{};
    string firstName;
    string lastName;

    // array of 10 funds
    Fund fundsArray[10];
};

#endif //BULLERS_ASSIGNMENT5_ACCOUNT_H
