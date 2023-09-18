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
int getMax(int arr[],int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(arr[i]>max)
            max=arr[i];
    }
    return max;
}
void Counting_Sort(int arr[],int n){
    int max=getMax(arr,n);
    int count[max+1];
    int output[n];
    int index=0;
    for(int i=0;i<n;i++)
        output[i]=0;
    for(int i=0;i<=max;i++)
        count[i]=0;
    for(int i=0;i<n;i++)
        count[arr[i]]++;
        cout<<"The count array is:\n";
        display(count,max+1);

    for(int i=1;i<=max;i++)
        count[i]+=count[i-1];
        cout<<"The modified count array is:\n";
        display(count,max+1);

    for(int i=n-1;i>=0;i--){
        index=count[arr[i]]-1;
        count[arr[i]]=count[arr[i]]-1;
        output[index]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
    cout<<"The output array : \n";
    display(output,n);
}
int main(){
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int arr[n];
    input(arr,n);
    Counting_Sort(arr,n);
}
