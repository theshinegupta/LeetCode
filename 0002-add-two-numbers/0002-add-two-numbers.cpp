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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        ListNode* head=l2;
        
        ListNode* prev=l2;
        int carry=0;
       
        while(l1 && l2)
        {
            int temp=l1->val+l2->val+carry;
            
            if(temp>9)
                carry=temp/10;
            else
                carry=0;
            
            l2->val=temp%10;
            prev=l2;
            l2=l2->next;
            l1=l1->next;
        }
        
        ListNode* temp=new ListNode(carry);
        
        if(l1==NULL && l2==NULL)
        {
            if(carry)
            {
              prev->next=temp;  
            }
            
            
            return head;
            
            
        }
        
        
        ListNode* curr=NULL;
        if(l2==NULL)
        {
            curr=l1;
            prev->next=curr;
            
        }
        else
            curr=l2;
        
        
        
        
        while(curr)
        {
            int temp=curr->val+carry;
            
            if(temp>9)
                carry=temp/10;
            else
                carry=0;
            
            curr->val=temp%10;
            prev=curr;
            curr=curr->next;
            
            
        }
        
        
        ListNode* temp2=new ListNode(carry);
        
        if(carry)
            prev->next=temp2;
        
        return head;
        
        
            
        
    }
};