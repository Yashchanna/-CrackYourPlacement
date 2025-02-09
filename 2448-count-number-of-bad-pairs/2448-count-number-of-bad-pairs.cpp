static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        // int cnt = 0;

        // for(int i=0;i<nums.size()-1;i++)
        // {
        //     for(int j=i+1;j<nums.size();j++)
        //     {
        //         int diff= nums[j]-nums[i];

        //         if(j-i!=diff) cnt++;
        //     }
        // }
        
        // return cnt;
      unordered_map<int,long long> mp;
      for(int i=0 ;i<nums.size();i++)
      {
        mp[nums[i]-i]++;
      }
      long long good_pairs =0;
      for(auto it: mp)
      {
        if(it.second>1)
        {
            long long pairs = (it.second * (it.second-1)) >> 1;
            good_pairs += pairs;
        }
      }

      long long total = (nums.size() * (nums.size() -1)) >> 1;
      return total -good_pairs;
    }
};