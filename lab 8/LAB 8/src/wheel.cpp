#include "wheel.h"

wheel::wheel()
{
    //ctor
}

wheel::wheel(double radius):radius(radius){

}

wheel::~wheel()
{
    //dtor
}

void wheel::desc(){
    cout<<"circumference: "<<circumference()<<endl;
}

double wheel::circumference(){
    return 2*3.1416*radius;
}
