#include<iostream>
#include<vector>
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
    bool checkpalindrome(vector<int>arr)
    {
        int n=arr.size();
        int s=0;
        int e=n-1;
        while(s<=e)
        {
            if(arr[s]!=arr[e])
            {
            return 0;
            }
            s++;
            e--;
        }
            return 1;
    }
void ispalindrome(node* head)
{
    vector<int>arr;
    node* temp=head;
    while(temp!=NULL)
    {
        arr.push_back(temp->data);
        temp=temp->next;
    }
} 
void insertathead(node* &head,int d)
    {
        node* temp=new node(d);
        temp-> next=head;
        head=temp;
   }   
void insertattail(node* &tail,int d)
    {
        node *temp=new node(d);
        tail->next=temp;
        //tail=temp;
        tail=tail->next;
    }
void print(node* &head)
{
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
        cout<<endl;
}
int main()
{
    vector<int>arr;
    node* node1= new node(10);
    node* head=node1;
    node* tail=node1;
    insertattail(tail,20);
    insertattail(tail,30);
    insertattail(tail,20);
    insertattail(tail,10);
    print(head);
    ispalindrome(head);
    if(checkpalindrome(arr)==true)
    {
        cout<<" list is plaindrome "<<endl;
    }
    else
    {
        cout<<" not plaindrome " <<endl;
    }
    return 0;

}