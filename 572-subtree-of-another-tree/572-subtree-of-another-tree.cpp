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
    bool flag=false;
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        search(root,subRoot);
        
        return flag;
    }
    
private:
    
    void search(TreeNode* root,TreeNode* subRoot)
    {
        if(root==NULL) return;
        if(root->val ==subRoot->val)
        {
            bool tempFlag=check(root,subRoot);
            
            if(flag==false && tempFlag==true) {flag=true;}
            
            
        }
        
        search(root->left,subRoot);
        search(root->right,subRoot);
    }
    
    bool check(TreeNode* root,TreeNode* subRoot)
    {
        if(root==NULL && subRoot==NULL) return true;
        
        if(root==NULL && subRoot!=NULL) return false;
        
        if(root!=NULL && subRoot==NULL) return false;
        
        return ( (root->val==subRoot->val) && check(root->left,subRoot->left) && check(root->right,subRoot->right));
    }

};