#include<iostream>
using namespace std;

class door
{
    public:
        door();
        door(bool op);
        virtual ~door();

        bool Getop_mode() { return op_mode; }
        void Setop_mode(bool val) { op_mode = val; }

        void desc();

    protected:

    private:
        bool op_mode;
};

class engine
{
    public:
        engine();
        engine(double mfc, double mep, double ar);
        virtual ~engine();

        double Getmax_fuel_consumption() { return max_fuel_consumption; }
        void Setmax_fuel_consumption(double val) { max_fuel_consumption = val; }
        double Getmax_energy_produce() { return max_energy_produce; }
        void Setmax_energy_produce(double val) { max_energy_produce = val; }
        double Getavg_rpm() { return avg_rpm; }
        void Setavg_rpm(double val) { avg_rpm = val; }

        void desc();

    protected:

    private:
        double max_fuel_consumption;
        double max_energy_produce;
        double avg_rpm;
};

class seat
{
    public:
        seat();
        seat(string comf, bool sw);
        virtual ~seat();

        string Getcomfort() { return comfort; }
        void Setcomfort(string val) { comfort = val; }
        bool Getseat_warmer() { return seat_warmer; }
        void Setseat_warmer(bool val) { seat_warmer = val; }

        void desc();

    protected:

    private:
        string comfort;
        bool seat_warmer;
};

class wheel
{
    public:
        wheel();
        wheel(double radius);
        virtual ~wheel();

        double Getradius() { return radius; }
        void Setradius(double val) { radius = val; }

        double circumference();

        void desc();

    protected:

    private:
        double radius;
};

class car
{
    public:
        car();
        car(double max_acc, double fuel_cap);
        virtual ~car();

        double Getmax_acc() { return max_acc; }
        void Setmax_acc(double val) { max_acc = val; }
        double Getfuel_cap() { return fuel_cap; }
        void Setfuel_cap(double val) { fuel_cap = val; }

        void setData(string comf, bool sw, double radius, double mfc, double mep, double ar, bool op);
        void desc();

    protected:

    private:
        double max_acc;
        double fuel_cap;
        wheel Wheel;
        seat Seat;
        engine Engine;
        door Door;
};



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


wheel::wheel()
{
    //ctor
}

wheel::wheel(double radius):radius(radius){

}

wheel::~wheel()
{
    //dtor
}

void wheel::desc(){
    cout<<"circumference: "<<circumference()<<endl;
}

double wheel::circumference(){
    return 2*3.1416*radius;
}



int main(void){

    cout<<"\n\tTASK2"<<endl;
    car Car(45,56);
    Car.setData("pleasent", false, 55, 23, 2, 67, true);
    Car.desc();
}

