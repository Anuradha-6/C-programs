#include"StackChar.cpp"
#include<iostream>
using namespace std;
class Postfix{
public:
    int isOperand(char a){
        if(a>='A'&&a<='Z'||a>='a'&&a<='z')
            return 1;
        else
            return 0;
    }
    int precedence(char a){
        if(a=='^')
            return 3;
        else if(a=='*'||a=='/')
            return 2;
        else if(a=='+'||a=='-')
            return 1;
        else
            return 0;
    }
    void convertToPostfix(string exp){
        StackChar ob;
        ob.push('$');
        string pexp;
        for(int c=0;c<exp.length();c++)
        {
            if(isOperand(exp[c])==1)
                pexp=pexp+exp[c];
            else if(exp[c]=='(')
                ob.push(exp[c]);
            else if(exp[c]==')'){
                while(ob.peek()!='('){
                    char ch=ob.pop();
                    pexp=pexp+ch;
                }
                ob.pop();
            }
            else{
                if(precedence(exp[c])<=precedence(ob.peek())){
                    pexp=pexp+ob.pop();
                    ob.push(exp[c]);
                }
                else
                    ob.push(exp[c]);
            }
        }
        while (ob.peek() != '$')
        {
            char ch = ob.pop();
            pexp += ch;
        }
        cout<<"Postfix String: "<<pexp<<"\n";
    }
};
int main(){
    Postfix obj;
    string exp;
    cout<<"Enter the infix string\n";
    cin>>exp;
    obj.convertToPostfix(exp);
}
