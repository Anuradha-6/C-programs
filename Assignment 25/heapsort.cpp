#include<iostream>
using namespace std;
    void print(int arr[],int n){
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    void swap(int *a,int *b){
        int t=*b;
        *b=*a;
        *a=t;
    }
    int lchild(int i){
        return 2*i;
    }
    int rchild(int i){
        return 2*i+1;
    }
    void heapadjust(int a[],int k,int N){
        int n=N-1;
        if(k>N/2){
            return;
        }
        if(a[k-1]<a[lchild(k)-1] && lchild(k)-1<N)
            swap(&a[k-1],&a[lchild(k)-1]);
        if(a[k-1]<a[rchild(k)-1]&& rchild(k)-1<N)
            swap(&a[k-1],&a[rchild(k)-1]);
    }
    void heapify(int a[],int n){
        for(int i=n/2;i>0;i--)
            heapadjust(a,i,n);
        }
    void heapsort(int a[],int n){
        heapify(a,n);
        int x=1;
        int t;
        for(int i=n;i>1;i--){
            swap(&a[i-1],&a[0]);
            heapify(a,i-1);
                cout<<"Pass "<<x<<":";
                print(a,n);
                x++;
        }
    }
    int main(){
        int n;
        cout<<"Enter the no. of elements\n";
        cin>>n;
        int arr[n];
        cout<<"Enter the array elements\n";
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<"Entered array is:\n";
        print(arr,n);
        heapsort(arr,n);
        cout<<"Sorted array is:\n";
        print(arr,n);
}
