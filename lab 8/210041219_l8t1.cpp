#include<iostream>
#include<math.h>
using namespace std;

class shape
{
    public:
        shape();
        ~shape();

        void whoAmI();

    protected:

    private:

};

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

class circle : public two_dimensional_shape
{
    public:
        circle();
        circle(double radius);
        virtual ~circle();

        double area();
        double perimeter();

        double Getradius() { return radius; }
        void Setradius(double val) { radius = val; }

        void whoAmI();

    protected:

    private:
        double radius;
};

two_dimensional_shape::two_dimensional_shape()
{

}

two_dimensional_shape::~two_dimensional_shape()
{
    //dtor
}

shape::shape()
{
    //ctor
}

shape::~shape(){

}

rectangle::rectangle()
{
    //ctor
}

rectangle::rectangle(double length, double width):length(length), width(width)
{
    //ctor
}

rectangle::~rectangle()
{
    //dtor
}

double rectangle::area(){
    return length*width;
}

double rectangle::perimeter(){
    return 2*(length+width);
}

void rectangle::whoAmI(){
    std::cout<<"I am rectangle. I am a two-dimensional shape."<<std::endl;
    cout<<"Area: "<<area()<<endl;
    cout<<"Perimeter: "<<perimeter()<<endl;
}

cube::cube()
{
    //ctor
}

cube::cube(double side_length):length(side_length){

}

double cube::surface_area(){
    return 6*length*length;
}

double cube::volume(){
    return pow(length,3);
}

void cube::whoAmI(){
    cout<<"I am cube. I am a three-dimensional shape."<<endl;
    cout<<"surface_area: "<<surface_area()<<endl;
    cout<<"volume: "<<volume()<<endl;
}

cube::~cube()
{
    //dtor
}

circle::circle()
{
    //ctor
}

circle::circle(double radius):radius(radius)
{
    //ctor
}

double circle::area(){
    return radius*radius*3.1416;
}

double circle::perimeter(){
    return 2*3.1416*radius;
}

void circle::whoAmI(){
    std::cout<<"I am circle I am a two-dimensional shape."<<std::endl;
    cout<<"Area: "<<area()<<endl;
    cout<<"Perimeter: "<<perimeter()<<endl;
}

circle::~circle()
{
    //dtor
}

three_dimensional_shape::three_dimensional_shape()
{
    //ctor
}

three_dimensional_shape::~three_dimensional_shape()
{
    //dtor
}

cylinder::cylinder()
{
    //ctor
}

cylinder::cylinder(double radius, double height):radius(radius),height(height){

}

cylinder::~cylinder()
{
    //dtor
}

double cylinder::surface_area(){
    return 2*3.1426*radius*height + 2*3.1416*pow(radius, 2);
}

double cylinder::volume(){
    return 3.1416*pow(radius,2)*height;
}

void cylinder::whoAmI(){
    std::cout<<"I am cylinder. I am a three-dimensional shape."<<std::endl;
    cout<<"surface_area: "<<surface_area()<<endl;
    cout<<"volume: "<<volume()<<endl;
}

int main(void){

    cout<<"\tTASK1"<<endl;
    rectangle r(5,6);
    circle c(5);
    cylinder cy(2, 8);
    cube cu(6);
    r.whoAmI();
    c.whoAmI();
    cy.whoAmI();
    cu.whoAmI();
}
