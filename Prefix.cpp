#include<iostream>
#include"StackChar.cpp"
using namespace std;
class Prefix{
public:
    int isOperand(char a){
        if(a>='A'&&a<='Z'||a>='a'&&a<='z')
            return 1;
        else
            return 0;
    }
    int precedence(char a){
        if(a=='*'||a=='/')
            return 2;
        else if(a=='+'||a=='-')
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
    void ConvertToPrefix(string s){
        StackChar ob;
        ob.push('$');
        string in=reverse(s);
        string pre;
        for(int i=0;i<in.length();i++){
            if(in[i]==')')
                ob.push(in[i]);
            else if(isOperand(in[i]))
                pre+=in[i];
            else if(in[i]=='('){
                while(ob.peek()!=')'){
                    pre+=ob.pop();
                }
                ob.pop();
            }
            else{
                if(ob.peek()=='$')
                    ob.push(in[i]);
                else if(ob.peek()==')')
                    ob.push(in[i]);
                else if(precedence(in[i])>precedence(ob.peek()))
                    ob.push(in[i]);
                else{
                    while(precedence(in[i])<precedence(ob.peek())){
                        pre+=ob.pop();
                    }
                    ob.push(in[i]);
                }
            }
        }
        while(ob.peek()!='$'){
            pre+=ob.pop();
        }
        string newpre=reverse(pre);
        cout<<"The prefix String is\n";
        cout<<newpre;

    }
};
int main(){
    Prefix ob;
    string st;
    cout<<"Enter the infix String\n";
    cin>>st;
    ob.ConvertToPrefix(st);
}
