#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
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
int Bubble_Sort(int arr[],int n){
    int t=0,pass=0;
    for(int i=0;i<n-1;i++){
        t=0;
        cout<<"Pass "<<i+1<<" : \n";
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                t++;
                display(arr,n);
            }
            pass++;

        }

        if(t==0)
            break;
    }
    return pass;
}

int main(){
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int arr[n];
    input(arr,n);
    int x=Bubble_Sort(arr,n);
    cout<<"The sorted array : ";
    display(arr,n);
    cout<<"No. of comparisons = "<<x;
}
