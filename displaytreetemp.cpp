#include "templateDatastructs.h"
#include<iostream>
#include <cmath>
using namespace std;
////////////////////
void print_spaces(int val)
{
    for(int i = 0; i < 11-val; i++) cout<<"      ";
}

////////////////////
class BinaryTree
{
    TreeNode<int> *root;
    int no_of_elements, height, orig_height;
    public:
        BinaryTree() { root = NULL; no_of_elements = 0; height=0; orig_height=0; }
        void createTree();
        void insert(int val);
        void preOrderTrv(TreeNode<int> *rt);
        void inOrderTrv(TreeNode<int> *rt);
        void postOrderTrv(TreeNode<int> *rt);
        void levelOrderTrv();
        TreeNode<int>* getRoot() { return root; }
        void displayTree();
        void displayNode(int data, int t_int);
        // int getNoOfLevels(){ log }
};
//+++++++++++++++//
void BinaryTree :: displayNode(int data, int t_int)
{
    static Queue <int> QQ;

    if(height == 1 || height == 2 || height == 4 || height == 8)
    {
        if(no_of_elements == t_int) print_spaces(height);
        for(int i = 0 ; i < t_int; i++) 
        {
            if(height == 0)
            {
                if(i>0) cout<<"          ___";
                else cout<<"        ___";
            }
            else if(height == 2)
            {
                if(i>0) cout<<"        ___";
                else cout<<"    ___";
            }
            else if(height == 3)
            {
                
            }
            else
            {
                if(i>0) cout<<"                 ___";
                else cout<<"    ___";
            }
                
        }
        cout<<"\n"; 
        if(no_of_elements == t_int) print_spaces(height);
        for(int i = 0 ; i < t_int; i++) 
        {
            if(height == 0)
            {
                if(i>0) cout<<"        /   \\";
                else cout<<"       /   \\";
            }
            else if(height == 2 || height == 3)
            {
                if(i>0) cout<<"      /   \\";
                else cout<<"   /   \\";
            }
            else if(height == 3)
            {
                
            }
            else
            {
                if(i>0) cout<<"               /   \\";
                else cout<<"   /   \\";
            }
        }
        cout<<"\n";
        if(no_of_elements == t_int) print_spaces(height);
        for(int i = 0 ; i <  t_int; i++)
        {
            while(!QQ.isEmpty())
            {
                if(height == 0)
                {
                    if(i>0) cout<<"      |  "<<QQ.deQueue()<<"  |";
                    else cout<<"      |  "<<QQ.deQueue()<<"  |";
                }
                else if(height == 2 || height == 3)
                {
                    if(i>0) cout<<"|  "<<QQ.deQueue()<<"  |    ";
                    else cout<<"  |  "<<QQ.deQueue()<<"  |    ";
                }
                else if(height == 3)
                {
                    
                }
                else
                {
                    if(i>0) cout<<"             |  "<<QQ.deQueue()<<"  |";
                    else cout<<"  |  "<<QQ.deQueue()<<"  |";
                }
            }
                
        }
        cout<<"\n";
        if(no_of_elements == t_int) print_spaces(height);
        for(int i = 0 ; i <  t_int; i++) 
        {
            if(height == 0)
            {
                if(i>0) cout<<"        \\___/";
                else cout<<"       \\___/";
            }
            else if(height == 2 || height == 3)
            {
                if(i>0) cout<<"\\___/      ";
                else cout<<"   \\___/      ";
            }
            else if(height == 3)
            {
                
            }
            else
            {
                if(i>0) cout<<"               \\___/";
                else cout<<"   \\___/";
            }
        }
        cout<<"\n";
        if(no_of_elements == t_int) print_spaces(height);
        for(int i = 0 ; i <  t_int; i++) 
        {
            if(height == 0)
            {
                if(i>0) cout<<"       /     \\";
                else cout<<"      /     \\";    
            }
            else if(height == 2 || height == 3)
            {
                if(i>0) cout<<"     /   \\ ";
                else cout<<"   /    \\";
            }
            else if(height == 3)
            {
                
            }
            else
            {
                if(i>0) cout<<"               /   \\";
                else cout<<"   /   \\";
            }
            
        }
        cout<<"\n";
        if(no_of_elements == t_int) print_spaces(height);
        for(int i = 0 ; i <  t_int; i++)
        {
            if(height == 0)
            {
                if(i>0) cout<<"      /     \\";
                else cout<<"    /         \\";    
            }
            else if(height == 2 || height == 3)
            {
                if(i>0) cout<<"   /     \\ ";
                else cout<<"  /      \\";
            }
            else if(height == 3)
            {
                
            }
            else
            {
                if(i>0) cout<<"             /     \\"; 
                else cout<<"  /     \\";
            }
        } 
        cout<<"\n";
        if(no_of_elements == t_int) print_spaces(height); 
        for(int i = 0 ; i <  t_int; i++)
        {
            if(height == 0)
            {
                if(i>0) cout<<" /            \\";
                else cout<<"  /             \\";    
            }
            else if(height == 2)
            {
                if(i>0) cout<<" /       \\ ";
                else cout<<" /        \\";
            }
            else if(height == 3)
            {
                
            }
            else
            {
                if(i>0) cout<<"           /       \\"; 
                else cout<<" /       \\";
            } 
        }
        cout<<"\n";
    }
    else QQ.enQueue(data);
   
}
//-------------------//
void BinaryTree :: displayTree()
{
    if(!root) return;
    int i = 0, temp_int = 0, j = 0;
    TreeNode<int> *temp  = new TreeNode<int>;
    Queue <TreeNode<int>*> Q;
    Q.enQueue(root);
    while(!Q.isEmpty())
    {
        temp = Q.deQueue();
        no_of_elements++;
        temp_int = pow(2, j); //t_int is No of Nodes per level
        displayNode(temp->getData(), temp_int);
         
        if(no_of_elements == pow(2, i))
        {
            height++;
            i++; j++;
        }        
        if(temp->getLeft()) Q.enQueue(temp->getLeft());
        if(temp->getRight()) Q.enQueue(temp->getRight());
    }
    cout<<"\nNo of Elements Are: "<<no_of_elements;
    cout<<"\nNo of Levels Are: "<<height;
}
//-------------------//
void BinaryTree :: createTree()
{
    int num; char ch;
    do
    {
        cout<<"\nEnter a Value: "; cin>>num; system("clear");
        insert(num);
        cout<<"\nWanna Enter More (y/Y)";cin>>ch;

    } while ((ch=='y') || (ch=='Y'));
    cout<<"\nA Binary Tree Created";
    
}
//-----------------//
void BinaryTree :: insert(int val)
{
    if(!root)
    {
        TreeNode<int>* newNode = new TreeNode<int>;
        newNode->setLeft(NULL);
        newNode->setRight(NULL);
        newNode->setData(val);
        root = newNode;
    }
    else
    {
        TreeNode <int> *p, *q;
        p = q = root;
        while(q != NULL)
        {
            p = q;
            if(val < p->getData()) q = p->getLeft();
            else if(val > p->getData()) q = p->getRight();
            else break; //If Duplicate Found!
        }
        if(val == p->getData()) cout<<"\nThe Value You Entered is Duplicate\nSo Not Inserted!";
        else if(val < p->getData())
        {
            TreeNode<int>* newNode = new TreeNode<int>;
            newNode->setLeft(NULL);
            newNode->setRight(NULL);
            newNode->setData(val);
            p->setLeft(newNode);
        }
        else
        {
            TreeNode<int>* newNode = new TreeNode<int>;
            newNode->setLeft(NULL);
            newNode->setRight(NULL);
            newNode->setData(val);
            p->setRight(newNode);
        }
    }
}
//-----------------//
void BinaryTree :: preOrderTrv(TreeNode<int> *rt)
{
    if(rt)
    {
        cout<<rt->getData()<<"\t";
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
//////////////////////
int main()
{
    BinaryTree myTr;
    bool mycheck = false; int num, ch; int tempData;
    char ch1;
    do
    {
        cout<<"\n1. Create a Tree"
            <<"\n2. Insert"
            <<"\n3. Delete"
            <<"\n4. Sort"
            <<"\n5. Search"
            <<"\n6. Check If Leaf/NonLeaf"
            <<"\n7. View Tree Data (Traverse Through)"
            <<"\n8. DisplayTree"
            <<"\n9. Exit\n";
        cin>>ch;
        system("clear");
        switch(ch)
        {
            case 1:
                myTr.createTree();
                break;
            case 2:
                cout<<"\nEnter Value to insert: "; cin>>num;
                myTr.insert(num);
                break;
            // case 3:
            //     cout<<"\nEnter Data to be Deleted in the list: ";
            //     cin>>tempData;
            //     myTr.deleteNode(tempData);
            //     break;
            // case 4:
            //     cout<<"\nAscending (a/A)"
            //         <<"\nDescending (d/D)"
            //         <<"\nEnterChoice!: ";
            //     cin>>ch1;
            //     switch(ch1)
            //     {
            //         case 'a':
            //         case 'A':
            //             myLL.sortList(ch1);
            //             break;
            //         case 'd':
            //         case 'D':
            //             myLL.sortList(ch1);
            //             break;
            //         default:
            //             cout<<"\nWrong Choice!";
            //     }
            //     break;
            // case 5:
            //     cout<<"\nEnter Data to be searched in the list: ";
            //     cin>>tempData;
            //     if(myLL.search(tempData)) cout<<"\nData Found!";
            //     else cout<<"\nNot Found";
            //     break;
            // case 6:
            //     cout<<"\nThe Size of the List is: "<<myLL.getSize();
            //     break;
            case 7:
                cout<<"\n1.PreOrderly"
                    <<"\n2.PostOrderly"
                    <<"\n3.InOrderly"
                    <<"\n4.LevelOrderly"
                    <<"\nEnterChoice!: ";
                cin>>ch1;
                switch(ch1)
                {
                    case '1':
                        myTr.preOrderTrv(myTr.getRoot());
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
            case 8:
                myTr.displayTree();
                break;
            case 9:
                return 0;
                break;
        }
    }while(1);

    cout<<endl;
    return 0;
}
