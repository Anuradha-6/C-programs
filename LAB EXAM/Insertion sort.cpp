#include<iostream>
using namespace std;
void input(int arr[],int n){
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"  ";
    cout<<"\n";
}
void insertion_sort(int arr[],int n){
    int j;
    for(int i=1;i<n;i++){
        j=i-1;
        int key=arr[i];
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
        cout<<"Pass "<<i<<":"<<endl;
        display(arr,n);
    }
}
int main(){
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int arr[n];
    input(arr,n);
    insertion_sort(arr,n);
    cout<<"The sorted array is: ";
    display(arr,n);
}

