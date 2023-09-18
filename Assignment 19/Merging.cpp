//Merging two sorted arrays
#include<iostream>
using namespace std;
void Merge(int x[],int m,int y[],int n,int z[]){
    int i=0,j=0,k=0;
    while(i<m&&j<n){
        if(x[i]<=y[j]){
            z[k]=x[i];
            i++;
            k++;
        }
        else{
            z[k]=y[j];
            j++;
            k++;
        }
    }
    while(i<m){
        z[k]=x[i];
        i++;
        k++;
    }
    while(j<m){
        z[k]=y[j];
        j++;
        k++;
    }
}
int main(){
    int m,n;
    cout<<"Enter the length of first array\n";
    cin>>m;
    int x[m];
    cout<<"Enter the length of second array\n";
    cin>>n;
    int y[n];
    cout<<"Enter the elements in first array\n";
    for(int i=0;i<m;i++)
        cin>>x[i];
    cout<<"Enter the elements in second array\n";
    for(int i=0;i<n;i++)
        cin>>y[i];
    int p=m+n-1;
    int z[p];
    Merge(x,m,y,n,z);
    for(int i=0;i<p;i++)
        cout<<z[i]<<"  ";
}
