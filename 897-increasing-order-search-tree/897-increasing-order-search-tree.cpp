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
    TreeNode* prev=NULL;
    TreeNode* finalRoot=NULL;
    TreeNode* increasingBST(TreeNode* root) {
        
        finalRoot=root;
        inorderChange(root);
        
        return finalRoot;
        
        
    }
private:
    
    void inorderChange(TreeNode* root)
    {
        if(root==NULL) return;
        
        inorderChange(root->left);
        
        if(prev==NULL){finalRoot=root; prev=root;}
        else
        {
            prev->right=root;
            root->left=NULL;
            prev=root;
        }
        
        
        inorderChange(root->right);
        
    }
    
};