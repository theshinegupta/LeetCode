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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool flag=false;
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        preOrder(root,head);
        
        //cout<<flag<<" ";
        return flag;
        
    }
    
void preOrder(TreeNode* root,ListNode* head)
{
    if(root==NULL)
        return;
    
    if(root->val==head->val)
    {
        
        flag=findList(root,head);
        if(flag==true)
        {
           
            return;
        } 
        
    }
    
    preOrder(root->left,head);
    
    if(flag) return;
    preOrder(root->right,head);
}
    
bool findList(TreeNode* root,ListNode* ptr)
{
    if(!ptr->next && root!=NULL && root->val==ptr->val)
        return true;
    
    if(root==NULL)
        return false;
    
    return (root->val==ptr->val) && (findList(root->left,ptr->next) || findList(root->right,ptr->next));
}
    
};