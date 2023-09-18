#include<iostream>
using namespace std;
bool Prime(int x, int y){
    if(x==1||y==1)
        return true;
    else{
        if(x==y)
            return false;
        else if(x<y)
            Prime(x,y-x);
        else
            Prime(x-y,y);
        }
}
int main(){
    int x,y;
    cout<<"Enter the first number\n";
    cin>>x;
    cout<<"Enter the second number\n";
    cin>>y;
    bool p=Prime(x,y);
    if(p)
        cout<<"The numbers are co prime\n";
    else
        cout<<"The numbers are not co prime\n";

}
