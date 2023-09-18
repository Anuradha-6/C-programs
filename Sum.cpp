#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter the numbers"<<"\n";
    cin>>num;
    int sum=0;
    while(num>0){
        int d=num%10;
        sum+=d;
        num=num/10;
    }
    cout<<"Sum of digits="<<sum<<"\n";
    return 0;
}
