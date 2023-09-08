#include<iostream>
#include "SavingsAccount.h"
#include "Student.h"
#include "Employee.h"

using namespace std;
int main(void){

    cout<<"    TASK 1    "<<endl;
    SavingsAccount saver1(2000.0),saver2(3000.0);
    SavingsAccount::modifyInterestRate(3);
    cout<<"Calculation for saver1 is: "<<saver1.calculateMonthlyInterest()<<endl;

    SavingsAccount::modifyInterestRate(4);
    cout<<"Calculation for saver2 is: "<<saver2.calculateMonthlyInterest()<<endl;

    cout<<"Number of objects created is: "<<SavingsAccount::creation<<endl;
    cout<<"Number of objects destroyed is: "<<SavingsAccount::destruction<<endl;

    cout<<"    TASK 2   "<<endl;
    Student student1;
    student1.setInfo("moushi", "10 MAY 2002", 210041219, 3.95);
    student1.getInfo();

    cout<<"    TASK3    "<<endl;
    string month;
    int date,year;
    cout<<"INPUT TODAY'S DATE ";
    cin>>date>>month>>year;
    student1.SetCurDate(date,month,year);
    cout<<"STUDENT AGE IS: "<<student1.getAge()<<endl;

    cout<<"    TASK 4   "<<endl;
    Employee emp1;
    emp1.setInfo("mo", "10 MAY 2002", 2100);
    emp1.getInfo();
}
