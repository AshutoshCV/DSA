#include<iostream>
#include<map>
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
void insertnode(node* &tail,int element,int d)
{
    //if empty linked list
    if(tail==NULL)
    {
        node* newnode= new node(d);
        tail=newnode;
        newnode->next=newnode;
    }
    //when one and more than one element is present
    else
    {
        node*curr=tail;
        while(curr->data!=element)
        {
            curr=curr->next;
        }
        node* temp=new node(d);
        temp->next=curr->next;
        curr->next=temp;
       // curr=temp;
    }
}
void print(node* tail)
{
    node*temp=tail;
    if(tail==NULL)
    {
        cout<< "List is empty!!" <<endl;
    }
    while(temp->next!=tail)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}
node* floydDetectloop(node* head)
{
    node* slow=head;
    node* fast=head;
    while(slow!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;    
    if(slow==fast)
    {
     cout<<slow->data<<endl;
     return slow;
    }
    }
    return NULL;
}
node* getstartingnode(node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    node* intersection= floydDetectloop(head);
    node* slow=head;
    while(slow!=intersection)
    {
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}
void removeloop(node* head)
{
    if(head==NULL)
    {
        return ;
    }
    node* startingloop=getstartingnode(head);
    node* temp=startingloop;
    while(temp->next!=startingloop)
    {
        temp=temp->next;
    }
    temp->next=NULL;
}
int main()
{
    node* node1=new node(10);
    node* tail=node1;
//    // node* head=node1;
    insertnode(tail,0,3);
    insertnode(tail,3,4);
    insertnode(tail,3,5);
    insertnode(tail,4,6);
  //  print(tail);
    //tail->next=head->next;
    if(floydDetectloop(tail))
    {
        cout<< " cycle is present " <<endl;
    }
    else
    {
        cout<< " cycle is not present " <<endl;
    }
    node* loop=getstartingnode(tail);
  //  cout<< "loop starts at " << loop->data<<endl;
    removeloop(tail);
    cout<< "loop starts at " << loop->data<<endl;
    print(tail);
    return 0;
}