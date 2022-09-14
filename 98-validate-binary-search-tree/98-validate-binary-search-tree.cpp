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
      long long  prev=1e18;
      bool flag=true;
    
    bool isValidBST(TreeNode* root) {
        
         if(root->left==NULL && root->right==NULL) return true;
        check(root);
        
        return flag;
        
    }
private:
     void check(TreeNode* root)
     {
         if(root==NULL) return;
         
         check(root->left);
         
         if(prev==1e18) {prev=root->val;}
         else
         {
             int currVal=root->val;
             if(currVal<=prev) {flag=false;}
             
             prev=currVal;
         }
         
         check(root->right);
     }
};