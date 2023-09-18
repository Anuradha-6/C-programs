#include <iostream>
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
void Stable_Select_Sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
       int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min])
                min=j;
        }
        int key=arr[min];
        while(min>i){
            arr[min]=arr[min-1];
            min=min-1;
        }
        arr[i]=key;
        display(arr,n);
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int arr[n];
    input(arr,n);
    Stable_Select_Sort(arr,n);
    cout<<"The sorted array : ";
    display(arr,n);

}
