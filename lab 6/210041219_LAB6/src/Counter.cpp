#include "Counter.h"

Counter::Counter():Count(0), increment_step(1)
{
    //ctor
}

Counter::Counter(int countt, int increment):Count(countt),increment_step(increment)
{

}

Counter::~Counter()
{
    //dtor
}

void Counter::set_increment_step(int val){
    if(val>=0){
        increment_step=val;
    }
    else{
        increment_step=1;
    }
}

void Counter::increment(){
    Count+=increment_step;
}

Counter Counter::operator+(const Counter& c1) const{
    int countt=Count+c1.Count;
    int incrementt=increment_step+c1.increment_step;

    return Counter(countt, incrementt);
}

bool Counter::operator>(const Counter& c) const
{
    bool l;
    if(Count>c.Count) l=1;
    else l=0;

    return l;
}

bool Counter::operator<(const Counter& c) const
{
    bool l;
    if(Count<c.Count) l=1;
    else l=0;

    return l;
}

bool Counter::operator>=(const Counter& c) const
{
    bool l;
    if(Count>=c.Count) l=1;
    else l=0;

    return l;
}

bool Counter::operator<=(const Counter& c) const
{
    bool l;
    if(Count<=c.Count) l=1;
    else l=0;

    return l;
}

bool Counter::operator==(const Counter& c) const
{
    bool l;
    if(Count==c.Count) l=1;
    else l=0;

    return l;
}

bool Counter::operator!=(const Counter& c) const
{
    bool l;
    if(Count!=c.Count) l=1;
    else l=0;

    return l;
}

void Counter::operator+=(const Counter& c)
{
    Count+=c.Count;
    increment_step=std::max(increment_step, c.increment_step);
}

Counter Counter::operator++(int num=1)
{
    Count+=increment_step;
    return Counter(Count, increment_step);
}

void Counter::operator=(const Counter& c)
{
    Count=c.Count;
    increment_step=std::max(increment_step, c.increment_step);
}

Counter Counter::operator++(){
    Count+=increment_step;
    return  Counter(Count, increment_step);
}

void Counter::display(){
    std::cout<<"Count: "<<Count<<std::endl;
    std::cout<<"I_S_: "<<increment_step<<std::endl;
}




