class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater=0;
        int p=0;
        int q=height.size()-1;
        
        while(p<q)
        {
            int minTower=min(height[p],height[q]);
            
            int temp=(q-p)*minTower;
            
           // cout<<temp<<" ";
            maxWater=max(maxWater,temp);
           
            if(height[p]<height[q]) {p++;}
            else {q--;}
        }
        
        return maxWater;
    }
};