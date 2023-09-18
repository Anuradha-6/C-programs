#include<stdio.h>
#include<iostream>
#define MAX 3
using namespace std;
void readSparse(){
int r;
cout<<"Enter the no. of rows in sparce matrix\n";
cin>>r;
int a[r][3];
cout<<"Enter the values in sparce matrix\n";
for(int i=0;i<r;i++){
    for(int j=0;j<3;j++){
        cin>>a[i][j];
    }
}
cout<<"Printing the sparse matrix:\n";
for(int i=0;i<=a[0][2];i++){
    for(int j=0;j<3;j++){
        cout<<a[i][j]<<"  ";
    }
    cout<<"\n";
}
}
void addSparse(int a[][3],int b[][3],int c[][3]){
if(a[0][0]!=b[0][0]||a[0][1]!=b[0][1]){
    cout<<"Addition operation cannot be performed\n";
    exit(0);
}
c[0][0]=a[0][0];
c[0][1]=a[0][1];
int k=1;int i=1;int j=1;
while(i<=a[0][2]&&j<=b[0][2]){
    if(a[i][0]<b[j][0]){
        c[k][0]=a[i][0];
        c[k][1]=a[i][1];
        c[k][2]=a[i][2];
        k++;i++;
    }
    else if(a[i][0]>b[j][0]){
        c[k][0]=b[j][0];
        c[k][1]=b[k][1];
        c[k][2]=b[k][2];
        k++;j++;
    }
    else if(a[i][j]<b[j][i]){
        c[k][0]=a[i][0];
        c[k][1]=a[i][1];
        c[k][2]=a[i][2];
        k++;i++;
    }
    else if(a[i][1]>b[j][1]){
        c[k][0]=b[j][0];
        c[k][1]=b[j][1];
        c[k][2]=b[j][2];
        k++;j++;
    }
    else{
        c[k][0]=b[j][0];
        c[k][1]=b[j][1];
        c[k][2]=a[i][2]+b[j][2];
        k++;j++;i++;
    }
}
while(i<=a[0][2]){
    c[k][0]=a[i][0];
    c[k][1]=a[i][1];
    c[k][2]=a[i][2];
    k++;j++;
}
while(j<b[0][0]){
    c[k][0]=b[j][0];
    c[k][1]=b[j][1];
    c[k][2]=b[j][2];
    k++;j++;
}
}
void printSparse(int a[MAX][3]){
int r=a[0][2];
for(int i=0;i<=r;i++){
    for(int j=0;j<3;j++){
        cout<<a[i][j]<<"  ";
    }
    cout<<"\n";
}
}
int main(){
int a[MAX][3];
int b[MAX][3];
readSparse();
}
