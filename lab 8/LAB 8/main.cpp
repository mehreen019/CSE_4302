#include<iostream>
#include "rectangle.h"
#include "circle.h"
#include "cube.h"
#include "cylinder.h"
#include "car.h"
using namespace std;

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


    cout<<"\n\tTASK2"<<endl;
    car Car(45,56);
    Car.setData("pleasent", false, 55, 23, 2, 67, true);
    Car.desc();
}
