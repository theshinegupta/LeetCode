class Solution {
public:
    int hammingDistance(int x, int y) {
        int count=0;
        int temp=x^y;
        bitset<32> ans(temp);
       
        return ans.count();
        
    }
};