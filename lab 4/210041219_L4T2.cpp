#include<bits/stdc++.h>
using namespace std;
class Medicine{
private:
    string name;
    string genericName;
    double discountPercent;
    double unitPrice;
    double inPrice;
public:
    Medicine():name("null"),genericName("null"),discountPercent(5.0),unitPrice(0.0),inPrice(0){
        inPrice=unitPrice;
    }
    Medicine(string n, string genN, double unit=0.0):discountPercent(5){
        name=n;
        genericName=genN;
        unitPrice=unit;
        inPrice=unitPrice;
    }
    string getName(){
        return name;
    }
    void setName(string n){
        name=n;
    }
    string getGenName(){
        return genericName;
    }
    void setGenName(string n){
        genericName=n;
    }
    double getUnitPrice(){
        return unitPrice;
    }
    void setUnitPrice(double p){
        unitPrice=p;
    }
    double getDiscountPercent(){
        return discountPercent;
    }
    void setDiscountPercent(double p){
        discountPercent=p;
    }
    double getSellingPrice(int nos){
        return nos*(unitPrice-(unitPrice*discountPercent)/100);
    }
    bool isAffordable(double budget){
        double cost=getSellingPrice(1);
        if(cost<=budget){
            return true;
        }
        else return false;
    }
    void resetPrice(){
        unitPrice=inPrice;
        cout<<"INITIAL PRICE WAS: "<<inPrice<<endl;
    }
    void display(){
        cout<<"NAME: "<<name<<endl;
        cout<<"GENERIC NAME: "<<genericName<<endl;
        cout<<"PRICE: "<<unitPrice<<endl;
        cout<<"DISCOUNT: "<<discountPercent<<endl;
    }
    ~Medicine(){}
};
int main(void){
    Medicine napa("napa", "para");
    Medicine v("viagra", "pop", 5);
    Medicine c("cough syrup", "syrup", 20);

    cout<<"discount would be "<<v.getSellingPrice(5)<<endl;
    if(napa.isAffordable(0)){
        cout<<"it's affordable"<<endl;
    }
    else cout<<"not affordable"<<endl;

    c.setUnitPrice(5);
    c.display();
    c.resetPrice();
}
