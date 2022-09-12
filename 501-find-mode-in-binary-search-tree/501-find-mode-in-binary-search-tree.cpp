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
    map<int,int> mp;
    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        
        
        int maxVal=INT_MIN;
        
        counter(root);
        for(auto x:mp)
        {
            if(x.second>maxVal) maxVal=x.second;
        }
        
        for(auto x: mp)
        {
            if(x.second==maxVal) v.push_back(x.first);
        }
        
        
        
        
        return v;
    }
private:
    
    void counter(TreeNode* root)
    {
        if(root==NULL) return;
        
        if(mp.find(root->val)==mp.end()) {mp.insert({root->val,1});}
        else {mp[root->val]++;}
        
        counter(root->left);
        counter(root->right);
    }
};