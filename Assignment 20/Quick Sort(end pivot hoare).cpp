#include<iostream>
using namespace std;
int count=0,compare=0;
void swap(int *x,int *y){
    int temp=*y;
    *y=*x;
    *x=temp;
}
void display(int arr[],int l,int u){
    for(int i=l;i<u;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    cout<<"Pivot= "<<pivot<<endl;
    int left=low-1;
    int right=high;
    while(left<right){
        do{
            left++;
        }while(arr[left]<pivot);
        do{
            right--;
        }while(arr[right]>pivot && right>=0);
        if(left<right){
            compare++;
            cout<<"Swapping "<<arr[left]<<" and "<<arr[right]<<" :\n";
            swap(arr[left],arr[right]);
            display(arr,low,high+1);
        }
    }
    compare++;
    cout<<"Swapping "<<arr[high]<<" and "<<arr[left]<<" :\n";
    swap(arr[high],arr[left]);
    display(arr,low,high+1);
    return left;
}
void quick_sort(int arr[],int low,int high){
    if(low<high){
        cout<<"pass "<<++count<<":\n";
        int j=partition(arr,low,high);
        cout<<"The two sub arrays are :\n";
        display(arr,low,j);
        display(arr,j+1,high+1);
        quick_sort(arr,low,j-1);
        quick_sort(arr,j+1,high);
    }
}
int main(){
    int n;
    cout<<"Enter the no of elements\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quick_sort(arr,0,n-1);
    cout<<"The sorted array is:\n";
    display(arr,0,n);
    cout<<"No. of passes = "<<count<<endl;
    cout<<"No. of comparisons= "<<compare;
}
