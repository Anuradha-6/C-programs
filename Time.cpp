#include<iostream>
#include<stdlib.h>
using namespace std;
class Time{
public:
    int hour;
    int mins;
    void setTime(int a,int b){
        hour=a;
        mins=b;
    }
    void showTime(){
        cout<<hour<<" hours "<<mins<<" minutes\n";
    }
    Time add(Time a){
        Time x;
        x.mins=mins+a.mins;
        x.hour=hour+a.hour;
        if(x.mins>=60){
            x.hour=x.hour+(x.mins/60);
            x.mins=x.mins%60;
        }
        return x;
    }
};
int main(){
    Time t1;
    Time t2;
    Time t3;
    int h,m;
    cout<<"Enter the first time\n";
    cin>>h;
    cin>>m;
    t1.setTime(h,m);
    cout<<"Enter the second time\n";
    cin>>h;
    cin>>m;
    t2.setTime(h,m);
    t3=t1.add(t2);
    t1.showTime();
    t2.showTime();
    cout<<"The added time is: \n";
    t3.showTime();
}
