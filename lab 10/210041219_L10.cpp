#include<bits/stdc++.h>
using namespace std;
class Product{
protected:
    string title;
    //string authdirec;
    int ID;
public:
    Product(string title, int ID):title(title),ID(ID){}
    //Product(const Product& p):title(p.title),ID(p.ID),authdirec(p.authdirec){}

    virtual void displayInfo()=0;
    static int numofProducts;

    /*void setAuthdirec(string s){
        authdirec=s;
    }*/

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

    /*void operator=(Product& p){
        title=p.title;
        authdirec=p.authdirec;
        ID=p.ID;
    }*/
};

int Product::numofProducts=0;

class Book:public Product
{
private:
    string author;
public:
    Book(string title, string author, int ID):author(author),Product(title,ID)
    { numofProducts++;
      //setAuthdirec(author);
      //authdirec=author;
    }
    Book(const Book& b):author(b.author),Product(b.title,b.ID){
        numofProducts++;
    }

    void displayInfo(){
        cout<<"title: "<<title<<endl;
        cout<<"author: "<<author<<endl;
        cout<<"id: "<<ID<<endl;
    }
    void operator=(Book& p){
        title=p.title;
        author=p.author;
        ID=p.ID;
    }

};

class DVD:public Product
{
private:
    string director;
public:
    DVD(string title, string director, int ID):director(director),Product(title,ID)
    { numofProducts++; }
    DVD(const DVD& d):director(d.director),Product(d.title,d.ID)
    {
        numofProducts++;
    }

    void displayInfo(){
        cout<<"title: "<<title<<endl;
        cout<<"director: "<<director<<endl;
        cout<<"id: "<<ID<<endl;
    }

    void operator=(DVD& p){
        title=p.title;
        director=p.director;
        ID=p.ID;
    }

};

int main(void){
    Product* productlist[10];
    productlist[0] = new Book("to kill a mockingbird", "harper lee", 101);
    productlist[1] = new Book("the fault of our stars", "john green", 23);
    productlist[2] = new DVD("fallen angels", "wong kar wai", 5837);
    productlist[3] = new DVD("in the mood for love", "wong kar wai", 344);
    productlist[4] = new DVD("howls moving castle", "hayao miyazaki", 4387);

    cout<<"---TASK 5---"<<endl<<endl;

    bool ans = productlist[0] < productlist[1];
    cout<<"Comparison between product 1 and 2 shows that: ";
    if(ans){
        cout<<"2 has a higher ID"<<endl;
    }
    else cout<<"1 has a higher ID"<<endl;

    cout<<endl<<"---TASK 6---"<<endl<<endl;

    Book b1("B1", "d", 45),b3("B3","c",3455);
    Book b2=b1;
    b2.displayInfo();
    b2=b3;
    b2.displayInfo();

    cout<<endl<<"---TASK 7---"<<endl<<endl;
    cout<<endl<<"Total number of products is: "<<Product::numofProducts<<endl;
    cout<<endl<<"---TASK 8---"<<endl<<endl;

    for(int i=0;i<5;i++){
        productlist[i]->displayInfo();
    }


}
