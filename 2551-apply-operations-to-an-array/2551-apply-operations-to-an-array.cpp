class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        
        for(int i=0 ;i<nums.size();i++)
        {
            if( i<nums.size()-1 && nums[i] == nums[i + 1])
            {
                nums[i]*=2;
                nums[i+1]=0;
            }

        }

        int i=0, j=0;

        while(j<nums.size())
        {
            if(nums[j]!=0)
            {
                nums[i++]=nums[j];
            }
            j++;
        }
       
        while(i<nums.size())
        {
            nums[i]=0;
            i++;
        }

        return nums;
        
        
    }
};