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
    ListNode* ptr=NULL;
    ListNode* reverseList(ListNode* head) {
        
        rev(head,NULL);
        
        return ptr;
        
        
    }
    
void rev(ListNode* head,ListNode*  prev)
{
    if(head==NULL)
    {
      return;
    }
    
    if(head->next==NULL)
        ptr=head;
    
   
    rev(head->next,head);
    
    head->next=prev;
}
        
        
        
};