#include<iostream>
#include"Tree.cpp"
using namespace std;
class Binary_Search_Tree{
public:
    Node* newNode(int item){
        Node *ptr=(Node*)malloc(sizeof(Node));
        ptr->data=item;
        ptr->lchild=NULL;
        ptr->rchild=NULL;
        return ptr;
    }
    Node* insert(Node *r,int item){
        if(r==NULL)
            return newNode(item);
        else{
            Node *temp=r;
            Node *parent=NULL;
            while(temp!=NULL){
                parent=temp;
                if(item>temp->data)
                    temp=temp->rchild;
                else
                    temp=temp->lchild;
            }
            parent=NULL;
        }
    }
    void printPreorder(Node *root){
        if(root==NULL)
            return;
        else{
            cout<<root->data;
            printPreorder(root->lchild);
            printPreorder(root->rchild);
        }
    }
    void printInorder(Node *root){
        if(root==NULL)
            return;
        else{
            printInorder(root->lchild);
            cout<<root->data;
            printInorder(root->rchild);
        }
    }
    void printPostorder(Node *root){
        if(root==NULL)
            return;
        else{
            printPreorder(root->lchild);
            cout<<root->data;
            printPostorder(root->rchild);
        }
    }
};
int main(){
    Binary_Search_Tree ob;
    Node *root=NULL;
    root=ob.insert(root,20);
    ob.insert(root,15);
    ob.insert(root,30);
    ob.insert(root,24);
    ob.printPreorder(root);
}
