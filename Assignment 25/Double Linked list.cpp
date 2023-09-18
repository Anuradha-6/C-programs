#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node *prev;
};
class Double_linked_list{
public:
    Node *head;
    Double_linked_list(){
        head=NULL;
    }
    void insertBeg(int item){
        Node *curr=new Node;
        if(head==NULL){
            curr->data=item;
            curr->prev=NULL;
            curr->next=NULL;
            head=curr;
            return;
        }
        curr->data=item;
        curr->prev=NULL;
        curr->next=head;
        head->prev=curr;
        head=curr;
    }
    void insertEnd(int item){
        Node *curr=new Node;
        curr->data=item;
        curr->next=NULL;
        Node *temp=head;
        if(head==NULL){
            curr->prev=NULL;
            head=curr;
            return;
        }
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=curr;
        curr->prev=temp;
        return;
    }
    void delBeg(){
        if(head==NULL){
            cout<<"Empty list\n";
            return;
        }
        Node *temp=head;
        head=head->next;
        if(head!=NULL)
            head->prev->next=NULL;
        delete temp;
        return;
    }
    void delEnd(){
        if(head==NULL){
            cout<<"Empty list\n";
            return;
        }
        Node *temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        if(temp->prev!=NULL)
            temp->prev->next=NULL;
        else
            head=NULL;
        delete temp;
        return;
    }
    void display(){
        if(head==NULL){
            cout<<"Empty list\n";
            return;
        }
        Node *temp=new Node;
        temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
        return;
    }
};
int main(){
    Double_linked_list ob;
    int ch;
    int item;
    do{
        cout<<"1. Insert at beginning\n2. Insert at end\n3. Display the list\n4. Delete at beginning\n5. Delete at end\n6. Exit\n";
        cin>>ch;
        switch(ch){
        case 1:
            cout<<"Enter the item\n";
            cin>>item;
            ob.insertBeg(item);
            break;
        case 2:
            cout<<"Enter the item\n";
            cin>>item;
            ob.insertEnd(item);
            break;
        case 3:
            ob.display();
            break;
        case 4:
            ob.delBeg();
            break;
        case 5:
            ob.delEnd();
            break;
        case 6:
            exit(0);
        }
    }while(true);
}
