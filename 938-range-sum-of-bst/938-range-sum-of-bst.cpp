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
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        long long ans=findSum(root,low,high,0);
        
        return ans;
    }
private:
    
    long long findSum(TreeNode* root,int low,int high,int ans)
    {
        if(root==NULL) return 0;
        
        if(root->val>low && root->val<high) {ans+=root->val;}
        else
        {
            if(root->val==low || root->val==high) {ans+=root->val;}
            else {ans+=0;}
        }
        
        return  (ans+findSum(root->left,low,high,0)+findSum(root->right,low,high,0));
        }
};