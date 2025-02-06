class Solution {
public:
    int maxProduct(vector<int>& nums) {

    
    int n= nums.size();
    if(n==1) return nums[0];
     int  maxi=INT_MIN;

    for(int i =0;i<n ; i++)
    {
        int temp=nums[i];
        maxi = max(maxi , temp);
        
        for(int j = i+1 ; j<n;j++)
        {
        
           temp=temp * nums[j];
          
          maxi = max(maxi , temp);
        //   cout<<"i is"<<i<<" "<<"j is "<<j<<"  "<<"maxi is "<<maxi<<endl;
        }
    }

    // int maximum = *max_element(nums.begin(),nums.end());

    // if(maxi<maximum) return maximum;
    return maxi ;
        
    }
};