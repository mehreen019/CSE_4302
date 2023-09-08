#include "Employee.h"

Employee::Employee()
{
    //ctor
}

Employee::~Employee()
{
    //dtor
}

void Employee::SetDOB(std::string val){
    if(getAge(val)>=18) DOB=val;
    else DOB="1 JAN 2002";
}

void Employee::SetName(std::string name){
    if(name.size()>2) Name=name;
    else Name="John Doe";
}

void Employee::SetSalary(double val){
    if(val>=10000 && val<=100000) Salary=val;
    else Salary=10000;
}

void Employee::setInfo(std::string Name, std::string DOB, double salary){
    SetName(Name);
    SetDOB(DOB);
    SetSalary(salary);
}


void Employee::getInfo(){
    std::cout<<"EMPLOYEE NAME IS: "<<GetName()<<std::endl;
    std::cout<<"EMPLOYEE DATE OF BIRTH IS: "<<GetDOB()<<std::endl;
    std::cout<<"EMPLOYEE SALARY IS: "<<GetSalary()<<std::endl;
}

int Employee::getAge(std::string temp) const{
    //std::cout<<GetDOB().size()<<std::endl;
    int curyear = 2023;
    int birthyear = stoi(temp.substr(7,4));
    return curyear-birthyear;
}
