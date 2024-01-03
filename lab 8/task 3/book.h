#ifndef BOOK_H
#define BOOK_H
#include<iostream>
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

    protected:

    private:
        string title;
        string author;
        string pub_date;
        int ISBN;
        int edition;
};

#endif // BOOK_H
