#include "circle.h"

circle::circle()
{
    //ctor
}

circle::circle(double radius):radius(radius)
{
    //ctor
}

double circle::area(){
    return radius*radius*3.1416;
}

double circle::perimeter(){
    return 2*3.1416*radius;
}

void circle::whoAmI(){
    std::cout<<"I am circle I am a two-dimensional shape."<<std::endl;
    cout<<"Area: "<<area()<<endl;
    cout<<"Perimeter: "<<perimeter()<<endl;
}

circle::~circle()
{
    //dtor
}
