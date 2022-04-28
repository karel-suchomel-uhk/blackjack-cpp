//
// Created by Karel Suchomel on 27.04.2022.
//

#include "Wallet.h"
#include <UtilFunctions.h>
#include <iostream>

void Wallet::addToBalance(double amount) {
  double newBalance = roundUp(balance + amount, 2);
  setBalance(newBalance);
}

void Wallet::subtractFromBalance(double amount) {
  double newBalance = roundUp(balance - amount, 2);
  setBalance(newBalance);
}

void Wallet::setBalance(double balanceRef) {
  Wallet::balance = balanceRef;
}

double Wallet::getBalance() const {
  return roundUp(balance, 2);
}

Wallet::Wallet(double balance) : balance(balance) {}
