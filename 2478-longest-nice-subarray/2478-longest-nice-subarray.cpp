class Solution {
public:
  bool solve(vector<int>& nums , int l , int r)
  {
    for(int i = l ;i<r ;i++ )
    {
        for(int j=i+1 ; j<=r ; j++)
        {
            if(!(nums[i] & nums[j] )) 
            {
                continue;
            }
            else 
            return 0;
        }
    }
    return 1;
  }
    int longestNiceSubarray(vector<int>& nums) {
       int i =0 , j=1;
       if(nums.size()==1 || nums.size()==0)
       {
        return nums.size();
       }
       int len =1;
       while(j<nums.size())
       {
        if(solve(nums , i ,j))
        {
            // cout<<nums[i]<<" "<<nums[j];
            // cout<<endl;
           
            j++;
            // len=max(len , j-i+1);
            // continue ;
        }
        else
        {
            len=max(len , j-i);
            i++;
            j=i+1;

        }
       }
       len=max(len , j-i);
       return len;
    }
};