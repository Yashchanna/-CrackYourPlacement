class Solution {
public:
    bool canJump(vector<int>& nums) {

        int max_index=0;

        for(int i=0 ; i<nums.size();i++)
        {
            if(i>max_index) return false;

            max_index = max(max_index , i+nums[i]);

            if(max_index==nums.size()-1) return true;
        }
        
        return true ;
    }
};