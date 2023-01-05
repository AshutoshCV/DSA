#include<iostream>
using namespace std;
class Node {
    public:
    int newvalue;
    Node* next;
    Node(int newvalue)
    {
        this->newvalue=newvalue;
        this->next=NULL;
    }
};
void insertathead(Node* &head,int newvalue)
{
    //1.prepare a newn ode 
    Node* newNode= new Node(newvalue);
    //2.put it in front of  current head
   // newNode->newvalue=newvalue;
    newNode->next=head;
    //3.move head to list the list to point to the newNode
    head=newNode; 
}void printlist(Node* n)
{
     while(n!=NULL)
     {
         cout<< n->newvalue << " ";
         n=n->next;
     }
}
int main()
{
    Node* head=NULL;
    Node* second=NULL;
    Node* third=NULL;

    head=new Node(1);
    second= new Node(2);
    third= new Node(3);
    //allocate 3 nodes in heap
    //head->newvalue=1;  // asssign data to first nodes
    head->next=second;  // link first nodes to second

    //second->newvalue=2;
    second->next=third;

   // third->newvalue=3;
    third->next=NULL;
    insertathead(head,-1);
    insertathead(head,-3);
     printlist(head);
     
    return 0;
}