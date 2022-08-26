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
    int rootVal;
    bool isUnivalTree(TreeNode* root) {
        
      if(root==NULL) return true;
       rootVal=root->val;
        return check(root);
       
        }
    
 private:
      bool check(TreeNode* root)
      {
          if(root==NULL) return true;
          if(root->val!=rootVal) return false;
          else
          {
              return (check(root->left) && check(root->right));
          }
            
      }
        
    
};