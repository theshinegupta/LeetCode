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
    int finalAns=0;
    int averageOfSubtree(TreeNode* root) {
        
        shineSolve(root);
        return finalAns;
    }
private:
    
    void shineSolve(TreeNode* root)
    {
        if(root==NULL) return;
        
        if(root->left==NULL && root->right==NULL) {finalAns++; return;}
    
        
        int Sum=findSum(root);
        int nodes=countNodes(root);
        
        if((Sum/nodes)==root->val) finalAns++;
        
        shineSolve(root->left);
        shineSolve(root->right);
    }
       
    
    int findSum(TreeNode* root)
        {
            if(root==NULL) return 0;
            
           return (root->val)+findSum(root->left)+findSum(root->right);
           
        }
    
    int countNodes(TreeNode* root)
        {
            if(root==NULL) return 0;
            
           return (1+countNodes(root->left)+countNodes(root->right));
           
        }
};