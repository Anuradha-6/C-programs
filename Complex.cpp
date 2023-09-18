#include<iostream>
#include<stdlib.h>
using namespace std;
class Complex{
public:
    int real;
    int imag;
    Complex(){
        real=0;
        imag=0;
    }
    Complex(int a,int b){
        real=a;
        imag=b;
    }
    Complex(const Complex &c){
        real=c.real;
        imag=c.imag;
    }
    void set(int a,int b)
    {
        real=a;
        imag=b;
    }
    void display(){
        cout<<real<<"+i "<<imag<<"\n";
    }
    Complex sum(Complex c)
    {
        Complex t;
        t.real=real+c.real;
        t.imag=imag+c.imag;
        return t;
    }
};
int main(){
    Complex c1;
    int r,i;
    cout<<"Enter the first complex no.\n";
    cin>>r;
    cin>>i;
    c1.set(r,i);
    cout<<"Enter the second complex no. \n";
    cin>>r;
    cin>>i;
    Complex c2(r,i);
    Complex c3;
    c3=c1.sum(c2);
    c1.display();
    c2.display();
    c3.display();
}
