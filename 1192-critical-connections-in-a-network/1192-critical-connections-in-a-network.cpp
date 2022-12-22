class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> graph(n);
        for(auto x : connections)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        
        
        // for(auto x: graph)
        // {
        //     for( auto y: x)
        //     {
        //         cout<<y<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        vector<int> dT(n,-1);
        vector<int> lT(n,-1);
        int time=0;
        
        vector<vector<int>> res;
        tarjans(0,time,-1,graph,res,dT,lT);
        
        return res;
    }

    void tarjans(int currVrtx,int& time,int currParent,vector<vector<int>>& graph,vector<vector<int>>& res,vector<int>& dT,vector<int>& lT)
    {
        dT[currVrtx]=time;
        lT[currVrtx]=time;
        time++;
        
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