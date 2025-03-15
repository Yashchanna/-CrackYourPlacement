class Solution {
public:
    int search(vector<int>& nums, int target) {

        int i=0;
        int j=nums.size()-1;
        int mid=(i+j)/2;

        while(i<=j)
        {

              mid=(i+j)/2;
          
            if(nums[mid]==target)
            {
                return mid;
            }

            if(nums[i]<=nums[mid])
            {
                if(target>=nums[i] && target<=nums[mid])
                {
                    j=mid-1;
                }
                else
                {
                    i=mid+1;
                }
            }
            else
            {
                if(target<=nums[j] && target>=nums[mid])
                {
                    i=mid+1;
                }
                else
                {
                    j=mid-1;
                }
            }

            
        }

        return -1;
        
    }
};



