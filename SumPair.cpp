#include <stdio.h>
#include<iostream>
using namespace std;
int main(){
    int n,s=0;
    cout<<"Enter the no. of elements\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the given sum\n";
    cin>>s;
    cout<<"The pairs are:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==s)
                cout<<arr[i]<<"  "<<arr[j]<<"\n";
        }
    }
}
