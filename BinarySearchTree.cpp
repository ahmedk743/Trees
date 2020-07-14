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
        void preOrderTrv(TreeNode<int> *rt);
        void inOrderTrv(TreeNode<int> *rt);
        void postOrderTrv(TreeNode<int> *rt);
        void levelOrderTrv();
        TreeNode<int>* getRoot() { return root; }
        void displayTree();
        TreeNode<int>* find(TreeNode<int>* root, int data);
        void search(int val);
        TreeNode<int>* Delete(TreeNode<int>* root, int data);
        void remove(int del_data);
        bool isLeafNode(int val);
        short getTotalNodes(){return nofnodes;}
        // int getNoOfLevels(){ log }
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
    newNode->setData(val);
    newNode->setLeft(NULL);
    newNode->setRight(NULL);
    if(!root) 
    {
        root = newNode;
        no_of_nodes++;
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
        }  
    }
}
void BinaryTree::search(int val)
{
    TreeNode<int> * found;
    found = find(root, val);
    if(found) cout<<"\nThe Data is Found in TREE!";
    else cout<<"\nThe Data You Searched for Not Found!";
}
TreeNode<int>* BinaryTree :: find(TreeNode<int>* root, int data)
{
    if(root == NULL) return NULL;
    if(data < root->getData()) return (find(root->getLeft(), data));
    else if(data > root->getData()) return (find(root->getRight(), data));

    return root; //if finds an element
}
TreeNode<int>* find_max(TreeNode<int>* root)
{
    TreeNode<int> *max;
    if(!root) return NULL;
    while(root)
    {
        max = root;
        root = root->getRight(); //as max value should be in right subtree
    }
    return max;
}
TreeNode<int>* BinaryTree :: Delete(TreeNode<int>* root, int data)
{
    TreeNode<int>* temp;
    if(!root) cout<<"\nTree Doesn't exists!";
    else if(data < root->getData()) root->setLeft(Delete(root->getLeft(), data));
    else if(data > root->getData()) root->setRight(Delete(root->getRight(), data));
    else //if element found
    {
        if((root->getLeft()) && (root->getRight())) //if has both child
        {
            temp = find_max(root->getLeft());
            root->setData(temp->getData());
            root->setLeft(Delete(root->getLeft(), root->getData()));
        }
        else //one or no child
        {
            temp = root;
            if(root->getLeft()) root = root->getRight();
            if(root->getRight()) root = root->getLeft();

            delete temp;
        }
    }
    return root;
    
}
void BinaryTree :: remove(int del_data)
{
    TreeNode<int> *found;
    found = find(root, del_data);
    if(!found)
    {
        cout<<"\nThe Data You Entered for Deletion. Not Found!";
        return;
    }
    Delete(root, del_data);
    cout<<"\nThe Data is Deleted from TREE!"; 
}
//-----------------//
void BinaryTree :: preOrderTrv(TreeNode<int> *rt)
{
    if(rt)
    {
        cout<<rt->getData()<<"\t";
        nofnodes++;
        preOrderTrv(rt->getLeft());
        preOrderTrv(rt->getRight());
    }
}
//-----------------//
void BinaryTree :: inOrderTrv(TreeNode<int> *rt)
{
    if(rt)
    {
        inOrderTrv(rt->getLeft());
        cout<<rt->getData()<<"\t";
        inOrderTrv(rt->getRight());
    }
}
//-----------------//
void BinaryTree :: postOrderTrv(TreeNode<int> *rt)
{
    if(rt)
    {
        postOrderTrv(rt->getLeft());
        postOrderTrv(rt->getRight());
        cout<<rt->getData()<<"\t";
    }
}
//--------------------//
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
bool BinaryTree:: isLeafNode(int val)
{
    TreeNode<int> * leaf;
    leaf = find(root, val);
    if(!((leaf->getLeft()) || (leaf->getRight()))) return true;
    else return false;
}

//TESTER
int main()
{
    BinaryTree myTr;
    int num, ch; int tempData;
    char ch1;
    do
    {
        cout<<"\n1. Create a Tree"
            <<"\n2. Insert"
            <<"\n3. Delete"
            <<"\n4. Search"
            <<"\n5. Check If Leaf/NonLeaf"
            <<"\n6. View Tree Data (Traverse Through)"
            <<"\n7. Exit\n";
        cin>>ch;
        system("clear");
        switch(ch)
        {
            case 1:
                myTr.createTree();
                break;
            case 2:
                cout<<"\nEnter a Value For Node: "; cin>>tempData;
                myTr.insert(tempData);
                break;
            case 3:
                cout<<"\nEnter Data To Delete: "; cin>>tempData;
                myTr.remove(tempData);
                break;
            case 4:
                cout<<"\nEnter Data To Search: "; cin>>tempData;
                myTr.search(tempData);
                break;
            case 5:
                cout<<"\nEnter Data To check if it is LEAF?: "; cin>>tempData;
                if(myTr.isLeafNode(tempData)) cout<<"\nYeah! The Node you entered is LEAF!";
                else cout<<"\nNOPE! This one is not a LEAF.";
                break;
            case 6:
                cout<<myTr.getTotalNodes();
                cout<<"\n1.PreOrderly"
                    <<"\n2.PostOrderly"
                    <<"\n3.InOrderly"
                    <<"\n4.LevelOrderly"
                    <<"\nEnterChoice!: ";
                cin>>ch1;
                system("clear");
                switch(ch1)
                {
                    case '1':
                        myTr.preOrderTrv(myTr.getRoot());
                        myTr.getTotalNodes();
                        break;
                    case '2':
                        myTr.postOrderTrv(myTr.getRoot());
                        break;
                    case '3':
                        myTr.inOrderTrv(myTr.getRoot());
                        break;
                    case '4':
                        myTr.levelOrderTrv();
                        break;
                    default:
                        cout<<"\nWrong Choice!";
                }  
                break;
            case 7:
                return 0;
                break;

        }
    }while(1);

    cout<<endl;
    return 0;
}
