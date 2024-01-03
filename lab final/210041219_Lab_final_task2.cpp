#include<bits/stdc++.h>
using namespace std;
class Doc{
public:
    virtual void display_info()=0;
    virtual string get_title()=0;
};

class Book: public Doc{
private:
    string title;
    string author;
    string publisher;
public:
    Book():title(""),author(""), publisher(""){}
    Book(string Title, string auth, string pub):title(Title),publisher(pub),author(auth){}
    void display_info(){
        cout<<"title is: "<<title<<endl;
        cout<<"author is: "<<author<<endl;
        cout<<"publisher is: "<<publisher<<endl;
    }
    string get_title(){return title;}
};

class Entertainment: public Book{
private:
    string genre;
    int priority=2;
public:
    Entertainment():genre(""),Book(){}
    Entertainment(string Title, string auth, string pub, string gen):genre(gen),Book(Title, auth, pub){}
    void display_info(){
        Book::display_info();
        cout<<"genre is: "<<genre<<endl;
    }
    int get_priority(){return priority;}
};

class Academic: public Book{
private:
    string topic;
    string edition;
    int priority=1;
public:
    Academic():topic(""),edition(""),Book(){}
    Academic(string Title, string auth, string pub, string top, string ed):topic(top),edition(ed),Book(Title, auth, pub){}
    void display_info(){
        Book::display_info();
        cout<<"topic is: "<<topic<<endl;
        cout<<"edition is: "<<edition<<endl;
    }
    int get_priority(){return priority;}
};

class Journal: public Doc{
private:
    string title;
    vector<string> author_list;
    int publishing_year;
    string topic;
    int priority=3;
public:
    Journal():title(""),publishing_year(1900),topic(""){}
    Journal(string Title, vector<string>auth_list, int pub_year,string top ):title(Title),publishing_year(pub_year),topic(top){
        author_list=auth_list;
    }
    void display_info(){
        cout<<"title is: "<<title<<endl;
        cout<<"authors are: "<<endl;
        for(int i=0;i<author_list.size();i++){
            cout<<author_list[i]<<" ";
        }
        cout<<endl;
        cout<<"publishing year is: "<<publishing_year<<endl;
        cout<<"topic is: "<<topic<<endl;
    }
    string get_title(){return title;}
};

class Library{
private:
    int booknum;
    int journalnum;
    vector<pair<Doc*, int>> documents;
public:
    class invalid_quantity{};
    class BookNotAvailable{};
    class JournalNotAvailable{};

    static int docnum;
    void add_book(Doc* d, int quantity){
        documents.push_back({d, quantity});
        docnum++;
        if(typeid(d)==typeid(Book)) booknum+=quantity;
        else journalnum+=quantity;
    }
    Doc* lend_items(string title){
        if(docnum==0) throw invalid_quantity();
        for(int i=0;i<docnum;i++){
            if( documents[i].first->get_title() == title){
                if(documents[i].second>0){
                        documents[i].second-- ;
                        return documents[i].first; }
                else{
                    if(typeid(*documents[i].first)==typeid(Academic) || typeid(*documents[i].first)==typeid(Entertainment)) throw BookNotAvailable();
                    else throw JournalNotAvailable();
                }
            }
        }
    }
    void const library_contents(){
        for(int i=0;i<docnum;i++){
            cout<<i+1<<"."<<endl;
            documents[i].first->display_info();
        }
        cout<<endl;
    }
};

int Library::docnum=0;

void sortByBookType(Doc** d){
    for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            if(typeid(*d[j])==typeid(Academic) && (typeid(*d[i])==typeid(Entertainment) || typeid(*d[i])==typeid(Journal))){
                Doc* temp= d[i];
                d[i]=d[j];
                d[j]=temp;
            }
            else if(typeid(*d[j])==typeid(Entertainment) && typeid(*d[i])==typeid(Journal)){
                Doc* temp= d[i];
                d[i]=d[j];
                d[j]=temp;
            }
        }
    }
}

int main(void){
    Library lib;
    vector<string> auth_list;
    auth_list.push_back("john");
    auth_list.push_back("cena");

    Doc *d[10];
    d[0]= new Academic("a1","ef", "saefg", "sffg","seff");
    lib.add_book(d[0], 0);
    d[1]= new Journal("j1", auth_list, 2013, "sjdhfg");
    lib.add_book(d[1], 5);
    d[2]= new Entertainment("e1","ef", "saefg", "sffg");
    lib.add_book(d[2],3);
    d[3]=new Academic("a2","we", "uwrhb", "weuh","wevvgg");
    d[4]= new Journal("j2", auth_list, 2019, "fg");
    d[5]= new Journal("j3", auth_list, 2013, "sjdhfg");
    d[6]= new Journal("j4", auth_list, 2013, "sjdhfg");
    d[7]= new Journal("j5", auth_list, 2013, "sjdhfg");
    d[8]= new Entertainment("e2","ef", "saefg", "sffg");
    d[9]= new Entertainment("e3","ef", "saefg", "sffg");

    sortByBookType(d);

    try{
        Doc* d= lib.lend_items("a1");
    }
    catch(Library::invalid_quantity){
        cout<<"ERROR: not enough items available"<<endl;
    }
    catch(Library::BookNotAvailable){
        cout<<"ERROR: not enough books available"<<endl;
    }
    catch(Library::JournalNotAvailable){
        cout<<"ERROR: not enough journals available"<<endl;
    }
}
