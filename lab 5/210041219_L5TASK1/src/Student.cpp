#include "Student.h"

Student::Student():Name(""),DOB(""),ID(0),CGPA(0)
{
    //ctor
}

Student::Student(std::string Name, std::string DOB, int ID, double CGPA):Name(Name),DOB(DOB),ID(ID),CGPA(CGPA)
{

}

Student::~Student()
{
    //dtor
}

void Student::setInfo(std::string Name, std::string DOB, int ID, double CGPA){
    SetName(Name);
    SetDOB(DOB);
    SetID(ID);
    SetCGPA(CGPA);
}


void Student::getInfo() const{
    std::cout<<"STUDENT NAME IS: "<<GetName()<<std::endl;
    std::cout<<"STUDENT DATE OF BIRTH IS: "<<GetDOB()<<std::endl;
    std::cout<<"STUDENT ID IS: "<<GetID()<<std::endl;
    std::cout<<"STUDENT CGPA IS: "<<GetCGPA()<<std::endl;
}

int Student::getAge() const{
    //std::cout<<GetDOB().size()<<std::endl;
    int curyear = GetCurYear();
    int birthyear = stoi(GetDOB().substr(7,4));
    return curyear-birthyear;
}
