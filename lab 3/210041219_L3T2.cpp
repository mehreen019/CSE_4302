#include<bits/stdc++.h>
using namespace std;
class Medicine{
private:
    string name;
    string genericName;
    double discountPercent;
    double unitPrice;
public:
    void assignName(string n, string genN){
        name=n;
        genericName= genN;
    }
    void assignPrice(double price=0){
        unitPrice=price;
    }
    void setDiscountPercent(double percent){
        discountPercent = percent;
    }
    double getSellingPrice(){
        return unitPrice - (unitPrice*discountPercent)/100;
    }
    void display(){
        cout<<name<<" ("<<genericName<<") "<<"has a unit price of "<<unitPrice<<". Current discount is "<<discountPercent<<endl;
    }
};


int main(void){
    string s1,s2;
    double uP,dP;
    cin>>s1>>s2>>uP>>dP;

    Medicine obj;
    obj.assignName(s1,s2);
    obj.assignPrice(uP);
    obj.setDiscountPercent(dP);
    cout<<"discount price is: "<<obj.getSellingPrice()<<endl;
    obj.display();

}
