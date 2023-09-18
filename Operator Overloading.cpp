#include<iostream>
using namespace std;
class Complex{
    int real;
    int imag;
public:
    Complex();
    Complex(int,int);
    Complex(const Complex &c);
    void display();
    Complex operator +(Complex);
    Complex operator =(Complex);
    Complex operator -(Complex);
    Complex operator *(Complex);

};
Complex:: Complex(){
    real=imag=0;
}
Complex:: Complex(int a, int b){
    real=a;
    imag=b;
}
Complex::Complex(const Complex &c){
    real=c.real;
    imag=c.imag;
}
void Complex::display(){
    cout<<real<<" +i"<<imag<<"\n";
}
Complex Complex:: operator+(Complex c){
    Complex temp;
    temp.real=real+c.real;
    temp.imag=imag+c.imag;
    return temp;
}
Complex Complex:: operator =(Complex c){
    real=c.real;
    imag=c.imag;
    return(*this);
}
Complex Complex:: operator -(Complex c){
    Complex temp;
    temp.real=real-c.real;
    temp.imag=imag-c.imag;
    return temp;
}
Complex Complex:: operator *(Complex c){
    Complex temp;
    temp.real=real*c.real-imag*c.imag;
    temp.imag=imag*c.real+real*c.imag;
    return temp;
}
int main(){
    int a,b,c,d;
    cout<<"Enter the value of real part of first number\n";
    cin>>a;
    cout<<"Enter the value of complex part of first number\n";
    cin>>b;
    cout<<"Enter the value of real part of second number\n";
    cin>>c;
    cout<<"Enter the value of complex part of second number\n";
    cin>>d;
    Complex c1(a,b),c2(c,d);
    Complex c3;
    Complex c4;
    Complex c5;
    Complex c6;
    c1.display();
    c2.display();
    c3.operator =(c1.operator+(c2));
    c4.operator =(c1.operator-(c2));
    c5.operator =(c1.operator* (c2));
    c6.operator =(c1.operator+(c2.operator*(c3)));
    cout<<"Sum:\n";
    c3.display();
    cout<<"Difference:\n";
    c4.display();
    cout<<"Product:\n";
    c5.display();
    cout<<"c1+c2*c3=";
    c6.display();
}
