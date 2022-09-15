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
    
    vector<double> averageOfLevels(TreeNode* root) { 
        vector<double> v;
        
        levelOrder(root,v);
        
        return v;
        
        
    }
private:
    
    void levelOrder(TreeNode* root,vector<double>& v)
    {
        queue<TreeNode*> q;
        
        q.push(root);
        q.push(NULL);
        
        double currLvlsum=0;
        double count=0;
        while(q.size())
        {
            TreeNode* temp=q.front(); q.pop();
            
            if(temp!=NULL)
            {
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
                currLvlsum+=temp->val;
                count+=1;
            }
            else
            {
                
                double res=(currLvlsum/count);
                v.push_back(res);
                if(q.size()==0) break;
                
                currLvlsum=0;
                count=0;
                q.push(NULL);
            }
        }
    
    }
};