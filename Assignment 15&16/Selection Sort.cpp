#include<iostream>
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
int Selection_Sort(int arr[],int n){
    int t=0,pass=0;
    int c=0;
    for(int i=0;i<n;i++){
        int min=i;
        c=0;
        cout<<"Pass "<<i+1<<" :\n";
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
                c++;
            }
            pass++;
        }
        if(c!=0)
            swap(&arr[i],&arr[min]);

        display(arr,n);
    }
    return pass;
}
int main(){
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int arr[n];
    input(arr,n);
    int x=Selection_Sort(arr,n);
    cout<<"The sorted array : ";
    display(arr,n);
    cout<<"No. of comparisons = "<<x;
}
