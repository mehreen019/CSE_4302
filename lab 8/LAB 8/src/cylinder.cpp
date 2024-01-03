#include "cylinder.h"

cylinder::cylinder()
{
    //ctor
}

cylinder::cylinder(double radius, double height):radius(radius),height(height){

}

cylinder::~cylinder()
{
    //dtor
}

double cylinder::surface_area(){
    return 2*3.1426*radius*height + 2*3.1416*pow(radius, 2);
}

double cylinder::volume(){
    return 3.1416*pow(radius,2)*height;
}

void cylinder::whoAmI(){
    std::cout<<"I am cylinder. I am a three-dimensional shape."<<std::endl;
    cout<<"surface_area: "<<surface_area()<<endl;
    cout<<"volume: "<<volume()<<endl;
}
