#include<iostream>
using namespace std;
void transpose(int *arr,int r,int c){
    int **ptr;
    ptr=(int **)malloc(r*sizeof(int *));
    for(int i=0;i<r;i++)
        ptr[i]=(int *)malloc(c*sizeof(int));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
           *(ptr[i]+j)=*(arr+j*r+i);
        }
    }
    cout<<"The transpose matrix is :\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<ptr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int r,c;
    cout<<"Enter the no. of rows\n";
    cin>>r;
    cout<<"Enter the no. of columns\n";
    cin>>c;
    cout<<"Enter the matrix elements:\n";
    int *arr;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>*(arr+i*c+j);
        }
    }
    transpose(arr,r,c);
    free(arr);
}
