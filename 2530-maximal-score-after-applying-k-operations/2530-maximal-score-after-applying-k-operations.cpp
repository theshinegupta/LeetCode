class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        long long score=0;
        
        priority_queue<int> q;
        
        for(auto x: nums)
        {
            q.push(x);
        }
        
        for(int i=0;i<k;i++)
        {
            long long temp=q.top();
            q.pop();
            
            score+=temp;
            
            if(temp%3==0)
                temp=temp/3;
            else
                temp=temp/3+1;
            
            q.push(temp);
        }
        
        
        
        return score;
        
    }
};