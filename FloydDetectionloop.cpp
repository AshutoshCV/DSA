Node* floydDetectloop(Node* head)
{
    if(head=NULL)
    {
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;
    while(slow!=NULL && fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast)
        {
            return slow;
        }
    }
    return NULL;