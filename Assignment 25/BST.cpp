#include<iostream>
//#include<cstdlib>
using namespace std;
class Node{
public:
    int data;
    Node *lchild;
    Node *rchild;
    Node(){
        data=0;
        lchild=NULL;
        rchild=NULL;
    }
};
class BST{
public:
    Node* newNode(int item){
        Node *ptr=(Node*)malloc(sizeof(Node));
        ptr->data=item;
        ptr->lchild=NULL;
        ptr->rchild=NULL;
        return ptr;
    }
    Node* insertNode(Node *root,int val){
        if(root==NULL)
            return newNode(val);
        else{
            Node *temp=root;
            Node *parent=NULL;
            while(temp!=NULL){
                parent=temp;
                if(val>temp->data)
                    temp=temp->rchild;
                else
                    temp=temp->lchild;
            }
            if(val>parent->data){
                return parent->rchild=newNode(val);
            }
            else{
                return parent->lchild=newNode(val);
            }
        }
    }
    void printPreorder(Node *root){
        if(root==NULL)
            return;
        else{
            cout<<root->data<<"  ";
            printPreorder(root->lchild);
            printPreorder(root->rchild);
        }
    }
    void printInorder(Node *root){
        if(root==NULL)
            return;
        else{
            printInorder(root->lchild);
            cout<<root->data<<"  ";
            printInorder(root->rchild);
        }
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
    void smallest(Node *root){
        if(root==NULL){
            cout<<"No node is present\n";
            return;
        }
        while(root->lchild!=NULL)
            root=root->lchild;
        cout<<"The smallest element = "<<root->data<<endl;
    }
    void largest(Node *root){
        if(root==NULL){
            cout<<"No node is present\n";
            return;
        }
        while(root->rchild!=NULL)
            root=root->rchild;
        cout<<"The largest element = "<<root->data<<endl;
    }
    void del(Node *root,int key){
        if(root==NULL)
            return;
        Node *x=root;
        Node *parent=NULL;
        while(x!=NULL &&x->data!=key){//.....
            parent=x;
            if(key<x->data)
                x=x->lchild;
            else
                x=x->rchild;
        }
        if(x==NULL){
            cout<<"Element not found\n";
            return;
        }
        if(x->lchild==NULL||x->rchild==NULL){
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
            delete(succ);
            return;
        }
    }
    int totalNodes(Node *root){
        if(root==NULL)
            return 0;
        return totalNodes(root->lchild)+totalNodes(root->rchild)+1;
    }
    int externalNodes(Node *root){
        if(root==NULL)
            return 0;
        else if(root->lchild==NULL && root->rchild==NULL)
            return 1;
        else
            return(externalNodes(root->lchild)+externalNodes(root->rchild));
    }
    int internalNodes(Node *root){
        if(root==NULL)
            return 0;
        else if(root->lchild!=NULL && root->rchild!=NULL)
            return 1;
        else
            return(internalNodes(root->lchild)+internalNodes(root->rchild));
    }
    int height(Node *root){
        if(root==NULL)
            return 0;
        else
            return max(height(root->lchild),height(root->rchild))+1;
    }
    int search(Node *root,int key){
        if(root==NULL)
            return 0;
        while(root!=NULL){
            if(root->data==key)
                return 1;
            else if(key<root->data)
                root=root->lchild;
            else
                root=root->rchild;
        }
    }
};
int main(){
    BST ob;
    Node *root=NULL;
    int ch;
    int item,x;
    while(true){
        cout<<"1.Insert Element\n2.Preorder Traversal\n3.Inorder Traversal\n4.Postorder Traversal\n5.Smallest element\n6.Largest Element\n7.Delete an element\n8.Search an item \n9.Total no. of nodes\n10.Total no. of external nodes\n11.Total no. of internal nodes\n12.Height of tree\n13.Exit\n";
        cout<<"*******************************"<<endl;
        cin>>ch;
        switch(ch){
        case 1:
            cout<<"Enter the item\n";
            cin>>item;
            if(root==NULL)
                root=ob.insertNode(root,item);
            else
                ob.insertNode(root,item);
            break;
        case 2:
            ob.printPreorder(root);
            cout<<endl;
            break;
        case 3:
            ob.printInorder(root);
            cout<<endl;
            break;
        case 4:
            ob.printPostorder(root);
            cout<<endl;
            break;
        case 5:
            ob.smallest(root);
            break;
        case 6:
            ob.largest(root);
            break;
        case 7:
            cout<<"Enter the item\n";
            cin>>item;
            ob.del(root,item);
            break;
        case 8:
            cout<<"Enter the key\n";
            cin>>item;
            x=ob.search(root,item);
            if(x==1)
                cout<<"Element is present in the tree\n";
            else
                cout<<"Element is not present in the tree\n";
            break;
        case 9:
            x=ob.totalNodes(root);
            cout<<"Total no. of nodes = "<<x<<endl;
            break;
        case 10:
            x=ob.externalNodes(root);
            cout<<"Total no. of external nodes ="<<x<<endl;
            break;
        case 11:
            x=ob.internalNodes(root);
            cout<<"Total no. of internal nodes ="<<x<<endl;
            break;
        case 12:
            x=ob.height(root);
            cout<<"Height of the tree="<<x<<endl;
            break;
        case 13:
            exit(0);
        default:
            cout<<"Enter correct choice\n";
        }
    }
}
