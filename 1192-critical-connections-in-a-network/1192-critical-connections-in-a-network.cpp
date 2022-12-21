class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> graph(n);
        for(int i=0;i<connections.size();i++)
        {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        
        
//         for(int i=0;i<graph[1].size();i++)
//         {
//             cout<<graph[1][i]<<" ";
//         }
            
        
//          cout<<"\n";
        
        vector<int> dT(n,-1);
        vector<int> lT(n,-1);
        int time[1]={0};
        
        vector<vector<int>> res;
        
        tarjans(0,time,-1,graph,res,dT,lT);
        
        
        // cout<<dT[1]<<" "<<lT[1];
        
        return res;
        
 }
    void tarjans(int currVrtx,int time[],int currParent,vector<vector<int>>& graph,vector<vector<int>>& res,vector<int>& dT,vector<int>& lT)
    {
        dT[currVrtx]=time[0];
        lT[currVrtx]=time[0];
        time[0]+=1;
        
        for(auto currNeighbour : graph[currVrtx])
        {
            
            
            if(currNeighbour==currParent)
                continue;
            
            if(dT[currNeighbour]!=-1)
            {
                lT[currVrtx]=min(lT[currVrtx],dT[currNeighbour]);
                continue;
            }
            
            tarjans(currNeighbour,time,currVrtx,graph,res,dT,lT);
            
            lT[currVrtx]=min(lT[currVrtx],lT[currNeighbour]);
            
            
            if(dT[currVrtx]<lT[currNeighbour])
            {
                vector<int> temp;
                temp.push_back(currVrtx);
                temp.push_back(currNeighbour);
                res.push_back(temp);
            }
            
            
        }
        
        return;
    }
};