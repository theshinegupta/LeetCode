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
    int preOrder=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int is=0;
        int ie=preorder.size()-1;
        return cTree(preorder,inorder,is,ie);
        
    }
    
     TreeNode* cTree(vector<int> pre,vector<int> in,int is,int ie)
    {
        if(is>ie ) return NULL;
        
        TreeNode* root=new TreeNode(pre[preOrder++]);
        
        int inIndex;
        
        for(int i=is;i<=ie;i++)
        { 
            if(in[i]==root->val) 
            {inIndex=i; break;}
        }
        
       // cout<<inIndex<<" ";
          root->left=cTree(pre,in,is,inIndex-1);
        root->right=cTree(pre,in,inIndex+1,ie);
       
        
        
        return root;
    
    
    
    }
};