#ifndef LIBRARY_H
#define LIBRARY_H
#include<vector>
#include "book.h"
#include "member.h"

class library
{
    public:
        library();
        library(string name, string location, string working_hour);
        virtual ~library();

        string Getname() { return name; }
        void Setname(string val) { name = val; }
        string Getlocation() { return location; }
        void Setlocation(string val) { location = val; }
        string Getworking_hour() { return working_hour; }
        void Setworking_hour(string val) { working_hour = val; }

        void setData();

    protected:

    private:
        string name;
        string location;
        string working_hour;
        vector<book> Books;
        vector<member> Members;

};

#endif // LIBRARY_H
