#ifndef MEMBER_H
#define MEMBER_H
#include<iostream>
using namespace std;

class member
{
    public:
        member();
        virtual ~member();

        string Getname() { return name; }
        void Setname(string val) { name = val; }
        string Getpostal_mail() { return postal_mail; }
        void Setpostal_mail(string val) { postal_mail = val; }
        string Getaddress() { return address; }
        void Setaddress(string val) { address = val; }
        int Getnumber() { return number; }
        void Setnumber(int val) { number = val; }
        string Getemail() { return email; }
        void Setemail(string val) { email = val; }
        string Getstatus() { return status; }
        void Setstatus(string val) { status = val; }

    protected:

    private:
        string name;
        string postal_mail;
        string address;
        int number;
        string email;
        string status;
};

#endif // MEMBER_H
