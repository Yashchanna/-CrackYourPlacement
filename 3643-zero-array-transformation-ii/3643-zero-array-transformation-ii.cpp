class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n= nums.size();
        int cnt= count(nums.begin(),nums.end(),0);
        if(cnt==n) return 0;
        int l=0 , r=queries.size()-1 ,ans=-1;
        int mid = (l+r)/2;
       

        while(l<=r)
        {
            vector<int> diff(n+1,0);
            mid=(l+r)/2;

            for(int i =0;i<=mid;i++)
            {
                diff[queries[i][0]]+=queries[i][2];
                diff[queries[i][1]+1]-=queries[i][2];
            }
            
            for (int i = 1; i < nums.size(); i++) {
                diff[i] += diff[i - 1];
            }
            
            bool canZero = true;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > diff[i]) {
                    canZero = false;
                    break;
                }
            }
            
            if (canZero) {
                ans = mid + 1;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }    
        return ans; 
    }
};