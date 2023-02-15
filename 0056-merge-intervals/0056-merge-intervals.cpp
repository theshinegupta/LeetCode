class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int mergeCount=0;
        vector<vector<int>> merges;
        
        sort(intervals.begin(),intervals.end());
        
        for(int i=0;i<intervals.size()-1;i++)
        {
            if(intervals[i][1]>=intervals[i+1][0])
            {
                if(intervals[i][1]>=intervals[i+1][1])
                {
                    //complete overlap
                    intervals[i+1][0]=intervals[i][0];
                    intervals[i+1][1]=intervals[i][1];
                    
                   
                    
                }
                else
                {
                     intervals[i+1][0]=intervals[i][0];
                    
                    
                }
                    intervals[i][0]=-1;
                    
            }
           
        }
        
        for(int i=0;i<intervals.size();i++)
        {
            if(intervals[i][0]!=-1)
                merges.push_back(intervals[i]);
        }
        
        return merges;
    }
};