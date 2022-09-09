class Solution {
public:
    int fib(int n) {
        
        map<int,int> mpp;
        
        
       // for(auto x:mpp) cout<<x.first<<" "<<x.second<<"\n";
        return ans(n,mpp);
    }
    
private:
    int ans(int n,map<int,int>& mpp)
    {
        if(n==1) return 1;
        if(n==0) return 0;
        
        int currentKey=n;
        
         if(mpp.find(currentKey)!=mpp.end()) {  return mpp[currentKey];}
        
        int res1=ans(n-1,mpp);
        int res2=ans(n-2,mpp);
        
       
        mpp.insert(make_pair(currentKey,(res1+res2)));
        
        
        return res1+res2;
    }
};