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
    TreeNode* temp;
    TreeNode* searchBST(TreeNode* root, int val) {
        
       while(root)
       {
           
           if(val==root->val) {return root;}
           else
           {
               if(val<root->val && root->left!=NULL) {root=root->left;}
               else
               {
                   if(val>root->val && root->right!=NULL) {root=root->right;}
                   else break;
                 
               }
           }
       }
        
        return NULL;
        
    }
private:
    
};