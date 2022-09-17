class Solution {
public:
    int tribonacci(int n) {
        
        map<int,int> mp;
        return tribo(n,mp);
        
    }
private:
    int tribo(int n,map<int,int>& mp)
    {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        
        int currKey=n;
        
        if(mp.find(currKey)!=mp.end()) return mp[currKey];
        
        int res=tribo(n-1,mp)+tribo(n-2,mp)+tribo(n-3,mp);
        
        mp.insert({currKey,res});
       
        return mp[currKey];
    }
};