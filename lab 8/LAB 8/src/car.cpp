#include "car.h"

car::car()
{
    //ctor
}

car::car(double max_acc, double fuel_cap):max_acc(max_acc),fuel_cap(fuel_cap){

}

void car::setData(string comf, bool sw, double rad, double mfc, double mep, double ar, bool op){
    Seat.Setcomfort(comf);
    Seat.Setseat_warmer(sw);
    Wheel.Setradius(rad);
    Engine.Setmax_fuel_consumption(mfc);
    Engine.Setmax_energy_produce(mep);
    Engine.Setavg_rpm(ar);
    Door.Setop_mode(op);
    cout<<"max_acceleration: "<<max_acc<<endl;
    cout<<"fuel_capacity: "<<fuel_cap<<endl;
}

void car::desc(){
    Engine.desc();
    Seat.desc();
    Wheel.desc();
    Door.desc();
}

car::~car()
{
    //dtor
}
