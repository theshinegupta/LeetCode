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
    int maxDia=0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        calDiameter(root);
        
        return maxDia;
    }
    
    

    
     int height(TreeNode* root)
     {
         if(root==NULL) return 0;
         
         return max(height(root->left),height(root->right)) +1;
     }
    
    void calDiameter(TreeNode* root)
    {
        int temp;
        
        temp=height(root->left)+height(root->right);
        
        maxDia=max(maxDia,temp);
        
        if(root->left!=NULL)   calDiameter(root->left);
        if(root->right!=NULL)  calDiameter(root->right);
        
        
        
        
    }
      
};