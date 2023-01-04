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
     int res=INT_MIN;
    int longestUnivaluePath(TreeNode* root) {
        
       if(root==NULL)
           return 0;
        
        preOrder(root);
        
        return res;
    }
    
void preOrder(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    
    
    int lHeight=findHeight(root->left,root->val);
    int rHeight=findHeight(root->right,root->val);
    
    int tempAns=lHeight+rHeight;
    
    res=max(tempAns,res);
    
    preOrder(root->left);
    preOrder(root->right);
    
}
    
int findHeight(TreeNode* root,int data)
{
    if(root==NULL || root->val!=data)
    {
        return 0;
    }
    
     return max(findHeight(root->left,data),findHeight(root->right,data))+1;
}
};