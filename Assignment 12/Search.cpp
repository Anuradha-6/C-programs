#include<iostream>
using namespace std;

int Search(int arr[],int l,int r,int x){
    if(l>r)
        return -1;
    if(arr[l]==x)
        return l;
    if(arr[r]==x)
        return r;
    return Search(arr,l+1,r-1,x);
}
int main(){
    int n;
    int x;
    cout<<"Enter the size of array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the element to be searched\n";
    cin>>x;
    int a=Search(arr,0,n-1,x);
    if(a==-1)
        cout<<"Element not found\n";
    else
        cout<<"Element found at position "<<a+1;
    return 0;
}

