class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());


        set<vector<int>> ans;
       

        for(int i=0 ;i<=nums.size()-3;i++)
        {
            int  j =i+1;
            int k = nums.size() - 1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {

                    ans.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
               else if(nums[i]+nums[j]+nums[k]<0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }

        vector<vector<int>> final_ans;

        for(auto t:ans)
        {
            final_ans.push_back(t);
        }

        return final_ans;


        
        
    }
};