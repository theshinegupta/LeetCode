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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        
     if(root==NULL)
    {
        TreeNode* newNode=new TreeNode(val);
        root=newNode;
        return root;
        
    }
       insert(root,val);
       return root;
        
    }
    
void insert(TreeNode* root,int val)
{
    if(root==NULL)
    {
        TreeNode* newNode=new TreeNode(val);
        root=newNode;
        return;
        
    }
    
    if(val>root->val)
    {
         if(root->right!=NULL)
         {
             insert(root->right,val);
             return;
         }
             
        else
        {
             TreeNode* newNode=new TreeNode(val);
             root->right=newNode;
             return;
        }
    }
    
     if(val<root->val)
    {
         if(root->left!=NULL)
         {
             insert(root->left,val);
             return;
         }
        else
        {
             TreeNode* newNode=new TreeNode(val);
             root->left=newNode;
             return;
        }
    }
    
    
}
};