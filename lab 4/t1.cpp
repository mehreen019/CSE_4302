#include<bits/stdc++.h>
using namespace std;
class product{
private:
    string name;
    int id;
    int price;
    int quantity;
    int maxq;
    bool available;

public:
    static int total_value;
    product():name("null"),id(0),price(0),quantity(0),available(true),maxq(2000){
        addTotal(price,quantity);
    }
    product(string n, int i, int p, int q):available(true),maxq(2000){
        name=n;
        id=i;
        price=p;
        quantity=q;
        addTotal(price,quantity);
    }
    string getName(){
        return name;
    }
    void setName(string n){
        name=n;
    }
    int getID(){
        return id;
    }
    void setID(int i){
        id=i;
    }
    int getPrice(){
        return price;
    }
    void setPrice(int p){
        subTotal(price,quantity);
        addTotal(p,quantity);
        price=p;
    }
    int getQuantity(){
        return quantity;
    }
    void setQuantity(int q){
        subTotal(price,quantity);
        addTotal(price,q);
        quantity=q;
    }
    void setMaxQuantity(int mq){
        maxq=mq;
    }
    void addToInventory(int add){
        if(quantity+add<=maxq){
            addTotal(price,add);
            quantity+=add;
        }
        //else quantity=maxq;
    }
    bool isAvailable(){
        if(quantity==0) available=false;
        return available;
    }
    void purchase(int pur_q){
        if(quantity-pur_q>=0){
            quantity-=pur_q;
            subTotal(price,pur_q);
            if(quantity==0) available=false;
        }
        else cout<<"ITEM NOT AVAILABLE IN REQUIRED AMOUNT"<<endl;
    }
    int updatePrice(int percent){
        return price=price+(price*percent)/100;
    }
    void displayInventoryValue(){
        cout<<"INVENTORY VALUE IS: "<<quantity*price<<endl;
    }
    void displayDetails(){
        cout<<"NAME: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"PRICE: "<<price<<endl;
        cout<<"QUANTITY: "<<quantity<<endl;
        if(quantity>0){
            available=true;
            cout<<"AVAILABLE"<<endl;
        }
        else cout<<"NOT AVAILABLE"<<endl;
    }
    static void addTotal(int p, int q){
        total_value+=p*q;
    }
    static void subTotal(int p, int q){
        total_value-=p*q;
    }
    static void displayTotalInventoryValue(){
        cout<<"TOTAL VALUE OF ALL PRODUCTS: "<<total_value<<endl;
    }
    ~product(){}
};

int product::total_value=0;
int main(void){
    product milk("milk", 1, 1, 20);

    product choco;
    choco.setName("choco");
    choco.setPrice(2);
    choco.setQuantity(2);

    product egg("egg", 3, 5, 1);
    egg.setMaxQuantity(5);
    egg.addToInventory(5);
    egg.addToInventory(4);

    milk.displayDetails();
    choco.displayDetails();
    egg.displayDetails();

    product::displayTotalInventoryValue();
}
