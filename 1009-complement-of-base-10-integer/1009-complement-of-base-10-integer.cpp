class Solution {
public:
    int bitwiseComplement(int n) {
          int num=n;
          long long num2=0;
          long long power2=1;
          string str;
          int i=0;
        
        if(n==0) return 1;
    while(num)
       {
           if(num&1) str+='0';
               else str+='1';
           num=num>>1;
           
       }
        //cout<<str<<" ";
        for(auto x: str)
        {
            if(x=='1') num2+=power2*1;
            else num2=num2+0;
            
            power2=power2*2;
        }
        
        return num2;
        
        
    }
};