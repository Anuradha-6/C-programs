#include<iostream>
#define MAX 10
using namespace std;
class Stack{
public:
    int arr[MAX];
    int top;
    Stack(){
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
};
  /*  int main(){
        Stack s1;
        int size;
        cout<<"Enter length of array\n";
        cin>>size;
        while(1){
            cout<<"1.Push\n2.Pop\n3.Peek\n4.Exit\n";
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
                cout<<s1.pop()<<"\n";
                s1.display();
                break;
            case 3:
                cout<<s1.peek()<<"\n";
                s1.display();
                break;
            case 4:
                exit(0);
            }
        }
        return 0;
    }*/
