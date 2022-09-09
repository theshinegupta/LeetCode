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
    
    int flag=0;
    int target;
    bool hasPathSum(TreeNode* root, int targetSum) {
        
         target=targetSum;
         if(root==NULL)  return false;
        
         if(root->left==NULL && root->right==NULL)
         {
             if(root->val==target) return true;
              else false;
         }
        
         if(root->left!=NULL) pathSum(root->left,root->val);
         if(root->right!=NULL) pathSum(root->right,root->val);
        
        
        
        
   
   if(flag==1) return true;
        else return false;
        
    }
    
private:
     void pathSum(TreeNode* root,int currSum)
     {
         if(root==NULL)  return;
         
         if(root->left==NULL  && root->right==NULL && (currSum+root->val)==target) flag=1;
         
        if(root->left!=NULL) pathSum(root->left,root->val+currSum);
        if(root->right!=NULL) pathSum(root->right,root->val+currSum);
     }
};