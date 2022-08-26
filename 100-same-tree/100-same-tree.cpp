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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
         q1.push(p);
         
        queue<TreeNode*> q2;
         q2.push(q);
        
          TreeNode* temp1, *temp2;
        
        while(q1.size()!=0 && q2.size()!=0)
        {
            temp1=q1.front();
            temp2=q2.front();
           
            
            if((temp1==NULL && temp2!=NULL) || (temp2==NULL && temp1!=NULL) ) return false;
            
            if(temp1==NULL && temp2==NULL)  {q1.pop();q2.pop(); continue;}
            
            if(temp1->val!=temp2->val) return false;
            else
            {
                if(temp1->left!=NULL) q1.push(temp1->left); 
                 else q1.push(NULL);
                if(temp1->right!=NULL) q1.push(temp1->right);
                  else q1.push(NULL);
                
                if(temp2->left!=NULL) q2.push(temp2->left);
                   else q2.push(NULL);
                if(temp2->right!=NULL) q2.push(temp2->right);
                   else q2.push(NULL);
            }
            
            q1.pop();
            q2.pop();
        }
        
        return true;
        
        
    }
};