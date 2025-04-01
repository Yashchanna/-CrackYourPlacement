class Solution {
public:
    // vector< long long> dp(+1,0);
     long long solve(vector<vector< int>>& q ,  long long i ,  long long n ,vector< long long>& dp)
    {
        if(i>= n)
        {
          return 0 ; 
        }

        if(dp[i]!=0) return dp[i];


        long long points1 = q[i][0] + solve(q , i+q[i][1]+1 , n ,dp);
        long long points2 = solve(q , i+1 , n ,dp);

        return dp[i]=max(points1 , points2);
    }
    long long mostPoints(vector<vector<int>>& questions) {

        long long n = questions.size();
        long long points=0 ; 
       vector< long long> dp(n+1,0);
       return solve(questions , 0 ,n ,dp);
        
    }
};