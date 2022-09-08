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
    bool isBalanced(TreeNode* root) {
        
        if(root==NULL) return true;
        
        if(!isBalanced(root->left) || !isBalanced(root->right)) return false;
        else
        {
            int lh=height(root->left);
            int rh=height(root->right);
            
            return ((max(lh,rh)-min(lh,rh))>1)?false:true;
        }
        
    }
    
    int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        
        return max(height(root->left),height(root->right))+1;
    }
};