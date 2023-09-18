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
    int even=0,odd=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==0)
            even+=arr[i];
        else
            odd+=arr[i];
    }
    cout<<"Sum of even="<<even<<"\n";
    cout<<"Sum of odd="<<odd<<"\n";
    return 0;
}
