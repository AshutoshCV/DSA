#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int d)
    {
        this->data=d;
        this->next=NULL;
    }
};
void reverselinkedlist(node* &head)
{
    node* prev=NULL;
    node* curr=head;
    node* forward=NULL;
    while(curr!=NULL)
    {
    forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;
    }
     head=prev;
}
void pushdata(node* &head,int d)
{
    node* temp=new node(d);
    temp->next=head;
    head=temp;
}
void print(node* &head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data <<" "  ;
        temp=temp->next;
    }
}
int main()
{
    node* node1=new node(10);
    node* head= node1;
    pushdata(head,12);
    pushdata(head,13);
     pushdata(head,10);
    pushdata(head,11);
    print(head);
    cout<< endl;
    reverselinkedlist(head);
    print(head);
    return 0;
}
