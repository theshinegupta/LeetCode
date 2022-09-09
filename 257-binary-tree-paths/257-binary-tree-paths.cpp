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
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> v;
    
        if(root->left==NULL && root->right==NULL) { string str=to_string(root->val); v.push_back(str); return v;}
        
        string str1="";
        
        path(root,str1,v);
        
        return v;
                                                  
         
    }
    
private:
       void path(TreeNode* root,string str,vector<string>& v)
       {
           if(root->left==NULL && root->right==NULL) 
           {
               str+=to_string(root->val);
               v.push_back(str);
               return;
           }
           
           string s=to_string(root->val)+ "->";
           
           str+=s;
           if(root->left!=NULL) path(root->left,str,v);
           if(root->right!=NULL) path(root->right,str,v);
           
           return;
       }
    
};