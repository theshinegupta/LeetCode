class Solution {
public:
    int hammingDistance(int x, int y) {
        int count=0;
        int temp=x^y;
        while(temp)
        {
            if(temp&1) count++;
            
            temp=temp>>1;
        }
        
        return count;
        
    }
};