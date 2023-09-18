#include<stdio.h>
#include<iostream>
#define n 3
using namespace std;
void transpose(int x[n][n],int y[n][n])
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            y[i][j]=x[j][i];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                cout<<y[i][j]<<"  ";
        }
        cout<<"\n";
    }
}
int main()
{
    int a[n][n];
    int b[n][n];
    cout<<"Enter the array elements of A\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    transpose(a,b);
}
