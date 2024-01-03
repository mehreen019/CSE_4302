#ifndef TWO_DIMENSIONAL_SHAPE_H
#define TWO_DIMENSIONAL_SHAPE_H

#include <shape.h>


class two_dimensional_shape : public shape
{
    public:
        two_dimensional_shape();
        virtual ~two_dimensional_shape();

        double area();
        double perimeter();

        void whoAmI();

    protected:

    private:
        double Area;
        double Perimeter;

};

#endif // TWO_DIMENSIONAL_SHAPE_H
