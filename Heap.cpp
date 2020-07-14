#include <iostream>
#define SENTINAL 99999
using namespace std;
///////////////////
class Heap
{
    protected:
        int *heaparr, current_size;
        int CAPACITY;
    public:
        Heap(int capacity)
        {
            this->CAPACITY = capacity;
            heaparr = new int[CAPACITY];
            current_size = 0;
        }
        virtual void insert(int val) = 0;
        virtual void buildHeap() = 0;
        virtual int remove() = 0;
        void displayHeap();
        bool isFull()
        { 
            if(current_size==CAPACITY) return true;
            else return false; 
        }
        bool isEmpty()
        { 
            if(current_size==0) return true;
            else return false; 
        }
    
};
void Heap::displayHeap()
{
    cout<<"\nThe HEAP is As:\n";
    for(int i = 0; i < current_size; i++) cout<<heaparr[i]<<" ";
}
//------------------------//
class MaxHeap: public Heap
{
    public:
        MaxHeap(int capacity = 50) : Heap(capacity) 
        {
            
        }
        void insert(int val);
        void buildHeap();
        int remove(); //del_data = data_to_be_deleted
        //bbss
};
void MaxHeap::buildHeap()
{
    int val; char ch;
    do
    {
        cout<<"\nEnter a value to insert: "; cin>>val;
        this->insert(val);
        cout<<"\nWanna Enter More?(y/Y): "; cin>>ch;
    } while ((ch=='y')||(ch=='Y'));
    
}
void MaxHeap::insert(int val)
{
    cout<<"\nheaparr[i]= "<<heaparr[0];

    if(isFull())
    {
        cout<<"\nCannot Insert, Heap is FULL!";
        return;
    }
    int i = current_size++;
    cout<<"\ni= "<<i;
    heaparr[i] = val;
    // for(;heaparr[(i-1)/2] < val;i = (i-1)/2) //i.e if parent is less than val (MAXHEAP)
    //     heaparr[i] = heaparr[(i-1)/2];
    
    while(heaparr[i] < val)
    {
        heaparr[i] = heaparr[(i-1)/2];
        i = (i-1)/2;
    }
    heaparr[i] = val;
    cout<<"\nins";
}
int MaxHeap::remove()
{
    if(isEmpty())
    {
        cout<<"\nCannot Remove, Heap is Empty!";
        return SENTINAL;
    }
    current_size--;
    int deldata = heaparr[0];
    int temp = heaparr[current_size-1];
    int i = 0;
    do
    {
        if(heaparr[i*2+1] > heaparr[i*2+2])
        {
            if(temp < heaparr[i*2+1]){
                heaparr[i] = heaparr[i*2+1];
                i = i*2+1;
            }
        }
        else
        {
            if(temp < heaparr[i*2+2]){
                heaparr[i] = heaparr[i*2+2];
                i = i*2+2;
            }
        }
    } while (temp < heaparr[i]);
    return deldata;
}
//TESTER
int main()
{
    Heap* hp = new MaxHeap(10);
    hp->buildHeap();
    hp->displayHeap();
    cout<<"\nThe "<<hp->remove()<<" has been deleted.\n";
    hp->displayHeap();    

    cout<<endl;
    return 0;
}