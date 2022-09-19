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
    int hash[10000+1]={0};
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> v;
        
            
        inorder(root,v);
        int idx=v.size();
        
        hash[v[idx-1]]=v[idx-1];
        
        // cout<<hash[v[idx-1]];
        
        for(int i=idx-2;i>=0;i--)
        {
            hash[v[i]]=v[i]+hash[v[i+1]];
            // cout<<hash[v[i]]<<" ";
        }
        
        // for(int j=0;j<=10000;j++)
        // {
        //     if(hash[j]!=0) cout<<hash[j]<<" "; 
        // }
        
        shineSolve(root);
        
        return root;
     }
private:
    void inorder(TreeNode* root,vector<int>& v)
    {
        if(root==NULL) return;
        
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    
    void shineSolve(TreeNode* root)
    {
        if(root==NULL) return;
        
        shineSolve(root->left);
        //v.push_back(root->val);
        root->val= hash[root->val];
        
        shineSolve(root->right);
    }
    
    

};