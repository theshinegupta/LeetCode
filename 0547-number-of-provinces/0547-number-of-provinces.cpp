class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0;
        
        bool isVisited[isConnected.size()];
        
        memset(isVisited,false,sizeof(isVisited));
        
        
        for(int i=0;i<isConnected.size();i++)
        {
            
            if(!isVisited[i])
            {
                bfs(i,isConnected,isVisited);
                ans++;
            }
        }
        
        
        return ans;
        
    }
    
void dfs(int currVrtx,vector<vector<int>>& isConnected,bool isVisited[])
{
    if(isVisited[currVrtx])
    {return;}
    
    
    isVisited[currVrtx]=true;
    
    for(int i=0;i<isConnected.size();i++)
    {
        if(isConnected[currVrtx][i]==1)
        {
            dfs(i,isConnected,isVisited);
        }
    }
    
    return;
}
    

void bfs(int currVrtx,vector<vector<int>>& isConnected,bool isVisited[])
{
    if(isVisited[currVrtx])
        return;
    
    
    queue<int> q;
    q.push(currVrtx);
    
    while(!q.empty())
    {
        int temp=q.front();
        isVisited[temp]=true;
        q.pop();
        
        for(int i=0;i<isConnected.size();i++) //traversing Column wise rowNum=colNum isliye isConnected.size() krliya tha
        {
            if(isConnected[temp][i]==1)
            {
               if(!isVisited[i])
               {
                   q.push(i);
                    
               }
               // isVisited[i]=true;
               
                   
            }
        }
    }
    
    return;
}
};
