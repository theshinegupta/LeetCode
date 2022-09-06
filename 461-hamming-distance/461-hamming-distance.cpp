class Solution {
public:
    int hammingDistance(int x, int y) {
        int count=0;
       while(x || y)
       {
           if(x%2!=y%2) count++;
           
           x=x>>1;
           y=y>>1;
           
       }
        
        return count;
        
    }
};