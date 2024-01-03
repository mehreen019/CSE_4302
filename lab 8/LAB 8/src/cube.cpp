#include "cube.h"

cube::cube()
{
    //ctor
}

cube::cube(double side_length):length(side_length){

}

double cube::surface_area(){
    return 6*length*length;
}

double cube::volume(){
    return pow(length,3);
}

void cube::whoAmI(){
    cout<<"I am cube. I am a three-dimensional shape."<<endl;
    cout<<"surface_area: "<<surface_area()<<endl;
    cout<<"volume: "<<volume()<<endl;
}

cube::~cube()
{
    //dtor
}
