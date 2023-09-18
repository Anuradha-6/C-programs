#include<iostream>
using namespace std;
void concat(string s1,string s2){
    string news;
    int n=s1.length()+s2.length();
    char *ptr=(char *)malloc(n*sizeof(char));
    int a=0;
    for(int i=0;i<s1.length();i++){
        ptr[a]=s1[i];
        a++;
    }
    for(int i=0;s2.length(),a<n;i++){
        ptr[a]=s2[i];
        a++;
    }
    ptr[a]='\0';
    int i=0;
    cout<<"The concatenated string is :\n";
    while(ptr[i]!='\0'){
        cout<<ptr[i]<<" ";
        i++;
    }
    free(ptr);
}
int main(){
    string s1,s2;
    cout<<"Enter the first string\n";
    cin>>s1;
    cout<<"Enter the second string\n";
    cin>>s2;
    concat(s1,s2);
}
