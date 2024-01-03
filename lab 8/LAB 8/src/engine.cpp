#include "engine.h"

engine::engine()
{
    //ctor
}

engine::engine(double mfc, double mep, double ar):max_fuel_consumption(mfc), max_energy_produce(mep), avg_rpm(ar){

}

engine::~engine()
{
    //dtor
}

void engine::desc(){
    cout<<"max_fuel_consumption: "<<max_fuel_consumption<<endl;
    cout<<"max_energy_produce: "<<max_energy_produce<<endl;
    cout<<"avg_rpm: "<<avg_rpm<<endl;
}
