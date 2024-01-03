#include<bits/stdc++.h>
using namespace std;
const int maxx=100;

template<class type>
class stackk{
private:
    type st[maxx];
    int top;
    type first;
public:
    class rangeErr{};

    stackk():top(-1){}
    void push(type a){
        st[++top]=a;
        if(top==0){
            first=a;
        }
    }
    type pop(){
        if(top==-1){
            throw rangeErr();
        }
        return st[top--];
    }
    type peek(){

        return first;
    }
};

template<class element>
element nth_max(element* temp, element n){
    int sz=0;
    for(int i=0;;i++){
        if(temp[sz]==NULL) break;
        else sz++;
    }

    sort(temp, temp+sz);
    return temp[n-1];
}

int main(void){
    cout<<"\t TASK 1\n\n";
    stackk<int> st1;
    st1.push(1);
    st1.push(3);
    st1.push(5);
    cout<<"\tfirst stack\n";
    cout<<"popping: "<<st1.pop()<<endl;
    cout<<"first element: "<<st1.peek()<<endl;

    stackk<double> st2;
    st2.push(0.834);
    st2.push(94.2938);
    st2.push(4.5);

    cout<<"\n\tsecond stack\n";
    cout<<"popping: "<<st2.pop()<<endl;
    cout<<"first element: "<<st2.peek()<<endl;

    cout<<"\n\t TASK 2\n\n";
    int arr[]={5,4,3,2,1};
    cout<<"nth greatest element is: "<<nth_max(arr, 4)<<endl;

    cout<<"\n\t TASK 3\n\n";
    try{
        cout<<st2.pop()<<endl;
        cout<<st2.pop()<<endl;
        cout<<st2.pop()<<endl;
    }
    catch(stackk<double>::rangeErr){
        cout<<"no more elements to pop"<<endl;
    }

    try{
        cout<<st1.pop()<<endl;
        cout<<st1.pop()<<endl;
        cout<<st1.pop()<<endl;
    }
    catch(stackk<int>::rangeErr){
        cout<<"no more elements to pop"<<endl;
    }
}
