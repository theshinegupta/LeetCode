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
    vector<int> inorderTraversal(TreeNode* root) {
        
      vector<int> res;
        if(root==NULL)
            return res;
        
        stack<TreeNode*> s;
        // s.push(root);
        TreeNode* currNode=root;
        
        while(!s.empty() || currNode!=NULL)
        {
            while(currNode!=NULL)
            {
                s.push(currNode);
                currNode=currNode->left;
            }
            
            currNode=s.top();
            s.pop();
            res.push_back(currNode->val);
            currNode=currNode->right;
        }
        
        return res;
    }
    
// void inorder(TreeNode* root,vector<int>& res)
// {
//     if(root==NULL)
//         return;
    
//     inorder(root->left,res);
//     res.push_back(root->val);
//     inorder(root->right,res);
    
//     return;
// }
};