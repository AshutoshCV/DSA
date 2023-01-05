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
void insertathead(node*&head,int d)
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
        cout<< temp->data <<" " ;
        temp=temp->next;
    }
    cout<<endl;
}
void removedublicates(node* &head)
{
    if(head==NULL)
    {
        cout<< " list is empty "<<endl;
        return ;
    }
    else
    {
        node* curr=head;
        while(curr->next!=NULL){
        if(curr->data==curr->next->data)
        {
            node* temp=curr->next->next;
            curr->next=NULL;
            delete curr;
            curr->next=temp;
            
        }
        else
        {
            curr=curr->next;
        }
    }
}
}
void removDublUnsorted(node*head)
{
    node* curr=head;
    node* prev=NULL;
    node* next_next;

    map<int,int>M;
    while(curr!=NULL){
    if(M[curr->data]) //if the value is already found 
    {
        prev->next=curr->next;
        next_next=curr;
        curr=curr->next; 
        delete (next_next);
        continue;  
    }
    prev=curr;
    M[curr->data]=1;
    curr=curr->next;
}
}
int main() 
{
    node* node1=new node(10);
    node* head=node1;
    insertathead(head,5);
    insertathead(head,20);
    insertathead(head,5);
    insertathead(head,10);  
    //print(head);
   // removedublicates(head);
    //print(head);
    removDublUnsorted(head);
    print(head);
}