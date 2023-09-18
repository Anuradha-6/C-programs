#include<iostream>
using namespace std;
int bin_search(int arr[],int l,int r,int x){
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]==x)
            return mid;
        else if(x>arr[mid])
            l=mid+1;
        else
            r=mid-1;
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter the size of array\n";
    cin>>n;
    int arr[n];
    int x;
    cout<<"Enter the array elements in sorted order\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the key to be searched\n";
    cin>>x;
    int bs=bin_search(arr,0,n-1,x);
    if(bs==-1)
        cout<<"Element not found\n";
    else
        cout<<"Element found at position "<<bs<<endl;
}
