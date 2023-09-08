#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
#include<string>
using namespace std;

class Employee
{
    public:
        Employee();
        ~Employee();

        string GetName() { return Name; }
        void SetName(string val);

        string GetDOB() { return DOB; }
        void SetDOB(string val);

        double GetSalary() { return Salary; }
        void SetSalary(double val);

        void getInfo();
        void setInfo(string Name, string DOB, double salary);

        int getAge(string temp) const;

    private:
        string Name; //!< Member variable "Name"
        string DOB; //!< Member variable "DOB"
        double Salary; //!< Member variable "Salary"
};

#endif // EMPLOYEE_H
