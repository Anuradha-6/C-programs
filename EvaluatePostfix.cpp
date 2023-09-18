#include<iostream>
#include"Stack.cpp"
using namespace std;
class EvaluatePostfix{
public:
    int isDigit(char a){
        if(a>='0'&&a<='9')
            return 1;
        else
            return 0;
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
    int Expression(string st){
        Stack ob;
        for(int i=0;i<st.length();i++){
            if(isDigit(st[i]))
                ob.push((int)(st[i]-48));
            else{
                int x=ob.pop();
                int y=ob.pop();
                int z=evaluate(y,x,st[i]);
                ob.push(z);
            }
        }
        return ob.pop();
    }
};
int main(){
    EvaluatePostfix obj;
    string s;
    int r;
    cout<<"Enter the postfix string\n";
    cin>>s;
    r=obj.Expression(s);
    cout<<"The value is "<<r;
}
