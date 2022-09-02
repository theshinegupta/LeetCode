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
    int postOrder;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         postOrder=postorder.size()-1;
        int is=0;
        int ie=postOrder;
        
        return cTree(inorder,postorder,is,postOrder);
    }
    
    TreeNode* cTree(vector<int> in,vector<int> post,int is,int ie)
    {
        if(is>ie ) return NULL;
        
        TreeNode* root=new TreeNode(post[postOrder--]);
        
        int inIndex;
        
        for(int i=is;i<=ie;i++)
        { 
            if(in[i]==root->val) 
            {inIndex=i; break;}
        }
        
       // cout<<inIndex<<" ";
        root->right=cTree(in,post,inIndex+1,ie);
        root->left=cTree(in,post,is,inIndex-1);
        
        
        return root;
    
    
    
    }
};