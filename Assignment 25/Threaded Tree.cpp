#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *lchild;
    Node *rchild;
    bool lthread;
    bool rthread;
    Node(){
        data=0;
        lchild=NULL;
        rchild=NULL;
    }
};
class ThreadedTree{
public:
    Node* newNode(int item){
        Node *ptr=(Node*)malloc(sizeof(Node));
        ptr->data=item;
        ptr->lthread=true;
        ptr->rthread=true;
        return ptr;
    }
    Node* insert(Node *root,int item){
        if(root==NULL){
            root=newNode(item);
            root->lchild=NULL;
            root->rchild=NULL;
            return root;
        }
        Node *temp=root;
        Node *parent=NULL;
        while(temp!=NULL){
            parent=temp;
            if(temp->data==item){
                cout<<"Duplicate key\n";
                return root;
            }
            else if(item<temp->data){
                if(temp->lthread==false)
                    temp=temp->lchild;
                else
                    break;
            }
            else{
                if(temp->rthread==false)
                    temp=temp->rchild;
                else
                    break;
            }
        }
        Node *curr=newNode(item);
        if(item<parent->data){
            curr->lchild=parent->lchild;
            curr->rchild=parent;
            parent->lchild=curr;
            parent->lthread=false;
        }
        else{
            curr->lchild=parent;
            curr->rchild=parent->rchild;
            parent->rchild=curr;
            parent->rthread=false;
        }
        return root;
    }
    Node* inordersucc(Node *x){
        if(x->rthread==true)
            return x->rchild;
        x=x->rchild;
        while(x->lthread!=true)
            x=x->lchild;
        return x;
    }
    Node *inorderTraversal(Node *root){
        if(root==NULL)
            return 0;
        Node *temp=root;
        while(temp->lchild!=NULL)
            temp=temp->lchild;
        while(temp!=NULL){
            cout<<temp->data<<"  ";
            temp=inordersucc(temp);
        }
    }
};
int main(){
    ThreadedTree ob;
    Node *root=NULL;
    int ch;
    int item;
    while(true){
        cout<<"1.Insert\n2.Inorder Traversal\n3.Exit\n";
        cin>>ch;
        switch(ch){
        case 1:
            cout<<"Enter the item\n";
            cin>>item;
            if(root==NULL)
                root=ob.insert(root,item);
            else
                ob.insert(root,item);
            break;
        case 2:
            ob.inorderTraversal(root);
            cout<<endl;
            break;
        case 3:
            exit(0);
        }
    }
}
