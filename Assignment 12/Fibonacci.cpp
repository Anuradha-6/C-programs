#include<iostream>
using namespace std;
int fib(int n){
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    return fib(n-1)+fib(n-2);
}
int main(){
    int n;
    cout<<"Enter the value of n\n";
    cin>>n;
    cout<<"The n th Fibonacci term = ";
    cout<<fib(n);
}
