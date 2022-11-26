class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         bool isVisited[numCourses];
         memset(isVisited,false,sizeof(isVisited));
        
         int inDegree[numCourses];
         memset(inDegree,0,sizeof(inDegree));
        
         vector<int> adj[numCourses];
        
         for(int i=0;i<prerequisites.size();i++)
         {
             int a=prerequisites[i][0];
             int b=prerequisites[i][1];
             
             adj[a].push_back(b);
             inDegree[b]++;
         }
        
         queue<int> q;
         vector<int> ans;
          for(int i=0;i<numCourses;i++)
          {
              if(inDegree[i]==0)
                  q.push(i);
          }
        
          while(!q.empty())
          {
              int currVrtx=q.front();
              q.pop();
              
              
              if(!isVisited[currVrtx])
              {
                  ans.push_back(currVrtx);
                  isVisited[currVrtx]=true;
                  
                  for(int i=0;i<adj[currVrtx].size();i++)
                  {
                      inDegree[adj[currVrtx][i]]-=1;
                      
                      if(inDegree[adj[currVrtx][i]]==0)
                      {
                          q.push(adj[currVrtx][i]);
                      }
                  }
                  
                  
                  
              }
              
         }
        
              vector<int> nULL;
              for(int i=0;i<numCourses;i++)
              {
                  if(!isVisited[i])
                      return nULL;
              }
              
              reverse(ans.begin(),ans.end());
              return ans;
              
        
    }
};