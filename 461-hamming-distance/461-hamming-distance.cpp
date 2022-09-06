class Solution {
public:
    int hammingDistance(int x, int y) {
       
       
        bitset<32> ans(x^y);
        return ans.count();
        
    }
};