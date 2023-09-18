#include<iostream>
using namespace std;
int recursive(int arr[],int l,int r,int x){
    if(l==r){
        if(x==arr[l])
            return l;
        return -1;
    }
    else{
        int mid=(l+r)/2;
        if(arr[mid]==x)
            return mid;
        else if(x>arr[mid])
            return recursive(arr,mid+1,r,x);
        else
            return recursive(arr,l,mid-1,x);
    }
}
int iterative(int arr[],int l,int r,int x){
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
    cout<<"Enter the no. of elements\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int x;
    cout<<"Enter element to be searched\n";
    cin>>x;
    int ch;
    int s;
    cout<<"Enter 1 for recursive method and 2 for iterative method\n";
    cin>>ch;
    switch(ch){
    case 1:
        s=recursive(arr,0,n-1,x);
        if(s==-1)
            cout<<"Element not found\n";
        else
            cout<<"Element found at position "<<s<<"\n";
        break;
    case 2:
        s=iterative(arr,0,n-1,x);
        if(s==-1)
            cout<<"Element not found\n";
        else
            cout<<"Element found at position "<<s<<"\n";
        break;
    default:
        cout<<"Incorrect choice\n";
    }
}
