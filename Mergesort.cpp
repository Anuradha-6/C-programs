#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the no. of elements in first array\n";
    cin>>n;
    int a[n];
    cout<<"Enter the no. of elements in second array\n";
    cin>>m;
    int b[m];
    cout<<"Enter the elements of 1 st array\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the elements of 2 nd array\n";
    for(int i=0;i<m;i++)
        cin>>b[i];
    int c[m+n];
    int i=0,j=0,k=0;
    while(i<n&&j<m){
        if(a[i]<b[j])
        {
            c[k++]=a[i];
            i++;
        }
        else
        {
            c[k++]=b[j];
            j++;
        }
    }
    while(i<n)
    {
        c[k++]=a[i];
        i++;
    }
    while(j<m)
    {
        c[k++]=b[j];
        j++;
    }
    cout<<"The merged array is\n";
    for(int i=0;i<m+n;i++)
        cout<<c[i]<<"  ";
}
