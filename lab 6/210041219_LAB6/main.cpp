#include <iostream>
#include "Counter.h"
#include "FLOAT.h"
#include "Coordinate.h"
#include "Matrix3D.h"

using namespace std;

int main()
{
    cout<<"\tTASK4"<<endl;
    Counter c1(0,6),c2(0,10),c3(0,5);
    c1= c2++;
    c1.display();
    c1= ++c3;
    c1.display();
    bool l= c1>=c2;
    cout<<"result for c1>=c2: "<<l<<endl;

    cout<<endl<<"\tTASK3"<<endl;
    FLOAT f1(5.57),f2(3.08);
    FLOAT f3= f1+f2;
    f3.display();
    int i=f3;
    cout<<"Converted value is: "<<i<<endl;
    bool anss= f1!=f2;
    cout<<"result for f1!=f2 is: "<<anss<<endl;

    cout<<endl<<"\tTASK2"<<endl;
    Coordinate p1(3,4),p2(7,8);
    cout<<"Distance is: "<<p1.getDistance(p2)<<endl;
    ++p1;
    p2++;
    p1.display();
    p2.display();
    bool k=p1<p2;
    cout<<"result for p1<p2 is: "<<k<<endl;

    cout<<endl<<"\tTASK1"<<endl;
    Matrix3D m,n,t;
    double x;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>x;
            m.setmat(i,j,x);
        }
    }
    n=m.inverse();
    n.display();
    t=n+m;
    t.display();
}
