#ifndef CIRCLE_H
#define CIRCLE_H

#include "two_dimensional_shape.h"


class circle : public two_dimensional_shape
{
    public:
        circle();
        circle(double radius);
        virtual ~circle();

        double area();
        double perimeter();

        double Getradius() { return radius; }
        void Setradius(double val) { radius = val; }

        void whoAmI();

    protected:

    private:
        double radius;
};

#endif // CIRCLE_H
