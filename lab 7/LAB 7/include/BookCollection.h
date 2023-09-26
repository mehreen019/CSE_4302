#ifndef BOOKCOLLECTION_H
#define BOOKCOLLECTION_H
const int max_size=5;
#include<iostream>

class BookCollection
{
    public:
        static int numBooks;
        //BookCollection();
        //~BookCollection();
        double& operator[](std::string& title);
       // void operator[](std::string& title, double price);
        void addBook(std::string title, std::string author, double price);

    private:
        std::string titles[max_size]={" "};
        std::string authors[max_size]={" "};
        double prices[max_size]={0.0};
};

#endif // BOOKCOLLECTION_H
