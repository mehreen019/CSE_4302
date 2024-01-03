#ifndef THREE_DIMENSIONAL_SHAPE_H
#define THREE_DIMENSIONAL_SHAPE_H

#include <shape.h>


class three_dimensional_shape : public shape
{
    public:
        three_dimensional_shape();
        virtual ~three_dimensional_shape();

        double surface_area();
        double volume();

        void whoAmI();

    protected:

    private:
        double Surfacearea;
        double Volume;
};

#endif // THREE_DIMENSIONAL_SHAPE_H
