#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void insertathead(node* &head,int d)
{
    if(head==NULL)
    {
       head=new node(d);
       return;
    }
    node* temp=new node(d);
    temp->next=head;
    head=temp;
}
node* findmid(node* &head)
{
    node* slow=head;
    node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
node* merge(node* left,node* right)
{  
    if(left==NULL)
    {
        return right;
    }
    if(right==NULL)
    {
        return left;
    } 
    node* ans=new node(-1);
    node* temp;
    temp=ans;
    while(left!=NULL && right!=NULL)
    {
        if(left->data<=right->data)
        {
           temp->next=left;
           left=left->next;  
        }
        else
        {
            temp->next=right;
            right=right->next;
        }
        temp=temp->next;
    }
    while(left!=NULL)
    {
       temp->next=left;
       left=left->next;
       temp=temp->next;   
    }
    while(right!=NULL)
    {
       temp->next=right;
       right=right->next; 
       temp=temp->next;
    }
    return ans->next;
}

node* mergesort(node* head)
{
    //Base case
    if(head==NULL || head->next==NULL)
    {  
        return head;
    }
    //divide in halves
    node* mid;
    node* right;
    mid= findmid(head);
    right=mid->next;
    mid->next=NULL;
    
    //recursive calls
    //merge both halves
    node* result=merge(mergesort(head),mergesort(right));
    return result;
}
void printlist(node* n)
{
    while(n!=NULL)
    {
       cout<<n->data<<" ";
       n=n->next;
    }
    cout<<endl;
}
int main()
{
    node* head=NULL;
    node* left,*right;
    insertathead(head,30);
    insertathead(head,5);
    insertathead(head,6);
    printlist(head);
    findmid(head);
    node* sortedhead=mergesort(head);
    printlist(sortedhead);

    return 0;
}