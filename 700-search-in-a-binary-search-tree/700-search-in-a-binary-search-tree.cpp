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
    TreeNode* temp;
    TreeNode* searchBST(TreeNode* root, int val) {
        
       // if(root->left==NULL && root->right==NULL && )
        temp=NULL;
        search(root,val);
        
        return temp;
        
    }
private:
    void search(TreeNode* root,int val)
    {
        
        if(val<root->val && root->left!=NULL)   {search(root->left,val); }
        else 
        {
            if(val>root->val && root->right!=NULL) {search(root->right,val);}
            else
            {
                if(val==root->val) {temp=root; return;}
            }
            
            
        }
             
    }
};