#include<iostream>
using namespace std;
int linearSearch(int arr[],int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x)
            return 1;
    }
    return 0;
}
int main(){
    int n;
    cout<<"Enter the size of array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int x;
    cout<<"Enter the key to be searched\n";
    cin>>x;
    int s=linearSearch(arr,n,x);
    (s==1)?cout<<"Item found\n":cout<<"Item not found\n";
}
