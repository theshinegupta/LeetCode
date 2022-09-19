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
    TreeNode* bstToGst(TreeNode* root) {
        
        
        shineTraversal(root);
        
        return root;
    }
private:
     int prev=-1;
     void shineTraversal(TreeNode* root)
     {
         if(root==NULL) return;
         
         shineTraversal(root->right);
         
         if(prev==-1) prev=root->val;
         else
         {
             root->val=root->val+prev;
             prev=root->val;
         }
         
         shineTraversal(root->left);
     }
};