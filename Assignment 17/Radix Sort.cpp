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
void Counting_Sort(int arr[],int n,int pow10){
    int count[10];
    int output[n];
    int digit=0,index=0;
    for(int i=0;i<=9;i++)
        count[i]=0;
    for(int i=0;i<n;i++){
        digit=(arr[i]/pow10)%10;
        count[digit]++;
    }
    for(int i=1;i<=9;i++)
        count[i]=count[i]+count[i-1];
    for(int i=n-1;i>=0;i--){
        digit=(arr[i]/pow10)%10;
        index=count[digit]-1;
        count[digit]=count[digit]-1;
        output[index]=arr[i];
    }
    for(int i=0;i<n;i++)
        arr[i]=output[i];
}
void Radix_Sort(int arr[],int n){
    int max=getMax(arr,n);
    int i=0;
    int pow10=1;
    while(max>0){
        Counting_Sort(arr,n,pow10);
        pow10=pow10*10;
        max=max/10;
        cout<<"Pass "<<i<<": \n";
        display(arr,n);
        i++;
    }
}
int main(){
    int n;
    cout<<"Enter the size\n";
    cin>>n;
    int arr[n];
    input(arr,n);
    Radix_Sort(arr,n);
    cout<<"The sorted array is :\n";
    display(arr,n);
}
