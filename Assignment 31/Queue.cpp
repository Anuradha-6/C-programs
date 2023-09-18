#include<iostream>
#define max 10
using namespace std;
class Queue{
public:
    int arr[max];
    int front,rear;
    Queue(){
        front=-1;
        rear=-1;
    }
    bool isFull(){
        if(rear==max-1)
            return true;
        else
            return false;
    }
    bool isEmpty(){
        if(front==rear)
            return true;
        else
            return false;
    }
    void enQueue(int item){
        if(!isFull())
        {
            rear++;
            arr[rear]=item;
        }
        else
            cout<<"Queue is full\n";
    }
    int deQueue(){
        if(!isEmpty()){
            front=front+1;
            return arr[front];
        }
        else{
            cout<<"Queue is empty\n";
            return INT_MIN;
        }
    }
    int peek(){
        if(!isEmpty())
            return arr[front+1];
        else{
            cout<<"Queue is empty\n";
            return INT_MIN;
        }
    }
    void display(){
        if(!isEmpty()){
            for(int i=front +1;i<=rear;i++)
                cout<<arr[i]<<"  ";
        }
        else
            cout<<"Queue is empty\n";
    }
};
/*int main(){
    int ch;
    int item;
    Queue obj;
    while(true){
        cout<<"1.enQueue\n2.deQueue\n3.Peek\n4.Display\n5.Exit\n";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter the item\n";
                cin>>item;
                obj.enQueue(item);
                obj.display();
                break;
            case 2:
                obj.deQueue();
                obj.display();
                break;
            case 3:
                cout<<obj.peek();
                break;
            case 4:
                obj.display();
                break;
            case 5:
                cout<<"Program Terminated";
                exit(0);
                break;
        }
    }
    return 0;
}*/
