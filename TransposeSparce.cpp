#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the no. of rows\n";
    cin>>n;
    int s[n][3];
    cout<<"Enter the elements\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>s[i][j];
        }
    }
    int t[n][3];
    t[0][0]=s[0][1];
    t[0][1]=s[0][0];
    t[0][2]=s[0][2];
    int k=1;
    for(int i=0;i<s[0][1];i++){
        for(int j=1;j<=s[0][2];j++){
            if(i==s[j][1]){
                t[k][0]=i;
                t[k][1]=s[j][0];
                t[k][2]=s[j][2];
                k++;
            }
        }
    }
    cout<<"Transpose is:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cout<<t[i][j]<<"  ";
        }
        cout<<"\n";
    }
}
