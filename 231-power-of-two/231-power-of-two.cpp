class Solution {
public:
    bool isPowerOfTwo(int n) {
       // cout<<ceil(log2(16))<<" "<<floor(log2(16));
        if(n==0) return false;
        else  return (ceil(log2(n))==floor(log2(n)))?1:0;
    }
};