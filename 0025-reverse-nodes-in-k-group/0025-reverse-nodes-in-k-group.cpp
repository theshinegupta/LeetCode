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
        
    
        int count=0;
        ListNode* ptr=head;
        if(k==1)
            return head;
        
         while(ptr){
            ptr=ptr->next;
            count++;
         }
        
        if(k==count)
        {
           return reverseList(head);
        }
        
        
        int times=(count-(count%k))/k;
        
        
        ptr=head;
        ListNode* start=NULL;
        ListNode* prevEnd=NULL;
        ListNode* finalHead=NULL;
        ListNode* temp=NULL;
        ListNode* temp2=NULL;
        
        int passNodes=1;
        int counter=0;
        
        while(ptr && counter<times)
        {
            if(passNodes==1)
                 start=ptr;
            
            ptr=ptr->next;
            passNodes++;
            
             if(ptr==NULL)
                 break;
            
            if(passNodes==k+1)
            {
                pair<ListNode*, ListNode*> shine=rev(start,k);
                if(counter==0)
                {
                    finalHead=shine.second;
                    prevEnd=shine.first;    
                    // break;
                }
                else
                {
                    prevEnd->next=shine.second;
                    prevEnd=shine.first;
                       
                }
                
                temp=ptr;
                
                temp2=ptr; 
                passNodes=1;
                // cout<<"here"<<" ";
                counter++;
            }
        }
        
       
        if(count%k)
          prevEnd->next=temp;
        else
            prevEnd->next=reverseList(start);

        
        return finalHead;
        
        
    }
    
pair<ListNode*,ListNode*> rev(ListNode* head,int k)
{
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* nxt=curr->next;
    
    int temp=1;
    
    while(curr && curr->next)
    {
        curr->next=prev;
        prev=curr;
        curr=nxt;
        nxt=nxt->next;
        temp++;
        if(temp==k+1)
            break;
    }
    
    return {head,prev};
}
    
   
ListNode* reverseList(ListNode* head) {
        
        
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