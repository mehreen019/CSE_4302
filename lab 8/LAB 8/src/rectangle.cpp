#include "rectangle.h"

rectangle::rectangle()
{
    //ctor
}

rectangle::rectangle(double length, double width):length(length), width(width)
{
    //ctor
}

rectangle::~rectangle()
{
    //dtor
}

double rectangle::area(){
    return length*width;
}

double rectangle::perimeter(){
    return 2*(length+width);
}

void rectangle::whoAmI(){
    std::cout<<"I am rectangle. I am a two-dimensional shape."<<std::endl;
    cout<<"Area: "<<area()<<endl;
    cout<<"Perimeter: "<<perimeter()<<endl;
}
