#include<stdio.h>
#include<iostream>
#define n 3
using namespace std;
int isSame(int x[n][n],int y[n][n])
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(x[i][j]!=y[i][j])
                return 0;
        }
    }
    return 1;
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
    cout<<"Enter the array elements of B\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>b[i][j];
        }
    }
    if(isSame(a,b))cout<<"Yes, the two matrices are identical";
    else cout<<"No,the two matrices are not identical";
}
