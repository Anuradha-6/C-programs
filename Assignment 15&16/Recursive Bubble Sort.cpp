#include<iostream>
using namespace std;
void input(int arr[],int n){
    cout<<"Enter the array elements";
    for(int i=0;i<n;i++)
        cin>>arr[i];
}
void display(int arr[],int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"  ";
    cout<<"\n";
}
void Recursive_Bubble_Sort(int arr[],int n){
    if(n==1)
        return;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1])
            swap(arr[i],arr[i+1]);
    }
    Recursive_Bubble_Sort(arr,n-1);
}

int main(){
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int arr[n];
    input(arr,n);
    Recursive_Bubble_Sort(arr,n);
    cout<<"The sorted array : ";
    display(arr,n);

}
