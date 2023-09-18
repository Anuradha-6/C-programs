#include<iostream>
using namespace std;
class Node{
public:
    int data;
    int height;
    Node *lchild;
    Node *rchild;
    Node(){
        data=0;
        height=0;
        lchild=NULL;
        rchild=NULL;
    }
};
class AVL{
public:
    Node* newNode(int item){
        Node *ptr=(Node*)malloc(sizeof(Node));
        ptr->data=item;
        ptr->lchild=NULL;
        ptr->rchild=NULL;
        return ptr;
    }
    int getHeight(Node *x){
        if(x==NULL)
            return 0;
        else
            return(x->height);
    }
    int getBalance(Node *x){
        if(x==NULL)
            return 0;
        else
            return (getHeight(x->lchild)-getHeight(x->rchild));
    }
    Node* rotateLeft(Node *x){
        Node *y=x->rchild;
        Node *temp=y->lchild;
        y->lchild=x;
        x->rchild=temp;
        x->height=max(getHeight(x->lchild),getHeight(x->rchild))+1;
        y->height=max(getHeight(y->lchild),getHeight(y->rchild))+1;
        return y;
    }
    Node* rotateRight(Node *x){
        Node *y=x->lchild;
        Node *temp=y->rchild;
        y->rchild=x;
        x->lchild=temp;
        x->height=max(getHeight(x->lchild),getHeight(x->rchild))+1;
        y->height=max(getHeight(y->lchild),getHeight(y->rchild))+1;
        return y;
    }
    Node* insert(Node *root,int item){
        //Inserting recursively
        if(root==NULL)
            return newNode(item);
        if(item<root->data)
            root->lchild=insert(root->lchild,item);
        else if(item>root->data)
            root->rchild=insert(root->rchild,item);
        else  //For repeat items we do not insert
            return root;
        int bf=getBalance(root);
        if(bf<-1 &&item<root->rchild->data)//RR case
            return rotateLeft(root);
        if(bf<-1 &&item>root->rchild->data)//RL (left subtree of right child of x) case
            return rotateLeft(root);
        if(bf>1 && item<root->lchild->data)//LL case
            return rotateRight(root);
        if(bf>1 && item>root->lchild->data){//LR case
            root->lchild=rotateLeft(root->lchild);
            return rotateRight(root);
        }
        return root; //Return if tree is balanced
    }
    void printPostorder(Node *root){
        if(root==NULL)
            return;
        else{
            printPostorder(root->lchild);
            printPostorder(root->rchild);
            cout<<root->data<<"  ";
        }
    }
    int search(Node *root,int key){
        if(root==NULL)
            return 0;
        if(key==root->data)
            return 1;
        else if(key<root->data)
            search(root->lchild,key);
        else
            search(root->rchild,key);
    }

    Node* del(Node *root,int item){
        if(root==NULL)
            return root;
        if(item<root->data)
            root->lchild=del(root->lchild,item);
        else if(item>root->data)
            root->rchild=del(root->rchild,item);
        else{
            if(root->lchild==NULL||root->rchild==NULL){
                Node *ptr;
                if(root->lchild==NULL)
                    ptr=root->rchild;
                else
                    ptr=root->lchild;
                if(ptr==NULL){
                    ptr=root;
                    root=NULL;
                }
                else // One child case
                *root = *ptr; // Copy the contents of
                           // the non-empty child
                delete(ptr);
            }
            else{ //Node with 2 children
                Node *temp=root->rchild;
                while(temp->lchild!=NULL)
                    temp=temp->lchild; //Inorder successor
                root->data=temp->data;
                // Delete the inorder successor
                root->rchild = del(root->rchild,temp->data);
            }
        }
        if(root==NULL)
            return root;
        root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
        int balance=getBalance(root);
        if (balance > 1 && getBalance(root->lchild) >= 0)
        return rotateRight(root);

        // Left Right Case
        if (balance > 1 &&getBalance(root->lchild) < 0)
        {
            root->lchild = rotateLeft(root->lchild);
            return rotateRight(root);
        }

        // Right Right Case
        if (balance < -1 &&getBalance(root->rchild) <= 0)
            return rotateLeft(root);

        // Right Left Case
        if (balance < -1 &&getBalance(root->rchild) > 0)
        {
            root->rchild = rotateRight(root->rchild);
            return rotateLeft(root);
        }

        return root;
    }
};
int main(){
    AVL ob;
    Node *root=NULL;
    root=ob.insert(root,10);
    ob.printPostorder(root);
    cout<<endl;
    ob.insert(root,20);
    ob.printPostorder(root);
    cout<<endl;
    ob.insert(root,30);
    ob.printPostorder(root);
    cout<<endl;
    ob.insert(root,40);
    ob.printPostorder(root);
    cout<<endl;
    ob.insert(root,50);
    ob.printPostorder(root);
    cout<<endl;
    cout<<ob.search(root,20);
    cout<<endl;
    cout<<ob.search(root,15);
    cout<<endl;
    ob.printPostorder(root);
    cout<<endl;
    ob.del(root,50);
    ob.printPostorder(root);
}


 /*Iterative deletion (does not work yet)
 void del(Node *root,int item){
        if(root==NULL){
            cout<<"Tree is empty\n";
            return;
        }
        Node *parent=NULL;
        Node *x=root;
        while(x!=NULL){
            parent=x;
            if(x->data==item)
                break;
            else if(item<x->data)
                x=x->lchild;
            else
                x=x->rchild;
        }
        if(x==NULL){
            cout<<"Item not found\n";
            return;
        }
        if(x->lchild==NULL || x->rchild==NULL){
            Node *ptr;
            if(x->lchild==NULL)
                ptr=x->rchild;
            else
                ptr=x->lchild;
            if(parent==NULL){
                root=ptr;
                delete(x);
                return;
            }
            ptr->height=max(getHeight(ptr->lchild),getHeight(ptr->rchild))+1;
            if(x==parent->lchild)
                parent->lchild=ptr;
            else
                parent->rchild=ptr;
            delete(x);
        }
        else{
            Node *succ=x->rchild;
            Node *psucc=NULL;
            while(succ->lchild==NULL){
                psucc=succ;
                succ=succ->lchild;
            }
            if(psucc==NULL)
                x->rchild=succ->rchild;
            else
                psucc->lchild=succ->rchild;
                x->data=succ->data;
            x->height=max(getHeight(x->lchild),getHeight(x->rchild))+1;
            delete(succ);
        }
        int bf=0;
        while(root!=NULL){
            bf=getBalance(root);
            if(bf<-1 &&item<root->rchild->data)//RR case
                rotateLeft(root);
            if(bf<-1 &&item>root->rchild->data)//RL (left subtree of right child of x) case
                rotateLeft(root);
            if(bf>1 && item<root->lchild->data){//LL case
                rotateRight(root);
            }
            if(bf>1 && item>root->lchild->data){//LR case
                root->lchild=rotateLeft(root->lchild);
                rotateRight(root);
            }
            if(item<root->data)
                root=root->lchild;
            else
                root=root->rchild;
        }
      // delete(x);
    }*/
