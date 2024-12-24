class Solution {
public:
    int ans = 0;
    int solve(int cur , int parent , vector<int> adj[]){
        int mx  = 0 , smx = 0;
        for(int nb : adj[cur]){
            if(nb == parent){
                continue;
            }
            int h = solve(nb , cur , adj);
            if(h>=mx){
                smx = mx;
                mx = h;
            }
            else if(h>=smx){
                smx = h;
            }
        }
        ans = max(ans , mx + smx);
        return mx + 1;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& A, vector<vector<int>>& B) {
       const int n = A.size();
      const  int m = B.size();
        vector<int> mp[n+1];
        vector<int> mp2[m+1];
        for(auto it : A){
            auto u = it[0];
            int v = it[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        for(auto it : B){
            auto u = it[0];
            int v = it[1];
            mp2[u].push_back(v);
            mp2[v].push_back(u);
        }
        ans = 0;
        solve(0,-1,mp);
        int d1 = ans;
        ans = 0;
        solve(0,-1,mp2);
        int d2 = ans;
        ans = max(d1 , d2);
        return max(((d1+1)/2)+ 1 + (d2+1)/2 , ans);
    }
};