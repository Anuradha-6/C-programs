//Insertion sort using binary Search

#include <iostream>
using namespace std;
int swapping=0;
int comparison=0;
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
int binary_Search(int arr[],int low,int high,int x){
    if(high<=low){
        comparison++;
        if(x>arr[low])
            return low+1;
        else
            return low;
    }
    int mid=(high+low)/2;
    if(x==arr[mid]){
        return mid+1;
        comparison++;
    }
    if(x>arr[mid]){
        return binary_Search(arr,mid+1,high,x);
        comparison++;
    }
    return binary_Search(arr,low,mid-1,x);
}
void Insertion_Sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        int pos=binary_Search(arr,0,j,key);
        while(j>=pos){
            swapping++;
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
int main(){
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int arr[n];
    input(arr,n);
    Insertion_Sort(arr,n);
    cout<<"The sorted array : ";
    display(arr,n);
    cout<<"No. of comparisons= "<<comparison<<"\n";
    cout<<"No. of Swaps= "<<swapping;
}
