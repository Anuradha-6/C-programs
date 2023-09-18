#include<stdio.h>;
#include<iostream>;
using namespace std;
double volume(double a){
    double v=a*a*a;
    return v;
}
double volume(double a,double b){
    double v=3.14*a*a*b;
    return v;
}
double volume(double a,double b,double c){
    double v=a*b*c;
    return v;
}
int main(){
    double a,r,h,l,b,g;
    cout<<"Enter the side of cube\n";
    cin>>a;
    cout<<"Volume of cube= "<<volume(a)<<"\n";
    cout<<"Enter the radius and height of cylinder\n";
    cin>>r;
    cin>>h;
    cout<<"Volume of cylinder= "<<volume(r,h)<<"\n";
    cout<<"Enter the length, breadth and height of rectangular box\n";
    cin>>l;
    cin>>b;
    cin>>g;
    cout<<"Volume of rectangular box= "<<volume(l,b,g)<<"\n";
}
