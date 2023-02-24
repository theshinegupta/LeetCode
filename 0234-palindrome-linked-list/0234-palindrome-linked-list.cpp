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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=NULL;
        ListNode* fast=head;
        
        if(head->next==NULL)
            return true;
        
        while(fast && fast->next)
        {
            if(slow==NULL)
                slow=head;
            else
                slow=slow->next;
            
            fast=fast->next->next;
        }
        
        ListNode* temp=slow->next;
        slow->next=NULL;
        
        temp=rev(temp);
        
        while(head && temp)
        {
            if(head->val!=temp->val)
                return false;
            
            head=head->next;
            temp=temp->next;
        }
        
        return true;
        
    }
    
ListNode* rev(ListNode* head) {
        
        
        if(head==NULL)
            return head;
        
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nxt=head->next;
        
        
        
        while(nxt)
        {
            curr->next=prev;
            prev=curr;
            curr=nxt;
            nxt=nxt->next;
        }
        
        
        curr->next=prev;
        
        return curr;
    }
    

    
};