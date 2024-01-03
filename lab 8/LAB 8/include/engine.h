#ifndef ENGINE_H
#define ENGINE_H
#include<iostream>
using namespace std;


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

#endif // ENGINE_H
