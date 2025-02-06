class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
 
    unordered_map<int , int> st;
    int cnt=0;

    for(int i=0;i<nums.size()-1;i++)
    {
        for(int j=i+1;j<nums.size();j++)
        {
           int product = nums[i]*nums[j];
           
           st[product]++;
          
        }
    }

    for(auto a:st )
    {
        // cout<<a.first<<"->"<<a.second<<endl;
        cnt+=((a.second)*(a.second-1)/2);
        
    }
    

    return cnt*8;
        

        
    }
};