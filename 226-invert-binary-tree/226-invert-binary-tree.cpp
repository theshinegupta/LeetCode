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
    TreeNode* invertTree(TreeNode* root) {
        
        if(root==NULL) return root;
        
        invert(root);
        return root;
    }
    
private:
    
    void invert(TreeNode* root)
    {
        if(root->left==NULL && root->right==NULL) return;
        
        if(root->left==NULL)
        {
            root->left=root->right;
            root->right=NULL;
            
            invert(root->left);
            
            return;
        }
        
        if(root->right==NULL)
        {
            
            root->right=root->left;
            root->left=NULL;
            
            invert(root->right);
            
            return;
        }
        
        
        TreeNode* temp=root->right;
        
        root->right=root->left;
        root->left=temp;
        
        invert(root->left);
        invert(root->right);
        
        
        
    }
};