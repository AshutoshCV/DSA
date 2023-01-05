#include<iostream>
using namespace std;
class Nodes {
    public:
    int data;
    Nodes* next;
    Nodes(int data)
    {
        this->data=data;
        this->next=nullptr;
    }
};
int main()
{
    Nodes *node1= new Nodes(10);
    cout<< node1->data << endl;
    cout<< node1->next << endl;
    return 0;

}