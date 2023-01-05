#include<iostream>
#include<map>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    ~Node()
    {
        int value=this->data;
        if(this->next!=NULL)
        delete next;
        this->next=NULL;
    }
};

    void insertathead(Node* &head,int d)
    {
        Node* temp=new Node(d);
        temp-> next=head;
        head=temp;

   }
    void insertattail(Node* &tail,int d)
    {
        Node *temp=new Node(d);
        tail->next=temp;
        //tail=temp;
        tail=tail->next;
    }
    void insertatposition(Node* &head,Node* &tail,int position, int d)
    {
        if(position==1)
        {
            insertathead(head,d);
            return ;
        }
        Node* temp=head;
        int count=1;
        while(count<position-1)
        {
            temp=temp->next;
            count++;
        }
        Node* nodetoinsert=new Node(d);
        nodetoinsert->next=temp->next;
        temp->next=nodetoinsert;

        if(temp->next==NULL)
        {
            insertattail(tail,d);
            return;
        }
    }
    void deletion(Node* & head,int position)
    {
        if(position==1)
        {
            Node *temp=head;
            head=head->next;
            //free up memory 
            temp->next=NULL;
            cout<<"Deleted element is " <<temp->data<< endl;
            delete temp;
        }
        else
    {
        Node*curr=head;
        Node*prev=NULL;
        int count=1;
        while(count<position)
        {
            prev=curr;
            curr=curr->next;
            count++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        cout<<"Deleted element is " << curr->data <<endl;
        delete curr;        
    }
}

void print(Node* &head)
{
    if(head==NULL)
    {
        cout<< " list is empty " <<endl;
        return;
    }
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<< temp->data<<" ";
        temp=temp->next;
    }
    cout<< endl;
}
bool iscircularornot(Node* head)
{
    //empty list
    if(head==NULL)
    {
        return true;
    }
    Node *temp=head->next;
    while(temp!=NULL && temp!=head)
    {
        temp=temp->next;
    }
    if(temp==head)
    {
        return true;
    }
    return false;
}
bool detectloop(Node*head)
{
    if(head==NULL)
    {
        return false;
    }
    map<Node*,bool> visited;
    Node* temp=head;
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
void createloop(Node* head)
{
    Node* temp=head;
    while(temp->next!=NULL)
    {
    temp=temp->next;
    }
    temp->next=head;
    cout<<temp->next->data<<endl;
}

Node* floydDetectloop(Node* head)
{
    Node* slow=head;
    Node* fast=head;
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
Node* getstartingnode(Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* intersection= floydDetectloop(head);
    Node* slow=head;
    while(slow!=intersection)
    {
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}
void removeloop(Node* head)
{
    if(head==NULL)
    {
        return ;
    }
    Node* startingloop=getstartingnode(head);
    Node* temp=startingloop;
    while(temp->next!=startingloop)
    {
        temp=temp->next;
    }
    temp->next=NULL;
}
int main()
{
    Node *node1= new Node(10);
    Node* head=node1;
    Node* tail=node1;
   // print(head);
    // insertathead(head,30); 
    // insertathead(head,30);
    // insertattail(tail,40);
    // insertattail(head,20);
    // insertathead(head,20);
    // insertatposition(head,tail,4,12);
    // print(head);
    head->next=new Node(15);
    head->next->next= new Node(15);
    head->next->next->next= new Node(20);
    head->next->next->next->next= new Node(30);
    head->next->next->next->next->next= new Node(30);
    createloop(head);
    //print(head);
    // cout<< " head " <<head->data << endl;
    // cout<< " tail " <<tail->data << endl;
    // tail->next=head->next;
    // cout<<tail->next->data;
    if(iscircularornot(head)){
        cout<< "Linked List is circular in nature" <<endl;    
    }
    else
    cout<< "linked list is not circular" <<endl;
    if(detectloop(head)==true)
    {
        cout<< " Loop is present " <<endl;
    }
    else{
        cout<< "Loop is absent " <<endl;
    }
    if(floydDetectloop(head))
    {
        cout<< " cycle is present " <<endl;
    }
    else
    {
        cout<< " cycle is not present " <<endl;
    }
    removeloop(head);
    if(detectloop(head)==true)
    {
        cout<< " Loop is present " <<endl;
    }
    else{
        cout<< "Loop is absent " <<endl;
    }
    print(head);
  //  deletion(head,4);
  //  print(head);
   //  deletion(head,1);
 //   print(head);
    // deletion(head,1);
   // print(head);

    return 0;

}