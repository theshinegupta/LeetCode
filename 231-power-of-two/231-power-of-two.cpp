class Solution {
public:
    bool isPowerOfTwo(int n) {
         if(n==0) return false;
        
          if(n<0) {return false;}
         else
         {
             return (!(n&(n-1)))?1:0;
         }
    }
};