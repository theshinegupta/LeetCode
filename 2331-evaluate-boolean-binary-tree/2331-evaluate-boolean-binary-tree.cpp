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
    bool evaluateTree(TreeNode* root) {
        
        int flag=check(root);
        
        if(flag==1) return true;
        else return false;
        
        
        
    }
private:
    
    int check(TreeNode* root)
    {
        if(root->left==NULL && root->right==NULL) return root->val;
        
        if(root->val==3)
        {
            return (check(root->left) && check(root->right));
        }
        else {return (check(root->left)|| check(root->right));}
    }
};