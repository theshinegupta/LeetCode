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
        
        int sum=0;
        int count=0;
        
        findAvg(root,&sum,&count);
        
        if((sum/count)==root->val) finalAns++;
        
        shineSolve(root->left);
        shineSolve(root->right);
    }
       
    
//     int findSum(TreeNode* root)
//         {
//             if(root==NULL) return 0;
            
//            return (root->val)+findSum(root->left)+findSum(root->right);
           
//         }
    
    int countNodes(TreeNode* root)
        {
            if(root==NULL) return 0;
            
           return (1+countNodes(root->left)+countNodes(root->right));
           
        }
    
    void findAvg(TreeNode* root,int *sum,int* count)
        {
            if(root==NULL)
            {
               return;
            }
            
          *sum+=root->val;
          *count+=1;
         
        findAvg(root->left,sum,count);
        findAvg(root->right,sum,count);
         
        
           
        }
};