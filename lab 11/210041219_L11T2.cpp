#include <fstream>
#include <iostream>
#include <typeinfo>
using namespace std;
#include <process.h>
const int MAX = 100;
enum p_type {tbook, tdvd};

class product
{
private:
    char title[80];
    int unit_price;
    int id;
    static int n;
    static product* arr[];

public:
    virtual void getdata()
    {
        cout << " Enter title: "; cin >> title;
        cout << " Enter unit price: "; cin >> unit_price;
        cout << " Enter id: "; cin>>id;
    }
    virtual void putdata()
    {
        cout << "\n Title: " << title;
        cout << "\n unit price: " << unit_price;
        cout << "   Id: " << id;
    }

    virtual p_type get_type();
    static void add();
    static void display();
    static void read();
    static void write();
};

int product::n = 0;
product* product::arr[MAX];

class book : public product
{
private:
    char author[80];

public:
    void getdata()
    {
        product::getdata();
        cout << " Enter author: "; cin >> author;
    }
    void putdata()
    {
        product::putdata();
        cout << "\n author: " << author;
    }
};

class dvd : public product
{
private:
    char director[80];

public:
    void getdata()
    {
        product::getdata();
        cout << " Enter director: "; cin >> director;
    }
    void putdata()
    {
        product::putdata();
        cout << "\n director: " << director;
    }
};

void product::add()
{
    char ch;
    cout << "'b' to add a book"
    "\n'd' to add a dvd"
    "\nEnter selection: ";
    cin >> ch;
    switch(ch)
    {   case 'b': arr[n] = new book; break;
        case 'd': arr[n] = new dvd; break;
        default: cout << "\nUnknown product type\n"; return;
    }
    arr[n++]->getdata();
}

void product::display()
{
    for(int j=0; j<n; j++)
    {
    cout << (j+1);
    switch( arr[j]->get_type() )
    {
        case tbook: cout << ". Type: book"; break;
        case tdvd: cout << ". Type: dvd"; break;
        default: cout << ". Unknown type";
    }
    arr[j]->putdata();
    cout << endl;
    }
}


p_type product::get_type()
{
    if( typeid(*this) == typeid(book) )
        return tbook;
    else if( typeid(*this)==typeid(dvd) )
        return tdvd;
    else
    { cerr << "\nBad employee type"; exit(1); }

}


void product::write()
{
    int size;
    cout << "Writing " << n << " products.\n";
    ofstream ouf;
    p_type ptype;
    ouf.open("PRODUCT.DAT", ios::trunc | ios::binary);
    if(!ouf)
    { cout << "\nCan�t open file\n"; return; }
    for(int j=0; j<n; j++)
    {
        ptype = arr[j]->get_type();
        ouf.write( (char*)&ptype, sizeof(ptype) );
        switch(ptype)
        {
            case tbook: size=sizeof(book); break;
            case tdvd: size=sizeof(dvd); break;
        }
        ouf.write( (char*)(arr[j]), size );
        if(!ouf)
        { cout << "\nCan�t write to file\n"; return; }
    }
}


void product::read()
{
    int size;
    p_type ptype;
    ifstream inf;
    inf.open("PRODUCT.DAT", ios::binary);
    if(!inf)
    { cout << "\nCan�t open file\n"; return; }
    n = 0;
    while(true)
    {
        inf.read( (char*)&ptype, sizeof(ptype) );
        if( inf.eof() ) break;
        if(!inf)
        { cout << "\nCan�t read type from file\n"; return; }
        switch(ptype)
        {
            case tbook:
                arr[n] = new book;
                size=sizeof(book);
                break;
            case tdvd:
                arr[n] = new dvd;
                size=sizeof(dvd);
                break;
            default: cout <<"\nUnknown type in file\n"; return;
        }
        inf.read( (char*)arr[n], size );
        if(!inf)
        { cout << "\nCan�t read data from file\n"; return; }
        n++;
    }
    cout << "Reading " << n << " products\n";
}


int main()
{
    char ch;
    while(true)
    {
        cout << "'a' -- add data for a product"
        "\n'd' -- display data for all products"
        "\n'w' -- write all product data to file"
        "\n'r' -- read all product data from file"
        "\n'x' -- exit"
        "\nEnter selection: ";
        cin >> ch;
        switch(ch)
        {
            case 'a':
                product::add(); break;
            case 'd':
                product::display(); break;
            case 'w':
                product::write(); break;
            case 'r':
                product::read(); break;
            case 'x': exit(0);
            default: cout << "\nUnknown command";
        }
    }
    return 0;
}
