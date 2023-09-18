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
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void Recursive_Selection_Sort(int arr[],int n,int i){
    if(n==i)
        return;
    int min=i;
    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[min])
            min=j;
    }
    if(min!=i)
        swap(arr[i],arr[min]);
    Recursive_Selection_Sort(arr,n,(i+1));
}
int main(){
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int arr[n];
    input(arr,n);
    Recursive_Selection_Sort(arr,n,0);
    cout<<"The sorted array : ";
    display(arr,n);

}
