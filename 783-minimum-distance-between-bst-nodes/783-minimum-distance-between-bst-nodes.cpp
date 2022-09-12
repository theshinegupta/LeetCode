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
    int minVal=INT_MAX;
    vector<int> v;
    int minDiffInBST(TreeNode* root) {
        
         inorder(root);
        
        for(int i=1;i<v.size();i++)
        {
            minVal=min((v[i]-v[i-1]),minVal);
        }
        return minVal;
    }

  private:
    
    void inorder(TreeNode* root)
    {
        if(root==NULL) return;
        inorder(root->left);
        
        v.push_back(root->val);
        inorder(root->right);
    }
};