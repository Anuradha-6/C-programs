#include<stdio.h>
#include<iostream>
#define MAX 20
using namespace std;
int main()
{
    int m,n;
    cout<<"Enter the rows and columns\n";
    cin>>m;
    cin>>n;
    int a[m][n];
    cout<<"Enter the elements of the matrix\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int s[MAX][3];
    a[m][n];
    s[0][0]=m;
    s[0][1]=n;
    int k=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]!=0)
            {
                s[k][0]=i;
                s[k][1]=j;
                s[k][2]=a[i][j];
                k++;
            }
        }
    }
    s[0][2]=k-1;
    for(int i=0;i<s[0][2];i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<s[i][j]<<"  ";
        }
        cout<<"\n";
    }

}
