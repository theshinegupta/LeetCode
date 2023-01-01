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
    int maxHeight=0;
    int diameterOfBinaryTree(TreeNode* root) {
        
        preOrder(root);
        return maxHeight-1;
    }
    
void preOrder(TreeNode* root)
{
    if(root==NULL)
        return;
    
    int tempHeight=0;
    tempHeight=findDia(root);
    
    maxHeight=max(tempHeight,maxHeight);
    
    if(root->left)
        preOrder(root->left);
    
    if(root->right)
        preOrder(root->right);
}
    
int findDia(TreeNode* root)
{
    int leftHeight=0;
    
    leftHeight=findHeight(root->left);
    
    int rightHeight=0;
    
    rightHeight=findHeight(root->right);
    
    return (leftHeight+rightHeight+1);
}
    
int findHeight(TreeNode* root)
{
    if(root==NULL)
         return 0;
    
    return max(findHeight(root->left),findHeight(root->right))+1;
}
};