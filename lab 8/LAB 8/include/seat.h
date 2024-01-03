#ifndef SEAT_H
#define SEAT_H
#include<iostream>
using namespace std;

class seat
{
    public:
        seat();
        seat(string comf, bool sw);
        virtual ~seat();

        string Getcomfort() { return comfort; }
        void Setcomfort(string val) { comfort = val; }
        bool Getseat_warmer() { return seat_warmer; }
        void Setseat_warmer(bool val) { seat_warmer = val; }

        void desc();

    protected:

    private:
        string comfort;
        bool seat_warmer;
};

#endif // SEAT_H
