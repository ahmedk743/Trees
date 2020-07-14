#include "templateDatastructs.h"
#include<iostream>
#include <cmath>
using namespace std;
////////////////////
class BinaryTree
{
    TreeNode<int> *root;
    int no_of_nodes, height, orig_height, nofnodes;
    public:
        BinaryTree() { root = NULL; no_of_nodes = 0; nofnodes=0; height=0; orig_height=0; }
        void createTree();
        void insert(int val);
        void levelOrderTrv();
        void preOrderTrv(TreeNode<int> *rt);
        TreeNode<int>* getRoot() { return root; }
        void displayTree();
        TreeNode<int>* find(TreeNode<int>* root, int data);
        void search(int val);
        TreeNode<int>* Delete(TreeNode<int>* root, int data);
        void remove(int del_data);
        bool isLeafNode(int val);
        short getTotalNodes(){return nofnodes;}
        // int getNoOfLevels(){ log }
        int getHeight(TreeNode<int>*);
        void AVL_rotation(myStack<TreeNode<int>*> stk);
};
void BinaryTree :: createTree()
{
    int val; char ch;
    do
    {
        cout<<"\nEnter a Value For Node: "; cin>>val;
        insert(val);
        cout<<"\nWanna Enter More? (y/Y): "; cin>>ch;

    } while ((ch=='y')||(ch=='Y'));
    
}
void BinaryTree :: insert(int val)
{
    TreeNode<int> *newNode = new TreeNode<int>;
    myStack<TreeNode<int>*> stk;
    newNode->setData(val);
    newNode->setLeft(NULL);
    newNode->setRight(NULL);
    if(!root) 
    {
        root = newNode;
            cout<<"\nekkLambi2";
        no_of_nodes++;
        stk.push(newNode);
    }
    else
    {
        TreeNode<int> *temp;
        temp = root;
        while(temp)
        {
            if(temp->getData() > newNode->getData())
            {
                if(temp->getLeft() == NULL) 
                {
                    temp->setLeft(newNode);
                    no_of_nodes++;
                    stk.push(temp);
                    cout<<"\nmeAVL1   "<<stk.getSize();
                    if(stk.getSize() >=3) AVL_rotation(stk);
                    break;
                }
                
                temp = temp->getLeft();
            }
            else if(temp->getData() < newNode->getData())
            {
                if(temp->getRight() == NULL) 
                {
                    temp->setRight(newNode);
                    no_of_nodes++;
                    break;
                }
                temp = temp->getRight();
            }
            else 
            {
                cout<<"\nThe value you Entered Exist already!\nSo not INSERTED";
                break;
            }
            stk.push(temp);
            cout<<"\nekkLambi";
        }  
    }
}

void BinaryTree :: AVL_rotation(myStack<TreeNode<int>*> stk)
{
    cout<<"\nmeAVL1";
    int bf;
    TreeNode<int> *A, *B, *C, *parent;
    myStack<TreeNode<int>*> stk2;
    bf = getHeight(stk.peek()->getLeft()) - getHeight(stk.peek()->getRight());
        
        cout<<"\nbf= "<<bf;
    while(!stk.isEmpty())
    {
        cout<<"\nmeAVL1";
        bf = getHeight(stk.peek()->getLeft()) - getHeight(stk.peek()->getRight());
        
        cout<<"\nbf= "<<bf;
        if((bf<-1) || (bf>1))
        {
            // cout<<"me";
            A = stk.pop();
            // parent = stk.pop();
            B = stk2.pop();
            C = stk2.pop();
            if((A->getRight()==B) && (B->getRight()==C))
            {
                B->setLeft(A);
                // parent->setRight(B);
            }
        }
        else
        {
            stk2.push(stk.pop());
        }
        
    }
}
void BinaryTree :: levelOrderTrv()
{
    if(!root) return;
    TreeNode<int> *temp  = new TreeNode<int>;
    Queue <TreeNode<int>*> Q;
    Q.enQueue(root);
    while(!Q.isEmpty())
    {
        temp = Q.deQueue();
        cout<<temp->getData()<<"\t";
        if(temp->getLeft()) Q.enQueue(temp->getLeft());
        if(temp->getRight()) Q.enQueue(temp->getRight());
    }
}
int BinaryTree :: getHeight(TreeNode<int>* root)
{
    TreeNode<int> *temp  = new TreeNode<int>;
    Queue <TreeNode<int>*> Q;
    Q.enQueue(root);
    while(!Q.isEmpty())
    {
        temp = Q.deQueue();
        if(temp->getLeft()) Q.enQueue(temp->getLeft());
        if(temp->getRight()) Q.enQueue(temp->getRight());
    }
    height = 0;
    find(root, temp->getData());
    return height;
}
TreeNode<int>* BinaryTree :: find(TreeNode<int>* root, int data)
{
    height++;
    if(root == NULL) return NULL;
    if(data < root->getData()) return (find(root->getLeft(), data));
    else if(data > root->getData()) return (find(root->getRight(), data));

    return root; //if finds an element
}
//--------------------//
int main()
{
    BinaryTree bt;
    bt.createTree();
    bt.levelOrderTrv();

    cout<<endl;
    return 0;
}