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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> res;
       
       if(root==NULL)
        return res;
        
       stack<pair< TreeNode*,pair<bool,bool> > > s;
       s.push({root,{true,true}});
       
       while(!s.empty())
       {
           TreeNode* currNode=s.top().first;
           bool leftFlag=s.top().second.first;
           bool rightFlag=s.top().second.second;
           
           if(currNode->left!=NULL && leftFlag)
           {
               s.top().second.first=false;
               s.push({currNode->left,{true,true}});
               continue;
           }
           
            res.push_back(currNode->val);
          
           
           if(currNode->right!=NULL && rightFlag)
           {
               s.top().second.second=false;
                s.pop();
               s.push({currNode->right,{true,true}});
               continue;
               
           }
           s.pop();
          
       }
       
       return res;
      
    }
    
    
// void inorder(TreeNode* root,vector<int>& res)
// {
//     if(root==NULL)
//         return;
    
//     inorder(root->left,res);
//     res.push_back(root->val);
//     inorder(root->right,res);
    
//     return;
// }
};