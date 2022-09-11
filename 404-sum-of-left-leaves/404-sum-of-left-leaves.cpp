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
    
    int ans=0;
    int sumOfLeftLeaves(TreeNode* root) {
        
     sum(root,false);
        
    return ans;
        
    }
    void sum(TreeNode* root,bool isleft)
    {
        if(root==NULL) return;
        
        if(root->left==NULL && root->right==NULL && isleft) {ans+=root->val;}
        
        sum(root->left,true);
        sum(root->right,false);
        return;
    }
};