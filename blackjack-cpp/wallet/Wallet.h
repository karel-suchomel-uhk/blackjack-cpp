//
// Created by Karel Suchomel on 27.04.2022.
//
#pragma once
#include <UtilFunctions.h>

class Wallet{
    double balance = 5000.00;

  public:
    Wallet()=default;

    explicit Wallet(double balance);

    void addToBalance(double amount);
    void subtractFromBalance(double amount);

    void setBalance(double balance);

    double getBalance() const;
};
