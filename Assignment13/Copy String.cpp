#include<iostream>
using namespace std;
void copy(char str1[], char str2[], int index){
    str2[index]=str1[index];
    if(str1[index]=='\0'){
        return ;
    }
    else{
        copy(str1,str2,index+1);
    }
}

int main(){
    char str1[10],str2[11];
    cout<<"Enter the string\n";
    cin.getline(str1,10);
    copy(str1,str2,0);
    cout<<"The copied string is:  "<<str2;
    return 0;
}
