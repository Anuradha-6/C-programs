#include<iostream>
#define max 30
using namespace std;
class TwoStacks{
public:
    int arr[max];
    int top;
    TwoStacks(){
        top=-1;
    }
    bool isEmpty(){
        if(top==-1)
            return true;
        else
            return false;
    }
    bool isFull(){
        if(top==max-1)
            return true;
        else
            return false;
    }
    void push(int item){
        top++;
        arr[top]=item;
    }
    int peek(int item){
        top++;
        arr[top]=item;
    }
    int peek(){
        if(!isEmpty())
            return arr[top];
        else
            cout<<"Stack is empty\n";
    }
    void display(){
        if(!isEmpty())
        {
            for(int i=top;i>=0;i--)
                cout<<arr[i]<<"  ";
        }
        else
            cout<<"The Stack is empty\n";
    }
    int pop(){
        if(!isEmpty())
        {

            int x=arr[top];
            top--;
            return x;
        }
        else
            cout<<"Stack is Empty\n";
    }
};
int main(){
    int n,a[max];
    TwoStacks s1,s2;
    cout<<"Enter the size of the array\n";
    cin>>n;
    cout<<"Enter the elements\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        if(a[i]%2==0)
            s1.push(a[i]);
        else
            s2.push(a[i]);
    }
    cout<<"The even stack is:\n";
    s1.display();
    cout<<"\n";
    cout<<"The odd stack is:\n";
    s2.display();
    return 0;
}

