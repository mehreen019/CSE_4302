#include<iostream>
using namespace std;

class RationalNumber{
private:
    int numerator;
    int denominator;
public:
    void assignn(int a, int b){
        numerator=a;
        if(b==0){
            cout<<"ERROR: DENOMINATOR IS INVALID"<<endl;
            val=0;
        }
        else denominator=b;
    }

    double convert(){
        return (double)numerator/(double)denominator;
    }
    void invert(){
        int temp=numerator;
        numerator=denominator;
        if(temp!=0){
            denominator=temp;
        }
        else{
            cout<<"ERROR: DENOMINATOR IS INVALID"<<endl;
            val=0;
        }
    }
    void print(){
        cout<<"The  rational number is "<<numerator<<"/"<<denominator<<endl;
    }
    bool val=1;
};

int main(void){
    int num,denom;
    cin>>num>>denom;

    RationalNumber obj;
    obj.assignn(num,denom);
    if(obj.val) obj.print();
    if(obj.val) cout<<obj.convert()<<endl;
    if(obj.val) obj.invert();
    if(obj.val) obj.print();
}
