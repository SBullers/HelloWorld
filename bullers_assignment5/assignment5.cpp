//
// Assignment 5 - Jolly Banker
// Created by Sara Bullers on 5/24/22.
//


#include "Bank.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    Bank bank;

    for (int i = 1; i < argc; i++) {
        std::ofstream output;
        output.open("BankTransOut.txt", std::ios_base::app);
        output << "The command line argument(s) was " << argv[i] << endl;
        string fileName = argv[i];
        bank.processTransactions(fileName);
    }

    // Call bank.display to print message and tree
    bank.displayAllBankBalances();
    return 0;

}
