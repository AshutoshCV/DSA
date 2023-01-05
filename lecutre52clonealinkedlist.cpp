#include<iostream>
#include<unordered_map>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node* random;
    node(int data)
    {
        this->data=data;
        next=random=NULL;
    }
};
 void insertattail(node* &tail,int d)
    {
        node *temp=new node(d);
        tail->next=temp;
        //tail=temp;
        tail=tail->next;
    }
node* clonelist(node* head)
{
    node *originalhead=head; 
    node*clonehead;
    unordered_map<node*,node*>map;
    //Dublicate of the first node
    while(originalhead!=NULL)
    {
        clonehead=new node(originalhead->data);
        map[originalhead]=clonehead;
        originalhead=originalhead->next;
    }
    originalhead=head;
    while(originalhead!=NULL)
    {
        clonehead=map[originalhead];
        clonehead->next=(originalhead->next!=NULL)? map[originalhead->next]:NULL;
        clonehead->random=(originalhead->random!=NULL)? map[originalhead->random]:NULL;
        originalhead=originalhead->next;
    }
    return map[head];
}
void printlist(node* &head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->"<<head->random->data;
        cout<<endl;
        head=head->next;
    }
    cout<<endl;
}
int main()
{
   node* head = NULL;
    
    node* node1 = new node(1);
    node* node2 = new node(2);
    node* node3 = new node(3);
    node* node4 = new node(4);
    node* node5 = new node(5);
    head = node1;
    head->next = node2;
    head->next->next = node3;
    head->next->next->next = node4;
    
    head->random = node4;
    head->next->random = node1;
    head->next->next->random = node5;
    head->next->next->next->random = node2;
   cout<<" the original list is: " <<endl;
   printlist(head);
   node* result=clonelist(head);
   cout<<" the clone list is: " <<endl;
   printlist(result);
   return 0;
}
