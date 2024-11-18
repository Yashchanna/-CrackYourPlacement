class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        
        // Function to handle decryption for positive k
        auto dec = [&](int k) {
            int s = 0;
            for (int i = 0; i < k; ++i) s += code[i];
            ans[n - 1] = s;
            int i = 0, j = k;
            while (i < n - 1) {
                if (j == n) j = 0;
                s -= code[i];
                s += code[j];
                ans[i] = s;
                ++i;
                ++j;
            }
            return ans;
        };

        if (k == 0) {
            return ans; // All elements are 0 when k == 0
        } else if (k > 0) {
            return dec(k); // Directly handle positive k
        } else {
            k = -k; // Convert negative k to positive
            ans = dec(k); // Compute for positive k
            int rotate = n - k - 1;
            if (rotate != 0) rotate = rotate % n;

            // Rotate the result for negative k
            vector<int> rotatedAns(n);
            for (int i = 0; i < n; ++i) {
                rotatedAns[i] = ans[(i + rotate) % n];
            }
            return rotatedAns;
        }
    }
};