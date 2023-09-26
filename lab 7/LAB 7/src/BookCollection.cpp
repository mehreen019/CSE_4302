#include "BookCollection.h"

int BookCollection::numBooks=0;

/*BookCollection::BookCollection()
{
    titles[max_size]={""};
    authors[max_size]={""};
    prices[max_size]={0.0};
}

BookCollection::~BookCollection()
{
    //dtor
}*/

double& BookCollection::operator[](std::string& title){
    double p=0.0;
    for(int i=0;i<max_size;i++){
        if(titles[i]==title){
            //std::cout<<prices[i];
            return prices[i];
        }
    }
    return p;
}


void BookCollection::addBook(std::string title, std::string author, double price){
    int i;
    for(i=0;i<max_size;i++){
        if(titles[i]==" ") break;
    }
    if(i==max_size) std::cout<<"MAX CAPACITY REACHED"<<std::endl;
    else{
        titles[i]=title;
        authors[i]=author;
        prices[i]=price;
    }
    //std::cout<<title;
}
