#include "BookCollection.h"
#include "CurrencyBDT.h"
#include "CurrencyDollar.h"
#include "CurrencyEuro.h"
#include "CurrencyConverter.h"
using namespace std;

int main(void){

    BookCollection b1;
    b1.addBook("book", "auth", 34.7);

    string s="book";
    b1[s]= 5.5;
    double p = b1[s];
    cout<<p<<endl;

    CurrencyDollar d(11, 44);
    CurrencyEuro e(5, 78);
    CurrencyBDT tk_from_d = d;
    CurrencyBDT tk_from_e = e;
    tk_from_d.display();
    tk_from_e.display();

    CurrencyConverter c1(3.00, 5),c2(1.06, 5, true);
    c1.showcurrency();
    c2.showcurrency();
    double am = c1;
    cout<<"converted is: "<<p<<endl;
}
