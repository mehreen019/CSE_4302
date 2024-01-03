#ifndef CYLINDER_H
#define CYLINDER_H

#include "three_dimensional_shape.h"



class cylinder : public three_dimensional_shape
{
    public:
        cylinder();
        cylinder(double radius, double height);
        virtual ~cylinder();

        double surface_area();
        double volume();

        double Getradius() { return radius; }
        void Setradius(double val) { radius = val; }
        double Getheight() { return height; }
        void Setheight(double val) { height = val; }

        void whoAmI();

    protected:

    private:
        double radius;
        double height;
};

#endif // CYLINDER_H
