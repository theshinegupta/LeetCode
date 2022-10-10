class Solution {
public:
    bool canArrange(vector<int>& ar, int k) {
      int arr[k];
        // memset(arr,0,k);
        
        for(int i=0;i<k;i++)
        {
            arr[i]=0;
        }
        for(int x: ar)
        {
            int currRemainder=((x%k)+k)%k;
            arr[currRemainder]++;
        }
        
        for(int i=0;i<=k/2;i++)
        {
            if(i==0 && arr[0]%2!=0)
                return false;
            else
            {
                if(i!=0)
                {
                int y=k-i;
                if(arr[i]!=arr[y])
                    return false;
                }
            }
        }
        
        return true;
        
    }
};