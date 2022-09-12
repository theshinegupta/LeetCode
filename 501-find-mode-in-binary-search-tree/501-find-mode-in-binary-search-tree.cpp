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
   int maxVal=INT_MIN;
    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        
        
        
        
        counter(root);
        // for(auto x:mp)
        // {
        //     if(x.second>maxVal) maxVal=x.second;
        // }
        
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
        
        if(mp.find(root->val)==mp.end()) {mp.insert({root->val,1}); maxVal=max(mp[root->val],maxVal);}
        else {mp[root->val]++; maxVal=max(mp[root->val],maxVal);}
        
        counter(root->left);
        counter(root->right);
    }
    
};