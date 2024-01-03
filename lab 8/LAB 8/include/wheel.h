#ifndef WHEEL_H
#define WHEEL_H
#include<iostream>
using namespace std;

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

#endif // WHEEL_H
