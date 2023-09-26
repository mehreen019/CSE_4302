#ifndef COUNTER_H
#define COUNTER_H
#include<iostream>

class Counter
{
    public:
        Counter();
        Counter(int countt, int increment);
        virtual ~Counter();

        //member functions
        int getCount() { return Count; }
        void resetCount(int val) { Count = 0; }
        void set_increment_step(int val);
        void increment();

        //operator overload
        Counter operator+(const Counter& c1) const;
        bool operator>(const Counter& c1) const;
        bool operator<(const Counter& c1) const;
        bool operator>=(const Counter& c1) const;
        bool operator<=(const Counter& c1) const;
        bool operator==(const Counter& c1) const;
        bool operator!=(const Counter& c1) const;
        void operator+=(const Counter& c);
        Counter operator++(int num=1);
        void operator=(const Counter& c);
        Counter operator++();

        //display
        void display();

    private:
        int Count;
        int increment_step;
};

#endif // COUNTER_H
