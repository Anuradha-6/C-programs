#include<stdio.h>
#include<iostream>
#define n 3
using namespace std;
void Add(int x[][n],int y[][n],int z[][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            z[i][j]=x[i][j]+y[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        cout<<z[i][j]<<"  ";
        }
        cout<<"\n";
    }
}
int main()
{
    int a[n][n];
    int b[n][n];
    int c[n][n];
    cout<<"Enter the array elements of A\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<"Enter the array elements of B\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>b[i][j];
        }
    }
    Add(a,b,c);
}
