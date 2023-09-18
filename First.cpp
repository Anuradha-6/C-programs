//Inserting a number at a given position in an array
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements"<<"\n";
    cin>>n;
    int arr[n+1];
    cout<<"Enter the array elements"<<"\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the position"<<"\n";
    int k;
    cin>>k;
    cout<<"Enter the number to be inserted"<<"\n";
    int num;
    cin>>num;
    int temp=0;
    for(int i=n;i>k-1;i--)
    {
        temp=arr[i];
        arr[i]=arr[i-1];
        arr[i-1]=temp;
    }
    arr[k-1]=num;
    for(int i=0;i<n+1;i++)
        cout<<arr[i]<<"  ";
}




