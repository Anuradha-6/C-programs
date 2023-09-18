#include<iostream>
#include<string.h>
using namespace std;
int isPalindrome(string str,int left,int right){
    if(left==right)
        return 1;
    if(str[left]!=str[right])
        return 0;
    if(left<=right)
        isPalindrome(str,left+1,right-1);
    return 1;
}
int main(){
    string str;
    cout<<"Enter the string\n";
    cin>>str;
    int x=isPalindrome(str,0,str.length()-1);
    (x==1)?cout<<"PALINDROME":cout<<"NOT PALINDROME";
}
