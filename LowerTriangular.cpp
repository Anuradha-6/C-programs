#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the no. of rows/columns\n";
    cin>>n;
    int arr[n][n];
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<j)
                cout<<0<<"  ";
            else
                cout<<arr[i][j]<<"  ";
        }
        cout<<"\n";
    }
}
