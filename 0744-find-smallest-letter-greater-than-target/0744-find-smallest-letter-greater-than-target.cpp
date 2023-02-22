class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int start=0;
        int end=letters.size()-1;
        
        int mid=0;
        while(start<=end)
        {
             mid=start+(end-start)/2;
            
            if(letters[mid]==target)
            {
                start=mid+1;
                continue;
            }
            if(letters[mid]-target>0)
            {
                end=mid-1;
            }
            else
                
            {
                start=mid+1;
            }
        }
        
        if(end<0 || start>=letters.size())
        {
            return letters[0];
        }
        
        
        return letters[start];
        
        
            
    }
};