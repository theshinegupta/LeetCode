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
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        
        int ans=0;
        
        preOrder(root,ans,low,high);
        return ans;
        
        
        
    }

    void preOrder(TreeNode* root,int &ans ,int low ,int high)
    {
        if(root==NULL)
            return;
        
        if(root->val>=low && root->val<=high)
        {
            ans+=root->val;
        }
        
        preOrder(root->left,ans,low,high);
        preOrder(root->right,ans,low,high);
        
        
    }
};