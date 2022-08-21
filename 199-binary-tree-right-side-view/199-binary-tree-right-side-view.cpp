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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> v;
        if(root==NULL) return v;
        queue<TreeNode*> q;
        
        q.push(root);
        q.push(NULL);
        TreeNode* temp;
        while(q.size())
        {
            if(q.front()!=NULL)
            {
                temp=q.front();
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
                
                q.pop();
                
            }
            else
            {
                 q.push(NULL);
                 v.push_back(temp->val);
                 q.pop();
                if(q.front()==NULL) break;
                
                
            }
        }
        
        return v;
        
    }
};