class Solution {
public:
    int findLHS(vector<int>& nums) {
        // unordered_map<int,int> mp;

        // for(auto a:nums) mp[a]++;
        // int pre_num=-1;
        // int pre_fre =0;
        // int maxi=0;
        // for(auto a:mp)
        // {
        //   if(abs(a.first-pre_num)==1)
        //   {
        //     maxi=max(maxi , a.second+ pre_fre);
        //   }

        //   pre_num=a.first;
        //   pre_fre=a.second;
        // }

        // return maxi ;

       unordered_map<int, int> frequencyMap;

       
        for (int num : nums) {
            frequencyMap[num]++;
        }
        int maxLength = 0;
        
        for (auto& [num, count] : frequencyMap) {
            if (frequencyMap.count(num + 1)) {
                int currentLength = count + frequencyMap[num + 1];
                maxLength = max(maxLength, currentLength);
            }
        }

        return maxLength;

        
    }
};