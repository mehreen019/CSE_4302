#include "door.h"

door::door()
{
    //ctor

}

door::door(bool op):op_mode(op)
{
    //ctor

}

void door::desc(){
    if(op_mode){
        cout<<"door is upward"<<endl;
    }
    else{
        cout<<"door is sideways"<<endl;
    }
}

door::~door()
{
    //dtor
}
