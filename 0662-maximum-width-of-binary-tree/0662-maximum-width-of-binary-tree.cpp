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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=INT_MIN;
        
        
        if(root==NULL)
            return 0;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(!q.empty())
        {
            int currLvlSize=q.size();
            int currLvlMin=q.front().second;
            
            int firstEle=0,lastEle=0;
            
            for(int i=0;i<currLvlSize;i++)
            {
                TreeNode* temp=q.front().first;
                
                if(i==0) firstEle=q.front().second;
                
                if(i==currLvlSize-1) lastEle=q.front().second;
                
                long long idx=q.front().second-currLvlMin;
                    
                if(temp->left)
                    q.push({temp->left,2*(idx)+1});
                if(temp->right)
                    q.push({temp->right,2*(idx)+2});
                
                q.pop();
                    
            }
            
            ans=max(ans,lastEle-firstEle+1);
            
        }
        
        return ans;
        
    }
};