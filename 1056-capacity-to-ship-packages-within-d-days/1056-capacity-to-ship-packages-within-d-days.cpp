class Solution {
public:
    int check(vector<int>& weights, int days, int mid)
    {
        int curr=0;
        int cnt=0;
        for(int i=0 ; i<weights.size();i++)
        {
            if(weights[i]>mid) return days+1;
            if(curr+weights[i]<=mid)
            {
               curr+=weights[i]; 
            }
            else
            {
                cnt++;
                curr=weights[i];
            }
            
           
        }
         return cnt+1;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int sum = 0;
        int mini=501;
        for(int i=0 ;i<weights.size();i++)
        {
            sum+=weights[i];
            mini=min(mini ,weights[i]);

        }

        int i=mini;
        int j =sum;

        while(i<j)
        {
            int mid=i+(j-i)/2;
            int cnt=check(weights , days , mid);
            
            if(cnt<=days)
            {
                j=mid;
            }
            else
            {
               i=mid+1;
            }
        }    

        return i;    
    }
};