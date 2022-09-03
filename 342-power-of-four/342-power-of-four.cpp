class Solution {
public:
    bool isPowerOfFour(int n) {
        int count=0;
        
        if(n==1) {return true;}
        if(n<=0 ||  n%2!=0) {return false;}
        
        while(n>1 && n%2==0)
        {
            n=n/2;
            count++;
        }
       // cout<<count<<" ";
        return (!(n&(n-1)) && (count%2==0))?1:0;
    }
};