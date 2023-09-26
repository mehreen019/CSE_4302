#include "FLOAT.h"

FLOAT::FLOAT():data(0)
{
    //ctor
}

FLOAT::FLOAT(float data):data(data){

}

FLOAT::~FLOAT()
{
    //dtor
}

FLOAT FLOAT::operator+(const FLOAT& f){
    data+=f.data;
    return FLOAT(data);
}

FLOAT FLOAT::operator=(const FLOAT& f){
    data=f.data;
    return FLOAT(data);
}

FLOAT FLOAT::operator*(const FLOAT& f){
    data*=f.data;
    return FLOAT(data);
}

FLOAT FLOAT::operator/(const FLOAT& f){
    data/=f.data;
    return FLOAT(data);
}

FLOAT FLOAT::operator-(const FLOAT& f){
    data-=f.data;
    return FLOAT(data);
}

FLOAT::operator float(){
    float temp= data;
    return data;
}

void FLOAT::display(){
    std::cout<<"data is: "<<data<<std::endl;
}

