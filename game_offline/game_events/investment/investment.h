//
// Created by Tobias Rønningen on 09/08/2025.
//

#ifndef CMANIA_INVESTMENT_H
#define CMANIA_INVESTMENT_H

void bank_opening_message();    // For when the player first goes to the bank, or a bank.
void bank_how_much_to_invest(); // Prompting the player of how much to invest.
void investment(int money);  // Calculates investment. Takes in player money.
int return_investment();    // Returns the investment the player made from investment().


#endif //CMANIA_INVESTMENT_H