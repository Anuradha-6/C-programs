#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int m,n,p,q;
    cout<<"Enter the size of first array\n";
    cin>>m;
    cin>>n;
    int a[m][n];
    cout<<"Enter the elements of first array\n";
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    cout<<"Enter the size of second array\n";
    cin>>p;
    cin>>q;
    int b[p][q];
    cout<<"Enter the elements of second array\n";
    for(int i=0;i<p;i++)
        for(int j=0;j<q;j++)
            cin>>b[i][j];
    if(n!=p)
    {
        cout<<"Multiplication not possible\n";
        exit(0);
    }
    int c[m][q];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<p;j++)
        {
            c[i][j]=0;
            for(int k=0;k<n;k++)
                c[i][j]+=a[i][j]*b[i][j];
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<q;j++)
        {
            cout<<c[i][j]<<"    ";
        }
        cout<<"\n";
    }
    return 0;
}
