#include<bits/stdc++.h>
using namespace std;
const int MAX=100;
const int LEN=80;
enum p_type {tbook, tdvd};
char emp[]="";

class Product{
protected:
    char title[LEN];
    int unit_price;
    int ID;
public:
    Product(char t[], int ID,int up):ID(ID),unit_price(up){
        strcpy(title, t);
    }

    static int numofProducts;
    static Product* arr[];

    virtual void getdata()
    {
        cout << " Enter title: "; cin >> title;
        cout << " Enter unit price: "; cin >> unit_price;
        cout << " Enter id: "; cin>>ID;
    }
    virtual void putdata()
    {
        cout << "\n Title: " << title;
        cout << "\n unit price: " << unit_price;
        cout << "   Id: " << ID;
    }

    p_type get_type();
    static void add();
    static void display();
    static void read();
    static void write();
    static void compare();
    static void assignn();

    bool operator<(Product& p){
        if(ID<p.ID) return true;
        else return false;
    }

    bool operator==(Product& p){
        if(ID==p.ID) return true;
        else return false;
    }

    bool operator>(Product& p){
        if(ID>p.ID) return true;
        else return false;
    }

    bool operator!=(Product& p){
        if(ID!=p.ID) return true;
        else return false;
    }

    bool operator<=(Product& p){
        if(ID<=p.ID) return true;
        else return false;
    }

    bool operator>=(Product& p){
        if(ID>=p.ID) return true;
        else return false;
    }

};

int Product::numofProducts=0;
Product* Product::arr[MAX];


class Book:public Product
{
private:
    char author[LEN];
public:
    Book():Product(emp,0,0){
        //numofProducts++;
        strcpy(emp, author);
    }
    Book(char title[], char auth[], int ID, int up):Product(title,ID,up)
    {   numofProducts++;
        strcpy(author, auth);
    }
    Book(Book& b):Product(b.title,b.ID,b.unit_price){
        numofProducts++;
        strcpy(author, b.author);
    }

    void getdata()
    {
        Product::getdata();
        cout << " Enter author: "; cin >> author;
    }
    void putdata()
    {
        Product::putdata();
        cout << "\n author: " << author;
    }

    void operator=(Book& p){
        strcpy(title, p.title);
        strcpy(author, p.author);
        ID=p.ID;
    }

};

class DVD:public Product
{
private:
    char director[LEN];
public:
    DVD():Product(emp,0,0){
        //numofProducts++;
        strcpy(emp,director);
    }
    DVD(char* title, char* dir, int ID,int up):Product(title,ID,up)
    { numofProducts++;
      strcpy(director, dir); }
    DVD(DVD& d):Product(d.title,d.ID,d.unit_price)
    {
        numofProducts++;
        strcpy(director,d.director);
    }


    void getdata()
    {
        Product::getdata();
        cout << " Enter director: "; cin >> director;
    }
    void putdata()
    {
        Product::putdata();
        cout << "\n director: " << director;
    }

    void operator=(DVD& p){
        strcpy(title, p.title);
        strcpy(director, p.director);
        ID=p.ID;
    }

};

void Product::add()
{
    char ch,ch2;
    int bt;
    cout << "'b' to add a book"
    "\n'd' to add a dvd"
    "\n'c' to copy another products value"
    "\nEnter selection: ";
    cin >> ch;
    switch(ch)
    {   case 'b':{
                arr[numofProducts] = new Book;
                arr[numofProducts++]->getdata();
                break;
        }
        case 'd':{
            arr[numofProducts] = new DVD;
            arr[numofProducts++]->getdata();
            break;
        }
        case 'c': {
            cout<<"product to copy: ";
            cin>>bt;
            arr[numofProducts++]=arr[bt];
            cout<<"\nProduct copied\n";
            break;
        }
        default: cout << "\nUnknown product type\n"; return;
    }
    //cout<<"ok";

}

void Product::display()
{
    cout<<"Displaying "<<numofProducts<<" products"<<endl;
    for(int j=0; j<numofProducts; j++)
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


p_type Product::get_type()
{
    if( typeid(*this) == typeid(Book) )
        return tbook;
    else if( typeid(*this)==typeid(DVD) )
        return tdvd;
    else
    { cerr << "\nBad employee type"; exit(1); }

}


void Product::write()
{
    int size;
    cout << "Writing " << numofProducts << " products.\n";
    ofstream ouf;
    p_type ptype;
    ouf.open("PRODUCT.DAT", ios::trunc | ios::binary);
    if(!ouf)
    { cout << "\nCan’t open file\n"; return; }
    for(int j=0; j<numofProducts; j++)
    {
        ptype = arr[j]->get_type();
        ouf.write( (char*)&ptype, sizeof(ptype) );
        switch(ptype)
        {
            case tbook: size=sizeof(Book); break;
            case tdvd: size=sizeof(DVD); break;
        }
        ouf.write( (char*)(arr[j]), size );
        if(!ouf)
        { cout << "\nCan’t write to file\n"; return; }
    }
}


void Product::read()
{
    int size;
    p_type ptype;
    ifstream inf;
    inf.open("PRODUCT.DAT", ios::binary);
    if(!inf)
    { cout << "\nCan’t open file\n"; return; }
    numofProducts = 0;
    while(true)
    {
        inf.read( (char*)&ptype, sizeof(ptype) );
        if( inf.eof() ) break;
        if(!inf)
        { cout << "\nCan’t read type from file\n"; return; }
        switch(ptype)
        {
            case tbook:
                arr[numofProducts] = new Book;
                size=sizeof(Book);
                break;
            case tdvd:
                arr[numofProducts] = new DVD;
                size=sizeof(DVD);
                break;
            default: cout <<"\nUnknown type in file\n"; return;
        }
        inf.read( (char*)arr[numofProducts], size );
        if(!inf)
        { cout << "\nCan’t read data from file\n"; return; }
        numofProducts++;
        }
    cout << "Reading " << numofProducts << " products\n";
}

void Product::compare(){
    int n1,n2;
    string c;
    cout<<"Insert two product IDs: \n";
    cin>>n1>>n2;
    cout << "'<' to compare between two products"
    "\n'>' to compare between two products"
    "\n'>=' to compare between two products"
    "\n'<=' to compare between two products"
    "\n'==' to compare between two products"
    "\n'!=' to compare between two products"
    "\nEnter selection: ";
    cin >> c;
    if( c=="<")
        {
            bool ans = Product::arr[n1] < Product::arr[n2];
            cout<<"Comparison between product "<<n1<<" and "<<n2<<" shows that: ";
            if(ans){
                cout<<n2<<" has a higher ID"<<endl;
            }
            else cout<<n1<<" has a higher ID"<<endl;
        }
    else if( c==">")
        {
            bool ans = Product::arr[n1] > Product::arr[n2];
            cout<<"Comparison between product "<<n1<<" and "<<n2<<" shows that: ";
            if(ans){
                cout<<n1<<" has a higher ID"<<endl;
            }
            else cout<<n2<<" has a higher ID"<<endl;
        }
    else if( c=="<=")
        {
            bool ans = Product::arr[n1] <= Product::arr[n2];
            cout<<"Comparison between product "<<n1<<" and "<<n2<<" shows that: ";
            if(ans){
                cout<<n2<<" has a higher ID or equal ID"<<endl;
            }
            else cout<<n1<<" has a higher ID"<<endl;
        }
    else if( c==">=")
        {
            bool ans = Product::arr[n1] >= Product::arr[n2];
            cout<<"Comparison between product "<<n1<<" and "<<n2<<" shows that: ";
            if(ans){
                cout<<n2<<" has a higher ID or equal ID"<<endl;
            }
            else cout<<n1<<" has a higher ID"<<endl;
        }
    else if( c=="==")
        {
            bool ans = Product::arr[n1] == Product::arr[n2];
            cout<<"Comparison between product "<<n1<<" and "<<n2<<" shows that: ";
            if(ans){
                cout<<n2<<" is equal to "<<n1<<endl;
            }
            else cout<<n1<<" is not equal to "<<n2<<endl;
        }
    else if( c=="!=")
        {
            bool ans = Product::arr[n1] != Product::arr[n2];
            cout<<"Comparison between product "<<n1<<" and "<<n2<<" shows that: ";
            if(ans){
                cout<<n2<<" is equal to "<<n1<<endl;
            }
            else cout<<n1<<" isn't equal to "<<n1<<endl;
        }
    else cout << "\nUnknown comparator\n"; return;

}

void Product::assignn(){
    int n1,n2;
    string c;
    cout<<"ID to be assigned: \n";
    cin>>n1;
    cout<<"ID to be assigned to: \n";
    cin>>n2;
    Product::arr[n2-1]=Product::arr[n1-1];
    cout<<"Successfully assigned\n";
}


int main(void){
    Product::arr[0] = new Book("to kill a mockingbird", "harper lee", 101, 345);
    Product::arr[1] = new Book("the fault of our stars", "john green", 23, 234);
    Product::arr[2] = new DVD("fallen angels", "wong kar wai", 5837,1093);
    Product::arr[3] = new DVD("in the mood for love", "wong kar wai", 344,467);
    Product::arr[4] = new DVD("howls moving castle", "hayao miyazaki", 4387,567);


    Book b1("B1", "d", 45, 243),b3("B3","c",3455, 567);
    Book b2=b1;
    //b2.putdata();
    b2=b3;
    //b2.putdata();
    Product::numofProducts-=3;

    char ch;
    while(true)
    {
        cout << "'a' -- add data for a product"
        "\n'd' -- display data for all products"
        "\n'w' -- write all product data to file"
        "\n'r' -- read all product data from file"
        "\n'c' -- compare between two products"
        "\n's' -- assign one products value to another"
        "\n'x' -- exit"
        "\nEnter selection: ";
        cin >> ch;
        switch(ch)
        {
            case 'a':
                Product::add(); break;
            case 'd':
                Product::display(); break;
            case 'w':
                Product::write(); break;
            case 'r':
                Product::read(); break;
            case 'c':
                Product::compare(); break;
            case 's':
                Product::assignn(); break;
            case 'x': exit(0);
            default: cout << "\nUnknown command";
        }
    }
    return 0;

}
