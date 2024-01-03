#include<iostream>
#include<vector>
using namespace std;

class book
{
    public:
        book();
        virtual ~book();

        string Gettitle() { return title; }
        void Settitle(string val) { title = val; }
        string Getauthor() { return author; }
        void Setauthor(string val) { author = val; }
        string Getpub_date() { return pub_date; }
        void Setpub_date(string val) { pub_date = val; }
        int GetISBN() { return ISBN; }
        void SetISBN(int val) { ISBN = val; }
        int Getedition() { return edition; }
        void Setedition(int val) { edition = val; }

        void display();

    protected:

    private:
        string title;
        string author;
        string pub_date;
        int ISBN;
        int edition;
};

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

        void display();

    protected:

    private:
        string name;
        string postal_mail;
        string address;
        int number;
        string email;
        string status;
};

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

        void setData(string title, string author, string pub_date, int ISBN, int edition, string name, string postal_mail, string address, int number, string email, string status);

        void display();
    protected:

    private:
        string name;
        string location;
        string working_hour;
        vector<book> Books;
        vector<member> Members;

};

library::library()
{
    //ctor
}

library::library(string name, string location, string working_hour):name(name), location(location), working_hour(working_hour)
{
    //ctor
}

void library::setData(string title, string author, string pub_date, int ISBN, int edition, string name, string postal_mail, string address, int number, string email, string status){
    book temp;
    temp.Settitle(title);
    temp.Setauthor(author);
    temp.Setpub_date(pub_date);
    temp.SetISBN(ISBN);
    temp.Setedition(edition);

    Books.push_back(temp);

    member tem;
    tem.Setaddress(address);
    tem.Setname(name);
    tem.Setpostal_mail(postal_mail);
    tem.Setnumber(number);
    tem.Setemail(email);
    tem.Setstatus(status);

    Members.push_back(tem);

    //temp.Setauthor()
}

library::~library()
{
    //dtor
}

void library::display(){
    for(int i=0;i<Books.size();i++){
        Books[i].display();
    }
    for(int i=0;i<Members.size();i++){
        Members[i].display();
    }
}

book::book()
{
    //ctor
}

book::~book()
{
    //dtor
}

void member::display(){
    cout<<"name:"<<name<<endl;
    cout<<"postal_mail: "<<postal_mail<<endl;
    cout<<"address: "<<address<<endl;
    cout<<"number: "<<number<<endl;
    cout<<"email: "<<email<<endl;
    cout<<"status: "<<status<<endl;
}

member::member()
{
    //ctor
}

member::~member()
{
    //dtor
}

void book::display(){
    cout<<"title: "<<title<<endl;
    cout<<"author: "<<author<<endl;
    cout<<"pub_date: "<<pub_date<<endl;
    cout<<"ISBN: "<<ISBN<<endl;
    cout<<"edition: "<<edition<<endl;
}

int main(void){
    library l("tina","ohio","8-5");
    l.setData("a","b","c",45,34, "p","ewrr","we",9,"hg5","ryy");
    l.display();

}
