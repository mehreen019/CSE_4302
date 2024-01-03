#ifndef CAR_H
#define CAR_H
#include "wheel.h"
#include "engine.h"
#include "door.h"
#include "seat.h"


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

#endif // CAR_H
