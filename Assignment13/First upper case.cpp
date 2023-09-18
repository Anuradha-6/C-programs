#include<iostream>
using namespace std;
char firstUpperCase(string str, int n){
    if(str[n]=='\0')
        return 0;
    else if(str[n]<='Z'&& str[n]>='A')
        return str[n];
    else
        return firstUpperCase(str,n+1);
}
int main(){
    string str;
    cout<<"Enter the string\n";
    getline(cin,str);
    char a=firstUpperCase(str,0);
    cout<<a;
}
