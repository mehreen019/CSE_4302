#include<iostream>
using namespace std;
const int MAX = 100;
class Book{
private:
    string title;
    string author;
    int publish_year;
    bool availability;
public:
    Book();
    Book(string title, string author, int publish_year);
    ~Book();
    static int total_books;

    //first approach is creating a friend class to access all the private attributes

    friend class Library;

    //another approach would be to create getter and setter functions for each attributes, and access them during sorting in that way;

    string getTitle() const{ return title; }
    string getAuthor() const{ return author; }
    int getYear() const{ return publish_year; }
    bool getAvailability() const{ return availability; }
};

class Library{
private:
    Book books[MAX];
public:
    Library();
    ~Library();
    void addBook(const class Book& b);
    void displayBooks() const;
    void SortByTitle();
};

int Book::total_books=0;

Book::Book():title(""),author(""),publish_year(0),availability(false){}

Book::Book(string title, string author, int publish_year):title(title),author(author),publish_year(publish_year),availability(true){
    total_books+=1;
}

Book::~Book(){}

Library::Library(){
    Book b;
    for(int i=0;i<MAX;i++){
        books[i]=b;
    }
}

Library::~Library(){}

void Library::addBook(const class Book& b){
    int i=0;
    string t;
    for( ;i<MAX;i++){
        //without using friend class
        //t=books[i].getTitle();
        //if(t=="") break;

        //with using friend class
        if(books[i].title=="") break;
    }
    books[i]= b;
}

void Library::displayBooks() const{
    string t,a;
    int p;
    bool available;
    for(int i=0;i<Book::total_books;i++){
        //with using friend class
        cout<<"Title: "<<books[i].title<<endl;
        cout<<"Author: "<<books[i].author<<endl;
        cout<<"Publishing year: "<<books[i].publish_year<<endl;
        if(books[i].availability) cout<<"availability: true"<<endl;
        else cout<<"availability: false"<<endl;
        cout<<endl;

        //without using friend class, we'd need to get individual attributes and display those
    }
}

void Library::SortByTitle(){
    for(int i=0;i<Book::total_books;i++){
        for(int j=i+1;j<Book::total_books;j++){
            if(books[i].title>books[j].title){
                swap(books[i], books[j]);
            }
        }
    }
}

int main(void){
    Book b1("to kill a mocking bird", "harper lee", 1959);
    Book b2("all the lights we cannot see", "john lee", 2015);
    Book b3("divergent", "veronica roth", 2011);

    Library lib;
    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b3);

    lib.SortByTitle();
    lib.displayBooks();
    cout<<"Total number of books is: "<<Book::total_books<<endl;
}
