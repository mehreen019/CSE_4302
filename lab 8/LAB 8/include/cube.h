#ifndef CUBE_H
#define CUBE_H

#include "three_dimensional_shape.h"


class cube : public three_dimensional_shape
{
    public:
        cube();
        cube(double side_length);
        virtual ~cube();

        double surface_area();
        double volume();

        double Getlength() { return length; }
        void Setlength(double val) { length = val; }

        void whoAmI();

    protected:

    private:
        double length;
};

#endif // CUBE_H
