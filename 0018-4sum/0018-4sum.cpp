class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        set<vector<int>> s;
        vector<vector<int>> output;
        long target = tar;

        sort(nums.begin(), nums.end());

        for (int y = 0; y < nums.size(); ++y) {
            for (int i = y + 1; i < nums.size(); ++i) {
                int j = i + 1;
                int k = nums.size() - 1;
                
                while (j < k) {
                long long int sum = static_cast<long long int>(nums[i]) + nums[j] + nums[k] + nums[y];

                    
                    if (sum == target) {
                        s.insert({nums[y], nums[i], nums[j], nums[k]});
                        ++j;
                        --k;
                    } else if (sum < target) {
                        ++j;
                    } else {
                        --k;
                    }
                }
            }
        }

        for (auto quadruplet : s)
            output.push_back(quadruplet);
        
        return output;
    }
};
