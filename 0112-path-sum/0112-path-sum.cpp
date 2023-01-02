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
    bool hasPathSum(TreeNode* root, int target) {
        
        
        if(root==NULL)
            return false;
        
        bool flag=false;
        
        if(root->left==NULL && root->right==NULL)
        {
            return (root->val==target);
        }
       
        return findSum(root->left,root->val,target) || findSum(root->right,root->val,target);
        
 }
    
bool findSum(TreeNode* root,long long currVal,int target)
{
    if(root==NULL)
        return false;
    
    if(root->left==NULL && root->right==NULL)
    {
        long long temp=currVal+root->val;
        return (temp==target);
    }
    
    
    return findSum(root->left,currVal+root->val,target) || findSum(root->right,currVal+root->val,target);
}
};