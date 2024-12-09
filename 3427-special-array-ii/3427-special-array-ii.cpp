// class Solution {
// public:
//     vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {


//         vector <bool> bl;

//         for(int i=0 ;i<queries.size();i++)
//         {
//             int start= queries[i][0];
//             int end= queries[i][1];

    
//             int flag =0;
//             for(int j=start ; j<end ;j++)
//             {
//                 if(nums[j]%2==0)
//                 {
                    
//                     if(nums[j+1]%2==0)
//                     {
//                       flag =1;
//                        break;
//                     } 
//                     else flag =0;
//                 }
//                 else
//                 {
                    
//                    if(nums[j+1]%2==0) flag=0;
//                    else
//                    {
//                     flag =1;
//                     break;
//                    } 
//                 }
//             }

//             if(flag)
//             {
//                 bl.push_back(false);
                
//             }
//             else
//             {
//                 bl.push_back(1);
//             }
//         }

//         return bl;
        
//     }
// };


class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();
        set<int> store;
        for(int i = 1; i < n; i++)
            if((nums[i] % 2) == nums[i - 1] % 2)
                store.insert(i);

        vector<bool> ans;
        for(auto querie : queries)
        {
            int left = querie[0], right = querie[1];

            auto it = store.upper_bound(left);
            ans.push_back((*it <= right and it != store.end()) ? 0 : 1);
        }

        return ans;
    }
};