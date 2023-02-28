class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        vector<int> maxArray(n);
        
        stack<pair<int,int>> sR,sL;
        
        
        for(int i=n-1;i>=0;i--)
        {
            int count=0;
            
            while(!sR.empty() && sR.top().first>=heights[i])
            {
                count+=1+sR.top().second;
                sR.pop();
            }
            
            maxArray[i]=count;
            sR.push({heights[i],count});
        }
        
        for(int i=0;i<n;i++)
        {
            int count=0;
            
            while(!sL.empty() && sL.top().first>=heights[i])
            {
                count+=1+sL.top().second;
                sL.pop();
            }
            
            maxArray[i]+=count;
            sL.push({heights[i],count});
        }
        
        
        int res=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            int temp=(maxArray[i])*heights[i]+heights[i];
            res=max(temp,res);
        }
        
        return res;
        
    }
};