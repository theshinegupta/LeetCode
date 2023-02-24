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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1==NULL || l2==NULL)
            return  (l1==NULL)?l2:l1;
        
        
        
            ListNode* curr=(l1->val<l2->val)?l1:l2;
            if(curr==l1)
            {
                l1=l1->next;
            }
           else
           {
               l2=l2->next;
           }
        
            ListNode* temp=curr;
        
            while(l1 && l2)
            {
                curr->next=(l1->val<l2->val)?l1:l2;
                
                if(curr->next==l1)
                {
                    curr=l1;
                    l1=l1->next;
                }
                else
                {
                    curr=l2;
                    l2=l2->next;
                }
            }
        
        if(l1==NULL)
            curr->next=l2;
        else
            curr->next=l1;
        
        return temp;
        
          
        
        
        
    }
};