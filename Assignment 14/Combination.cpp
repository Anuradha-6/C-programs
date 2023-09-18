#include<iostream>
using namespace std;
int Combination(int n, int r){
    if(n==r)
        return 1;
    if(n==0||r==0)
        return 1;
    else
        return (Combination(n-1,r-1)+Combination(n-1,r));
}
int main(){
    int n,r;
    cout<<"Enter the value of n\n";
    cin>>n;
    cout<<"Enter the value of r\n";
    cin>>r;
    int x=Combination(n,r);
    cout<<x;
}
