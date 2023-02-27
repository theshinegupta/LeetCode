/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        // ListNode* dummy=new ListNode(-1);
      
        return reverseKardo(head,k);
        
    }
    
ListNode* reverseKardo(ListNode* head,int k)
{
    if(head==NULL)
        return NULL;
    
    ListNode* start=head;
    ListNode* end=head;
    ListNode* temp=NULL;
    int count=1;
    
    while(end!=NULL)
    {
        end=end->next;
        count++;
        
        
        if(count==k)
        {
            temp=end;
            break;
        }
    }
    
    if(temp==NULL)
        return head;
    
    end=end->next;
   
    reverse(start,temp);
    
    start->next=reverseKardo(end,k);
    
    return temp;
    
}
    
void reverse(ListNode* start,ListNode* end)
{
    ListNode* prev=NULL;
    ListNode* curr=start;
    ListNode* nxt=curr->next;
    
    while(nxt!=end)
    {
        curr->next=prev;
        prev=curr;
        curr=nxt;
        nxt=nxt->next;
        
    }
    
    curr->next=prev;
    nxt->next=curr;
    
    
}
    
    

};