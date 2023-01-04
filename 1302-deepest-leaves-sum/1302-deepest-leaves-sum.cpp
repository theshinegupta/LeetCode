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
    int deepestLeavesSum(TreeNode* root) {
        
        int res=0;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            
            TreeNode* temp=q.front();
            q.pop();
            
            if(temp!=NULL)
            {
                res+=temp->val;
                
                if(temp->left) q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            else
            {
                if(!q.empty())
                {
                    res=0;
                    q.push(NULL);
                }
            }
            
        }
        
        return res;
    }
};