class Solution {
public:
    int solve(vector<int>& nums, int m, int k , int mid)
    {
        int number_of_boque=0;
        
        int cnt=0;
        for(int i =0 ;i<nums.size();i++)
        {
            if(nums[i]<=mid)
            {
                cnt++;
            }
            else
            {
                cnt=0;
            }

            if(cnt==k)
            {
                number_of_boque++;
                cnt=0;
            }
        }
        return number_of_boque;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        // if(bloomDay.size()/k<m) return -1;

        int l=0 , r=0;
        for(auto a : bloomDay )
        {
            r=max(r,a);
        }
        int ans = -1;

        while(l<=r)
        {
            int mid=l+(r-l)/2;

            if(solve(bloomDay , m , k , mid)>=m)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
       


        return ans;

        
    }
};