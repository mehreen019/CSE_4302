#include<bits/stdc++.h>
using namespace std;
class BankAccount{
private:
    int accountNumber;
    string holderName;
    string accType;
    double currentBalance;
    double minBalance;
    double interest;
    vector<pair<string, double>> accStatement;
public:

    BankAccount():accountNumber(0), holderName("null"), accType("current"), currentBalance(500), minBalance(500),interest(3){
    }
    BankAccount(int an, string hn, string aT, double curb, double minb):interest(3){
        accountNumber=an;
        holderName=hn;
        accType=aT;
        currentBalance=curb;
        minBalance=minb;
    }
    void showBalance(){
        cout<<"CURRENT BALANCE IS: "<<currentBalance<<endl;
    }
    void deposit(double amount){
        currentBalance+=amount;
        accStatement.push_back(make_pair("deposit", amount));
    }
    void withdrawal(double amount){
        if(currentBalance-amount<minBalance){
            cout<<"WITHDRAWAL FAILURE"<<endl;
        }
        else{
            currentBalance-=amount;
            accStatement.push_back(make_pair("withdrawal", amount));
        }
    }
    void giveInterest(){
        int temp= (currentBalance*interest)/100;
        temp=temp-(temp/10);
        currentBalance+=temp;
    }
    void applPenalty(){
        if(currentBalance<minBalance){
            currentBalance-=100;
            cout<<"Current balance after applying penalty "<<currentBalance<<endl;
        }
    }
    void printAccountStatement(){
        for(int i=0;i<accStatement.size();i++){
            cout<<accStatement[i].first<<" "<<accStatement[i].second<<endl;
        }
    }
    ~BankAccount(){
        cout<<"Account of "<<holderName<<" with account no "<<accountNumber<<" is destroyed with a balance BDT "<<currentBalance<<endl;
    }
};

int main(void){
    BankAccount me(1,"moushi", "curr", 500,500);
    me.showBalance();
    me.deposit(1000);
    me.withdrawal(20);
    me.giveInterest();
    me.applPenalty();
    me.printAccountStatement();
}
