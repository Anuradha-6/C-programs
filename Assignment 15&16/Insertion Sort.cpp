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
int Insertion_Sort(int arr[],int n){
    int j;
    int count=0;
    for(int i=1;i<n;i++){
        int key=arr[i];
        j=i-1;
        while(j>=0 && (++count && arr[j]>key)){
            arr[j+1]=arr[j];
            j=j-1;

        }
        arr[j+1]=key;
        cout<<"Pass "<<i<<" : \n";
        display(arr,n);
    }
    return count;
}
int main(){
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int arr[n];
    input(arr,n);
    int x=Insertion_Sort(arr,n);
    cout<<"The sorted array : ";
    display(arr,n);
    cout<<"No. of comparisons = "<<x;
}
