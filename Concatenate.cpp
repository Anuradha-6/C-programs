#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cout<<"Enter the number of rows and columns\n";
    cin>>m;
    cin>>n;
    int a[m][n],b[m][n];
    int c[m][n+n];
    cout<<"Enter the elements of first matrix\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<"Enter the elements of second matrix\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>b[i][j];
        }
    }
    for(int i=0;i<m;i++){
        int x=0;
        for(int j=0;j<n;j++){
            c[i][j]=a[i][j];
        }
        for(int j=n;j<n+n;j++){
            c[i][j]=b[i][x];
            x++;
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n+n;j++)
        {
           cout<<c[i][j]<<"  ";
        }
        cout<<"\n";
    }

}
