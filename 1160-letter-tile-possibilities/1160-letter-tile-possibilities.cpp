class Solution {
public:
    void solve(string &tiles, string curr, vector<bool> &used, set<string> &st) {
        if (!curr.empty()) {
            st.insert(curr);
        }

        for (int i = 0; i < tiles.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                solve(tiles, curr + tiles[i], used, st);
                used[i] = false;  // backtrack
            }
        }
    }

    int numTilePossibilities(string tiles) {
        set<string> st;
        vector<bool> used(tiles.size(), false);
        solve(tiles, "", used, st);
        return st.size();
    }
};
