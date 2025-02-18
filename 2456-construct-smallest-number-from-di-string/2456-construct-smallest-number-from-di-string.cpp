class Solution {
public:
    string smallestNumber(string pattern) {
          string ans(pattern.length() + 1, '0');

        for(int i = 0; i < ans.length(); i++) {
            ans[i] += (i + 1);
        }

        while (true) {
            bool valid = true;
            
            for (int i = 0; i < pattern.length(); i++) {
                if ((pattern[i] == 'I' && ans[i] >= ans[i + 1]) ||
                    (pattern[i] == 'D' && ans[i] <= ans[i + 1])) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) return ans;
            
            next_permutation(ans.begin(), ans.end());
        }

        return ans;

    }
};