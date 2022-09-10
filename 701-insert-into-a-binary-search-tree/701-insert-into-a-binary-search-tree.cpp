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
            root=new TreeNode(val);
            return root;
        }
        
        insert(root,val);
        
        return root;
        
    }

private:
    void insert(TreeNode* root,int val)
    {
        if(val>root->val)
        {
            if(root->right!=NULL)
            {
                insert(root->right,val);
            }
            else {root->right=new TreeNode(val);}
            
        }
        else
        {
            if(root->left!=NULL) {insert(root->left,val);}
            else {root->left=new TreeNode(val);}
        }
    }
};