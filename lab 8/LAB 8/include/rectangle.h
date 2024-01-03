#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "two_dimensional_shape.h"


class rectangle : public two_dimensional_shape
{
    public:
        rectangle();
        rectangle(double length, double width);
        virtual ~rectangle();


        double area();
        double perimeter();

        double Getlength() { return length; }
        void Setlength(double val) { length = val; }
        double Getwidth() { return width; }
        void Setwidth(double val) { width = val; }

        void whoAmI();

    protected:

    private:
        double length;
        double width;
};

#endif // RECTANGLE_H
