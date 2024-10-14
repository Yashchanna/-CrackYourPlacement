class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(),nums.end());
      
        long long score=0;

        while(k--)
        {
            int maxi = pq.top();
            pq.pop();

            score+=maxi;

            maxi= ceil(maxi/3.0);

            pq.push(maxi);
        }
        return score;
        
    }
};






// time limit exceeded
// class Solution {
// public:
//     long long maxKelements(vector<int>& nums, int k) {

//         int score=0;
//         long long ans=0;

//         for(int i=0 ;i<k ; i++)
//         {
//             double maxi = *max_element(nums.begin() , nums.end());
//             cout<<maxi<<" ";
//             ans+=maxi;

//             for(int j=0 ;j<nums.size();j++)
//             {
//                 if(nums[j]==maxi)
//                 {
//                     nums[j]=ceil(maxi/3);
//                     cout<<"replace"<<ceil(maxi/3)<<endl;
//                     break;
//                 }
//             }
//         }


//         return ans;



        
//     }
// };