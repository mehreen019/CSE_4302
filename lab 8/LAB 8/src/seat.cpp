#include "seat.h"

seat::seat()
{
    //ctor
}

seat::seat(string comf, bool sw):comfort(comf), seat_warmer(sw){

}

void seat::desc(){
    cout<<"comfort: "<<comfort<<endl;
    cout<<"seat_warmer: "<<seat_warmer<<endl;
}

seat::~seat()
{
    //dtor
}
