#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include<iostream>


class SavingsAccount
{
    public:
        SavingsAccount();
        SavingsAccount(double balance);
        ~SavingsAccount();

        static double annualInterestRate;
        static void modifyInterestRate(double newRate);
        static int creation;
        static int destruction;

        double GetsavingsBalance() { return savingsBalance; }
        void SetsavingsBalance(double val) { savingsBalance = val; }
        double calculateMonthlyInterest();

        void displayInfo();

    private:
        double savingsBalance;
};

#endif // SAVINGSACCOUNT_H
