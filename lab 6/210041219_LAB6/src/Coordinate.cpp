#include "Coordinate.h"

Coordinate::Coordinate()
{
    //ctor
}

Coordinate::Coordinate(float x,float y):abscissa(x), ordinate(y){

}

Coordinate::~Coordinate()
{
    //dtor
}

float Coordinate::getDistance(Coordinate c){
    return std::sqrt(std::pow(std::abs(abscissa-c.abscissa), 2)+ std::pow(std::abs(ordinate-c.ordinate), 2));
}
float Coordinate::getDistance(){
    return std::sqrt(std::pow(abscissa, 2)+ std::pow(ordinate, 2));
}
void Coordinate::move_x(float val){
    abscissa+=val;
}
void Coordinate::move_y(float val){
    ordinate+=val;
}
void Coordinate::movee(float val){
    move_x(val);
    move_y(val);
}


bool Coordinate::operator>(Coordinate& c1){
    float dist1= getDistance();
    float dist2=c1.getDistance();
    bool ans=0;
    if(dist1>dist2) ans=1;
    else ans=0;
    return ans;
}

bool Coordinate::operator<(Coordinate& c1){
    float dist1= getDistance();
    float dist2=c1.getDistance();
    bool ans=0;
    if(dist1<dist2) ans=1;
    else ans=0;
    return ans;
}

bool Coordinate::operator>=(Coordinate& c1){
    float dist1= getDistance();
    float dist2=c1.getDistance();
    bool ans=0;
    if(dist1>=dist2) ans=1;
    else ans=0;
    return ans;
}

bool Coordinate::operator<=(Coordinate& c1){
    float dist1= getDistance();
    float dist2=c1.getDistance();
    bool ans=0;
    if(dist1<=dist2) ans=1;
    else ans=0;
    return ans;
}

bool Coordinate::operator==(Coordinate& c1){
    float dist1= getDistance();
    float dist2=c1.getDistance();
    bool ans=0;
    if(dist1==dist2) ans=1;
    else ans=0;
    return ans;
}

bool Coordinate::operator!=(Coordinate& c1){
    float dist1= getDistance();
    float dist2=c1.getDistance();
    bool ans=0;
    if(dist1!=dist2) ans=1;
    else ans=0;
    return ans;
}



void Coordinate::operator++(){
    ++abscissa;
    ++ordinate;
}

void Coordinate::operator++(int num=1){
    abscissa++;
    ordinate++;
}

void Coordinate::display(){
    std::cout<<"Abscissa is: "<<abscissa<<std::endl;
    std::cout<<"Ordinate is: "<<ordinate<<std::endl;
}
