#include<iostream>
#include"Stack.cpp"
#include"StackChar.cpp"
using namespace std;
class EvaluatePrefix{
public:
    int isDigit(char a){
        if(a>='0'&&a<='9')
            return 1;
        else
            return 0;
    }
     string reverse(string s){
        string rev="";
        StackChar obj;
        for(int i=0;i<s.length();i++)
            obj.push(s[i]);
        for(int i=0;i<s.length();i++)
            rev+=obj.pop();
        return rev;
    }
    int evaluate(int a,int b,char op){
        int c;
        if(op=='-')
            c=a-b;
        else if(op=='+')
            c=a+b;
        else if(op=='*')
            c=a*b;
        else
            c=a/b;
        return c;
    }
    int expression(string s){
        string st=reverse(s);
        Stack ob;
        for(int i=0;i<st.length();i++){
            if(isDigit(st[i]))
                ob.push((int)(st[i]-48));
            else{
                int x=ob.pop();
                int y=ob.pop();
                int z=evaluate(x,y,st[i]);
                ob.push(z);
            }
        }
        return ob.pop();
    }
};
int main(){
    EvaluatePrefix obj;
    string s;
    int r;
    cout<<"Enter the prefix string\n";
    cin>>s;
    r=obj.expression(s);
    cout<<"The value is "<<r;
}
