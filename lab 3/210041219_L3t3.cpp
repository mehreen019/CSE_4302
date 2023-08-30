#include<bits/stdc++.h>
using namespace std;
class Time{
private:
    int hour;
    int minute;
    int second;
public:
    int hours(){
        return hour;
    }
    int minutes(){
        return minute;
    }
    int seconds(){
        return second;
    }
    void reset(int h,int m, int s){
        if(h<=24) hour=h;
        if(m<=60) minute=m;
        if(s<=60) second=s;
    }
    void advance(int h,int m,int s){
        hour=(hour+h)%24;
        if(m+minute>=60){
            hour=(hour+1)%24;
        }
        minute=(m+minute)%60;
        if(s+second>=60){
            if(1+minute>=60){
                hour=(hour+1)%24;
            }
            minute=(minute+1)%60;
        }
        second=(s+second)%60;
    }
    void print(){
        cout<<"HOUR:"<<hour<<" MINUTE:"<<minute<<" SECOND:"<<second<<endl;
    }

};




int main(void){
    int inh,inm,ins,h,m,s;
    cin>>inh>>inm>>ins>>h>>m>>s;

    Time cur;
    cur.reset(inh,inm,ins);
    cur.advance(h,m,s);
    cur.print();
}
