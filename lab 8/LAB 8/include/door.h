#ifndef DOOR_H
#define DOOR_H
#include<iostream>
using namespace std;

class door
{
    public:
        door();
        door(bool op);
        virtual ~door();

        bool Getop_mode() { return op_mode; }
        void Setop_mode(bool val) { op_mode = val; }

        void desc();

    protected:

    private:
        bool op_mode;
};

#endif // DOOR_H
