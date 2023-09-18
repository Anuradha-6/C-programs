#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
class Linked_list{
public:
    Node *head;
    Linked_list(){
        head=NULL;
    }
    void insertBeg(int);
    void insertEnd(int);
    void del_End();
    void del_Beg();
    void del_item(int);
    void display();
    void display_odd();
    void display_even();

};
void Linked_list::insertBeg(int item){
    Node *curr=new Node;
    curr->data=item;
    curr->next=head;
    head=curr;
    return;
}
void Linked_list::insertEnd(int item){
    Node *curr=new Node;
    curr->data=item;
    curr->next=NULL;
    if(head==NULL){
        head=curr;
        return;
    }
    else{
        Node *temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=curr;
    }
}
void Linked_list::del_End(){
    if(head==NULL){
        cout<<"Empty list\n";
        return;
    }
    Node *temp=head;
    Node *prev;
    if(head->next==NULL){
        head=NULL;
        free(temp);
        return;
    }
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
}
void Linked_list::del_Beg(){
    if(head==NULL){
        cout<<"The list is empty\n";
        return;
    }
    Node *temp=head;
    head=head->next;
    free(temp);
}
void Linked_list::del_item(int item){
    if(head==NULL){
        cout<<"The list is empty\n";
        return;
    }
    Node *temp=head;
    Node *prev;
    if(temp->data==item){
        head=head->next;
        delete(temp);
        return;
    }
    while(temp!=NULL && temp->data!=item){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        cout<<"Item not found\n";
        return;
    }
    prev->next=temp->next;
    free(temp);
}
void Linked_list::display(){
    Node *temp=head;
    if(head==NULL){
        cout<<"The List is Empty\n";
        return;
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void Linked_list::display_odd(){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next->next;
    }
    delete(temp);
}
void Linked_list::display_even(){
    Node *temp=head;
    while(temp!=NULL){
        temp=temp->next;
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    delete(temp);
}
int main(){
    Linked_list ob;
    int ch;
    int item;
    do{
        cout<<"\n1.Insert at Beginning\n2.Insert at end\n3.Delete from end\n4.Delete from beginning\n5.Delete an item\n6.Display\n7.Display even positions\n8.Display odd positions\n9.Exit\n";
        cout<<"Enter the choice\n";
        cin>>ch;
        switch(ch){
        case 1:
            cout<<"\nEnter the item\n";
            cin>>item;
            ob.insertBeg(item);
            break;
        case 2:
            cout<<"\nEnter the item\n";
            cin>>item;
            ob.insertEnd(item);
            break;
        case 3:
            ob.del_End();
            break;
        case 4:
            ob.del_Beg();
            break;
        case 5:
            cout<<"\nEnter the item\n";
            cin>>item;
            ob.del_item(item);
            break;
        case 6:
            ob.display();
            break;
        case 7:
            ob.display_even();
            break;
        case 8:
            ob.display_odd();
            break;
        case 9:
            exit(0);
        }
    }while(true);
}
