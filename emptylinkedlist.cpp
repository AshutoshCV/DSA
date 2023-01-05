#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* prev;
    node* next;
    //constructor
    node(int d)
    {
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
    //destructor for free up memory
   ~node()
    {
        int value=this->data;
        if(this->next!=NULL);
        delete next;
        this->next=NULL;
        cout<< "memory free with value" << value << endl;
    }
};
void insertathead(node* &tail,node* &head,int d)
{
    if(head==NULL)
    {
        node*temp=new node(d);
        head=temp;
        tail=temp;
    }
    else{
    node*temp=new node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
}
void insertattail(node* &tail,node* &head,int d)
{
    if(tail==NULL)
    {
        node*temp=new node(d);
        head=temp;
        tail=temp;
    }
    else
    {
    node*temp=new node(d);
    tail->next=temp;  
    temp->prev=tail;
    tail=tail->next;
    tail=temp; 
}
}
void insertatposition(node* tail,node* head,int position,int d)
{
    //CASE FOR INSERION AT HEAD
    if(position==1)
    {
        insertathead(tail,head,d);
        return;
    }
    //point head to temp
    node* temp=head;
    int count =1;
    while(count<position-1)
    {
        temp=temp->next;
        count++;
    }
    //CASE FOR INSERTION AT TAIL
    if(temp->next==NULL)
    {
        insertattail(tail,head,d);
        return;
    }
    node* nodetoinsert= new node(d);
    nodetoinsert->next=temp->next;
    temp->next->prev=nodetoinsert;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;
}
// CASE OF DELETION
void deletenode(int position,node*&head)
{
    if(position==1)
    {
        node*temp=head;
        //delete first node
        temp->next->prev=NULL;
        head=head->next; //head not updated and pointing to next
        //free start memory
        head=temp->next;
        temp->next=NULL;
        delete temp;
    } 
    //FREE MEMORY OF SPECIFIC NODE
    else
    {
        node*curr=head;
        node*prev=NULL;
        int count=1;
        while(count<position)
        {
            prev=curr;
            curr=curr->next;
            count++;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

void print(node* &head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<< temp->data << " " << endl;
        temp = temp->next;
    }
    cout<< endl;
}
int main()
{
    //empty linked list
    node* head=NULL;
    node* tail=NULL;
    insertathead(tail,head,13);
    print(head);
    insertathead(tail,head,12);
    print(head);
    insertattail(tail,head,14);
    print(head);
    insertatposition(tail,head,2,11);
    print(head);
    deletenode(3,head);
    print(head);
    return 0;

}