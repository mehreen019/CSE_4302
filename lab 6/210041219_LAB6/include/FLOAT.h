#ifndef FLOAT_H
#define FLOAT_H
#include<iostream>

class FLOAT
{
    public:
        FLOAT();
        FLOAT(float data);
        virtual ~FLOAT();

        FLOAT operator+(const FLOAT& f);
        FLOAT operator=(const FLOAT& f);
        FLOAT operator-(const FLOAT& f);
        FLOAT operator*(const FLOAT& f);
        FLOAT operator/(const FLOAT& f);
        operator float();

        void display();

    private:
        float data;
};

#endif // FLOAT_H
