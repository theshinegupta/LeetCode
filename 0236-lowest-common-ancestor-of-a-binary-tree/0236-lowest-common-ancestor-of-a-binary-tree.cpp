/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int pVal=0;
    int qVal=0;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* s) {
      
         pVal=p->val;
         qVal=s->val;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int lSide=0;
            int temp=q.front()->val;
            TreeNode* currNode=q.front();
            
            if(temp==pVal || temp==qVal)
                lSide+=1;
            
            if(currNode->left!=NULL)
                preOrder(currNode->left,lSide);
            
            if(lSide==2)
            {
                if(temp==pVal || temp==qVal)
                      return currNode;
                
                
                q.push(currNode->left);
                q.pop();
                continue;
            }
            
            if(lSide==1)
            {
                return currNode;
                break;
            }
                
            
            
            q.push(currNode->right);
            q.pop();
            
        }
        
        return root;
    }
    
void preOrder(TreeNode* root,int& lSide)
{
    if(root==NULL)
        return;
    
    if(root->val==pVal || root->val==qVal)
        lSide++;
    
    preOrder(root->left,lSide);
    preOrder(root->right,lSide);
}
};
