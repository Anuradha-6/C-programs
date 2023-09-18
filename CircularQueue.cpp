#include<iostream>
#define max 3
using namespace std;
class CircularQueue{
public:
    int a[max];
    int front;
    int rear;
    CircularQueue(){
        front=0;
        rear=0;
    }
    void enQueue(){
        if(front+rear==max-1)
            cout<<"Queue is full\n";
        else{
            int n;
            cout<<"Enter data\n";
            cin>>n;
            rear=(rear+max)%(max-1);
            a[rear]=n;
        }
    }
    void deQueue(){
        if(rear==front&&front==0)
            cout<<"Empty queue\n";
        else
            front++;
    }
    void display(){
        if(rear==front&&front==-1)
            cout<<"Empty queue\n";
        else{
            int i;
            for(i=(front+1)%max;i!=rear;i=(i+1)%max){
                cout<<a[i]<<"  ";
            }
            cout<<a[i];
            cout<<"\n";
        }
    }
};
int main(){
    CircularQueue obj;
    int ch;
    while(true)
    {
        cout<<"1.EnQueue\n2.DeQueue\n3.Display\n4.Exit\n";
        cin>>ch;
        switch(ch){
        case 1:
            obj.enQueue();
            obj.display();
            break;
        case 2:
            obj.deQueue();
            obj.display();
            break;
        case 3:
            obj.display();
            break;
        case 4:
            cout<<"Program Terminated\n";
            exit(0);
        }
    }
    return 0;
}
