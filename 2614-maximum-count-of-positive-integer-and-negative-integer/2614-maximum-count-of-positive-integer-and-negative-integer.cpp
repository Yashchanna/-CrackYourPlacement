class Solution {
public:
    int maximumCount(vector<int>& nums) {
       int p =0 ,n=0,i =0 , s=nums.size();

       while(i<s)
       {
        if(nums[i]>0) p++;
        else if(nums[i]<0) n++;

   

        i++;
       }
        
        return (n>=p)?n:p;
    }
};