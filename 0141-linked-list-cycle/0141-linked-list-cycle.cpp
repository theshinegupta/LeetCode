/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        int data=100000;
        
        while(head)
        {
            if(head->val>data)
                return true;
            
            head->val=data+head->val;
            head=head->next;
        }
        
        
        return false;
    }
};