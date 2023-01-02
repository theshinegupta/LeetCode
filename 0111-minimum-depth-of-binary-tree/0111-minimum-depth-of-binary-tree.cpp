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
    int minDepth(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        int minDepths=INT_MAX;
        findDepth(root,0,minDepths);
        
        return minDepths;
        
    }
    

    void findDepth(TreeNode* root,int currDepth,int & minDepths)
    {
        if(root==NULL)
        {
            return;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            minDepths=min(currDepth+1,minDepths);
            return;
        }
        
        findDepth(root->left,currDepth+1,minDepths);
        findDepth(root->right,currDepth+1,minDepths);
        
    }
};