class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int , int> mp;
        unordered_map<int, int> ball_number;
        int cnt = 0;
        for (int i = 0; i < queries.size(); i++) {       
           int ind = queries[i][0];
           int val = queries[i][1];
           if(ball_number[ind]!=val){
            int prev = ball_number[ind];
            if(prev!=0){
                mp[prev]--;
                if(mp[prev] == 0) cnt--;
            }
            ball_number[ind] = val;
            mp[val]++;
            if(mp[val] == 1) cnt++;
           }
           ans.push_back(cnt);
        }
        return ans;    
    }
};
