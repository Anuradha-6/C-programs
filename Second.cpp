#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the no. of elements"<<"\n";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int s=arr[0],l=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>l)
            l=arr[i];
        if(arr[i]<s)
            s=arr[i];
    }
    cout<<"Largest number="<<l<<"\n";
    cout<<"Smallest number="<<s<<"\n";
    return 0;
}
