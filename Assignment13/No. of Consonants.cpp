#include<iostream>
using namespace std;
int isConsonant(char ch){
    if(ch=='A'||ch=='a'||ch=='E'||ch=='e'||ch=='I'||ch=='i'||ch=='O'||ch=='o'||ch=='U'||ch=='u')
        return 0;
    else if(ch==' ')
        return 0;
    else
        return 1;
}
int TotalConsonants(string str,int n){
    if(n==1)
        return isConsonant(str[0]);
    else
        return TotalConsonants(str,n-1)+isConsonant(str[n-1]);
}
int main(){
    string str;
    cout<<"Enter the string\n";
    getline(cin,str);
    int x=TotalConsonants(str,str.length());
    cout<<"The total no. of consonants are "<<x;
}
