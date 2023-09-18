#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int first=0,second=0;
    int n;
    cout<<"Enter the number of elements"<<"\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements"<<"\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
        first=max(first,arr[i]);
    for(int i=0;i<n;i++){
        if(arr[i]!=first)
        second=max(second,arr[i]);
    }
    cout<<"Largest number="<<first<<"\n";
    cout<<"Second largest number="<<second<<"\n";
}
int max(int a,int b)
{
    return(a>b?a:b);
}
