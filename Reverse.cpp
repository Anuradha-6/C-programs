#include"Stack.cpp"
#include<iostream>
#define MAX 10
int main(){
    Stack s;
    int arr[MAX];
    int n;
    cout<<"Enter the no. of elements\n";
    cin>>n;
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++){
        s.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        arr[i]=s.pop();
    }
    cout<<"The reverse array is\n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
