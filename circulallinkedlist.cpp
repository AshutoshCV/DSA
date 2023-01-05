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
    }
}
void print(node* tail)
{
    node*temp=tail;
    if(tail==NULL)
    {
        cout<< "List is empty!!" <<endl;
    }
    do
    {
        cout<<tail->data<<" ";
        tail=tail->next;
    } while(tail!=temp);
    cout<<endl;
}
node* floydDetectloop(node* head)
{
    if(head=NULL)
    {
        return NULL;
    }
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
bool detectloop(node*head)
{
    if(head==NULL)
    {
        return false;
    }
    map<node*,bool> visited;
    node* temp=head;
    while(temp!=NULL){
    if(visited[temp]==true)
    {
        cout<< "present on element " << temp->data <<endl;
        return true;
    }
    visited[temp]=true;
    temp=temp->next;
}
return false;
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
    cout<<slow->data;
    return slow;
}
int main()
{
    node* tail=NULL;
   // node* loop=getstartingnode(tail);
    insertnode(tail,0,3);
    print(tail);
    insertnode(tail,3,4);
    print(tail);
    insertnode(tail,3,5);
    print(tail);
    if(detectloop(tail)==true)
    {
        cout<< " Loop is present " <<endl;
    }
    else{
        cout<< "Loop is absent " <<endl;
    }
    node* loop=getstartingnode(tail);
    cout<< "loop starts at " << loop->data;
    print(tail);
    return 0;
}