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
    TreeNode* searchBST(TreeNode* root, int val) {
        
        return search(root,val);
        
    }
    
TreeNode* search(TreeNode* root,int val)
{
    if(root==NULL)
    {
        return NULL;
    }
    
    if(val==root->val)
        return root;
    
    if(val>root->val && root->right!=NULL)
         return search(root->right,val);
    
    if(val<root->val && root->left!=NULL)
        return search(root->left,val);
    
    return NULL;
}
};