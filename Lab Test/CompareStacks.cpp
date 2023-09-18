#include<iostream>
#define MAX 10
using namespace std;
class CompareStacks{
public:
    int arr[MAX];
    int top;
    CompareStacks(){
        top=-1;}
    void push(int a){
        if(isFull())
            cout<<"Overflow\n";
        else
            arr[++top]=a;
    }
    int pop(){
    if(!isEmpty()){
        int x=arr[top];
        top--;
        return x;
    }
    else
        cout<<"Stack is empty\n";
    }
    int peek(){
        if(!isEmpty())
            return arr[top];
        else
            cout<<"The array is empty\n";
    }
    int isFull(){
        if(top==MAX-1)
            return 1;
        else
            return 0;
    }
    int isEmpty(){
        if(top==-1)
            return 1;
        else
            return 0;
    }
    void display(){
        if(!isEmpty()){
            for(int i=top;i>=0;i--)
                cout<<arr[i]<<"\n";
        }
    }
    void compare(CompareStacks a,CompareStacks b){
        int c=0;
        while(!a.isEmpty()&&!b.isEmpty()){
            if(a.pop()!=b.pop()){
            cout<<"The stacks are not same\n";
            c++;
            break;
            }
        }
        if(c==0){
            if((a.isEmpty()&&!b.isEmpty())||(b.isEmpty()&&!a.isEmpty()))
                cout<<"The stacks are not same\n";
            else
                cout<<"The stacks are same\n";
        }
    }
};
int main(){
    CompareStacks s1;
    CompareStacks s2;
    int size;
    cout<<"Enter length of array\n";
    cin>>size;
    int x=1;
    cout<<"Enter the first stack\n";
    while(x){
        cout<<"1.Push\n2.Pop\n3.Peek\n4.Exit from stack 1\n";
        cout<<"Enter your choice";
        int ch;
        cin>>ch;
        switch(ch){
        case 1:
            cout<<"Enter the item\n";
            int item;
            cin>>item;
            s1.push(item);
            s1.display();
            break;
        case 2:
            s1.pop();
            s1.display();
            break;
        case 3:
            cout<<s1.peek()<<"\n";
            s1.display();
            break;
        case 4:
            x=0;
        }
    }
    cout<<"Enter the second stack\n";
    x=1;
    while(x){
        cout<<"1.Push\n2.Pop\n3.Peek\n4.Exit from stack 2\n";
        cout<<"Enter your choice";
        int ch;
        cin>>ch;
        switch(ch){
        case 1:
            cout<<"Enter the item\n";
            int item;
            cin>>item;
            s2.push(item);
            s2.display();
            break;
        case 2:
            s2.pop();
            s2.display();
            break;
        case 3:
            cout<<s2.peek()<<"\n";
            s2.display();
            break;
        case 4:
            x=0;
        }
    }
    s1.compare(s1,s2);

    return 0;
}
