class Solution {
public:
    int trap(vector<int>& height) {
        
        int size=height.size();
        int left[size];
        int right[size];
        int count=0;
        
        
        left[0]=height[0];
        right[0]=height[size-1];
        int leftMax=height[0];
        int rightMax=height[size-1];
        
        for(int p=1;p<size-1;p++)
        {
            if(height[p]>leftMax) leftMax=height[p];
            
            left[p]=leftMax;
        }
        for(int p=size-1;p>0;p--)
        {
            if(height[p]>rightMax) rightMax=height[p];
            
            right[p]=rightMax;
        }
        
        for(int p=1;p<size-1;p++)
        {
            count+=min(left[p],right[p])-height[p];
        }
        
        return count;
        
    }
};