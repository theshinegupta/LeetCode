class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        bool flag=true;
        int v=graph.size();
        vector<int> colors(v,-1);
        
        for(int i=0;i<graph.size();i++)
        {
            if(colors[i]==-1)
            {
                flag=paint(i,0,flag,colors,graph);
                if(!flag)
                    return false;
            }
        }
        
        return flag;
    }
bool paint(int currVrtx,int parentColor,bool &flag,vector<int>& colors,vector<vector<int>>& graph)
{
    if(colors[currVrtx]!=-1 && colors[currVrtx]!=parentColor)
     return false;
    
    
    if(colors[currVrtx]==-1)
    {
        colors[currVrtx]=parentColor;
        
        for(int i=0;i<graph[currVrtx].size();i++)
        {
            if(parentColor==0)
               flag=paint(graph[currVrtx][i],1,flag,colors,graph);
            else
               flag=paint(graph[currVrtx][i],0,flag,colors,graph);
            
            if(!flag)
                return false;
        }
    }
    
    return true;
    

}
};