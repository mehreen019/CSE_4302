#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>

enum months
{   JAN = 0,
    FEB = 1,
    MAR = 2,
    APR = 3,
    MAY = 5,
    JUN = 6,
    JUL = 7,
    AUG = 8,
    SEP = 9,
    OCT = 10,
    NOV = 11,
    DEC = 12
};

class Student
{
    public:
        Student();
        Student(std::string Name, std::string DOB, int ID, double CGPA);
        ~Student();

        std::string GetName() const{ return Name; }
        void SetName(std::string val) { Name = val; }
        std::string GetDOB() const{ return DOB; }
        void SetDOB(std::string val) { DOB = val; }
        int GetID() const{ return ID; }
        void SetID(int val) { ID = val; }
        double GetCGPA() const{ return CGPA; }
        void SetCGPA(double val) { CGPA = val; }
        int GetCurYear() const{ return CurYear; }
        void SetCurDate(int date,std::string month,int year) { CurDay=date; CurMon=month, CurYear=year; }

        void getInfo() const;
        void setInfo(std::string Name, std::string DOB, int ID, double CGPA);
        int getAge() const;

    private:
        std::string Name;
        std::string DOB;
        int ID;
        double CGPA;
        std::string CurMon;
        int CurDay;
        int CurYear;
};

#endif // STUDENT
