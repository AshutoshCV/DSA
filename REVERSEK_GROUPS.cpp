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
void insertathead(node* &head,int d)
    {
        node* temp=new node(d);
        temp-> next=head;
        head=temp;

   }
node* kreverse(node* head,int k)
{
    if(head==NULL)
    {
        return NULL;
    }
    node* next =NULL;
    node* curr= head;
    node* prev=NULL;
    int count=0;
    while(curr!=NULL && count<k)
    {
       next=curr->next;
      curr->next=prev;
       prev=curr;
       curr=next; 
       count++;  
    }
      cout<< prev->data<<endl;
    if(next!=NULL)
    {
        head->next=kreverse(next,k);
    }
  
    
    return prev;
}
void print(node* &prev)
{
    node* temp=prev;
    while(temp!=NULL)
    {
        cout<< temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node* node1=new node(5);
    node* head= node1;
  
    insertathead(head,4);
    insertathead(head,3);
    insertathead(head,2);
    insertathead(head,1);
    //insertathead(head,60);
    print(head);
    head=kreverse(head,2);
    cout<<endl;
    print(head);
    return 0;
}