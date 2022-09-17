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
        
       
        return findSum(root);
        
        
        
    }
private:
    int findSum(TreeNode* root)
    {
        queue<TreeNode*> q;
        
        q.push(root);
        q.push(NULL);
        int sum=0;
        while(q.size())
        {
            TreeNode* temp=q.front();q.pop();
            
            if(temp!=NULL)
            {
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
                
                sum+=temp->val;
            }
            
            else
            {
                if(q.size()==NULL) break;
                sum=0;
                q.push(NULL);
            }
        }
        
        return sum;
        
    }
};