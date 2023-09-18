#include<iostream>
using namespace std;
int main(){
    int r;
    int c[10];
    cout<<"Enter the no. of arrays\n";
    cin>>r;
    for(int i=0;i<r;i++){
        cout<<"Enter the size of "<<i<<" row:\n";
        cin>>c[i];
    }
    int **ptr;
    ptr=(int **)malloc(r*sizeof(int *));
    for(int i=0;i<r;i++)
        ptr[i]=(int *)malloc(c[i]*sizeof(int));
    cout<<"Enter the elements in the matrix:\n";
    int x;
    for(int i=0;i<r;i++){
        for(int j=0;j<c[i];j++){
            cin>>x;
            *(ptr[i]+j)=x;
        }
    }
    cout<<"The jagged array is:\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c[i];j++){
            cout<<*(ptr[i]+j)<<" ";
        }
        cout<<endl;
    }
    free(ptr);
}
