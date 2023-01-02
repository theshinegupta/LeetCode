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
    int sumNumbers(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        if(root->left==NULL && root->right==NULL)
            return root->val;
        
        return findSum(root->left,root->val)+findSum(root->right,root->val);
        
    }
    
int findSum(TreeNode* root,int currVal)
{
    if(root==NULL)
        return 0;
    
    
    if(root->left==NULL && root->right==NULL)
    {
        return (currVal*10+root->val);
    }
    
    int temp=currVal*10+root->val;
    return findSum(root->left,temp) +findSum(root->right,temp);
}
};