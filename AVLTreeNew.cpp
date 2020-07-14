#include <iostream>
#include "templateDatastructs.h"
#include <cmath>
using namespace std;
class AVLRecursive
{
    class AVLNode
    {
        public:
        short bf;
        int value;
        AVLNode *left, *right;
        
            int height;
            AVLNode(int val){
                this->value = val;
                left = NULL; right = NULL;
            }
            int getText(){ return value; }
            AVLNode* getLeft(){ return left; }
            AVLNode* getRight(){ return right; }
    };
    int node_count;
    public:
    AVLNode* root;
        AVLRecursive(){
            root = NULL;
            node_count = 0;
        }
        int getHeight(){
            if(!root) return 0;
            else return root->height;
        }
        int size(){
            return node_count;
        }
        bool isEmpty(){
            return size() == 0;
        }
        bool contains(int val){
            return contains(root, val);
        }
        bool contains(AVLNode* root, int val){
            if(!root) return false;

            if(val < root->getText()) return contains(root->getLeft(), val);
            
            if(val > root->getText()) return contains(root->getRight(), val);

            return true;
        }
        bool insert(int value){
            if(!contains(root, value)){
                root = insert(root, value);
                node_count++;
                return true;
            }
            return false;
        }
        AVLNode* insert(AVLNode* root, int value){
            if(root == NULL) return new AVLNode(value);

            if(value < root->getText()){
                root->left = insert(root->getLeft(), value);
            } else {
                root->right = insert(root->getRight(), value);
            }   

            update(root);

            return balance(root);   
        }
        void update(AVLNode* node){
            int leftNodeHeight = (node->left == NULL) ? -1 : node->left->height;

            int rightNodeHeight = (node->right == NULL) ? -1 : node->right->height;

            node->height = 1 + max(leftNodeHeight, rightNodeHeight);
            node->bf = rightNodeHeight - leftNodeHeight;
        }
        AVLNode* balance(AVLNode* node){
            if(node->bf == -2){
                if(node->left->bf <= 0){
                    return leftLeftCase(node);
                } else {
                    return  leftRightCase(node);
                }
            } else if(node->bf == 2){
                if(node->right->bf >= 0){
                    return rightRightCase(node);
                } else {
                    return  rightLeftCase(node);
                }
            }
            return node;
        }
        AVLNode* leftLeftCase(AVLNode* node){
            return rightRotation(node);
        }
        AVLNode* leftRightCase(AVLNode* node){
            node->left = leftRotation(node->left);
            return leftLeftCase(node);
        }
        AVLNode* rightRightCase(AVLNode* node){
            return leftRotation(node);
        }
        AVLNode* rightLeftCase(AVLNode* node){
            node->right = rightRotation(node->right);
            return rightRightCase(node);
        }
        AVLNode* leftRotation(AVLNode* node){
            AVLNode* newParent = node->right;
            node->right = newParent->left;
            newParent->left = node;
            update(node);
            update(newParent);
            return newParent;
        }
        AVLNode* rightRotation(AVLNode* node){
            AVLNode* newParent = node->left;
            node->left = newParent->right;
            newParent->right = node;
            update(node);
            update(newParent);
            return newParent;
        }
        bool remove(int elem){
            if(contains(root, elem)){
                root = remove(root, elem);
                node_count--;
                return true;
            }
            return false;
        }
        AVLNode* remove(AVLNode* node, int elem){
            if(node==NULL) return NULL;

            if(elem < node->getText()){
                node->left = insert(node->getLeft(), elem);
            } else if(elem < node->getText()){
                node->right = insert(node->getRight(), elem);
            } 
            else{
                if(!node->left){
                    return node->right;
                } else if(!node->right){
                    return node->left;
                }
                else{
                    if(node->left->height > node->right->height){
                        int successorValue = findMax(node->left);
                        node->value = successorValue;
                        node->left = remove(node->left, successorValue);
                    } else {
                        int successorValue = findMin(node->right);
                        node->value = successorValue;
                        node->right = remove(node->right, successorValue);
                    }
                }
            }
            update(node);
            return balance(node);
        }
        int findMax(AVLNode* node){
            while(node->right!=NULL){
                node = node->right;
            }
            return node->value;
        }
        int findMin(AVLNode* node){
            while(node->left!=NULL){
                node = node->left;
            }
            return node->value;
        }
        void createTree()
        {
            int val; char ch;
            do
            {
                cout<<"\nEnter a Value For AVLNode: "; cin>>val;
                insert(val);
                cout<<"\nWanna Enter More? (y/Y): "; cin>>ch;

            } while ((ch=='y')||(ch=='Y'));
    
        }
        void levelOrderTrv()
        {
            if(!root) return;
            AVLNode* temp;
            Queue <AVLNode*> Q;
            Q.enQueue(root);
            while(!Q.isEmpty())
            {
                temp = Q.deQueue();
                cout<<temp->value<<"\t";
                if(temp->getLeft()) Q.enQueue(temp->getLeft());
                if(temp->getRight()) Q.enQueue(temp->getRight());
            }
        }
        // void preOrderTrv(AVLNode* rt)
        // {
        //     if(rt)
        //     {
        //         cout<<rt->value<<"\t";
        //         // nofnodes++;
        //         preOrderTrv(rt->getLeft());
        //         preOrderTrv(rt->getRight());
        //     }
        // }

};

int main(){
    AVLRecursive avltree;
    avltree.createTree();
    avltree.levelOrderTrv();

    cout<<endl;
    return 0;
}