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
void Recursive_Insertion_Sort(int arr[],int n){
    if(n<=1)
        return;
    Recursive_Insertion_Sort(arr,n-1);
    int key=arr[n-1];
    int j=n-2;
    while(j>=0 && arr[j]>key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
}
int main(){
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int arr[n];
    input(arr,n);
    Recursive_Insertion_Sort(arr,n);
    cout<<"The sorted array : ";
    display(arr,n);

}
