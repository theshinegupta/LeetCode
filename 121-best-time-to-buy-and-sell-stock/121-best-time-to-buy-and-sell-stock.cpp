class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
       int n=prices.size(); 
       int maxProfit=INT_MIN;
        vector<int> maxVal(n);
        
        maxVal[n-1]=prices[n-1];
        
        maxProfit=INT_MIN;
      
        for(int i=n-2;i>=0;i--)
        {
            if(prices[i]>maxVal[i+1]) {maxVal[i]=prices[i];}
            else{ maxVal[i]=maxVal[i+1];}
            
            if((maxVal[i]-prices[i])>maxProfit) {maxProfit=(maxVal[i]-prices[i]);}
        }
        
        if(maxProfit<0) { return 0;}
        else {return maxProfit;}
          
        
    }
};