#ifndef COORDINATE_H
#define COORDINATE_H
#include<iostream>
#include<math.h>

class Coordinate
{
    public:
        Coordinate();
        Coordinate(float x, float y);
        virtual ~Coordinate();

        float Getabscissa() { return abscissa; }
        void Setabscissa(float val) { abscissa = val; }
        float Getordinate() { return ordinate; }
        void Setordinate(float val) { ordinate = val; }
        float getDistance(Coordinate c);
        float getDistance();
        void move_x(float val);
        void move_y(float val);
        void movee(float val);

        bool operator>(Coordinate& c1);
        bool operator<(Coordinate& c1);
        bool operator>=(Coordinate& c1);
        bool operator<=(Coordinate& c1);
        bool operator==(Coordinate& c1);
        bool operator!=(Coordinate& c1);

        void operator++();
        void operator++(int num=1);

        void display();


    private:
        float abscissa;
        float ordinate;
};

#endif // COORDINATE_H
