class Solution {
public:
    int n;
    vector<int> segmentTree;
    vector<int> xorQueries(vector<int>& nums, vector<vector<int>>& queries) {
         n=nums.size();
         vector<int> st(4*n,0);
         segmentTree=st;
         
        constructST(nums,0,n-1,0);
        vector<int> res;
        
        for(auto x: queries)
        {
            int temp=findXor(0,n-1,x[0],x[1],0);
            res.push_back(temp);
            
            
        }
        return res;
        
    }
    
int findXor(int start,int end,int left,int right,int currIdx)
{
    if(start>end)
     return 0;
      
    if(start>right || end< left)
     return 0;
     
    
     
    if(start>=left && end<=right)
    return segmentTree[currIdx];
    
    int mid=start+(end-start)/2;
    
    int leftVal=findXor(start,mid,left,right,2*currIdx+1);
    int rightVal=findXor(mid+1,end,left,right,2*currIdx+2);
    
    return leftVal^rightVal;
}
    
void constructST(vector<int>& nums,int start,int end,int currIdx)
{
    if(start==end)
     {
         segmentTree[currIdx]=nums[start];
         return;
     }
     
     int mid=start+(end-start)/2;
     
     constructST(nums,start,mid,2*currIdx+1);
     constructST(nums,mid+1,end,2*currIdx+2);
     
     segmentTree[currIdx]=segmentTree[2*currIdx+1]^segmentTree[2*currIdx+2];
     
     return;
}
};