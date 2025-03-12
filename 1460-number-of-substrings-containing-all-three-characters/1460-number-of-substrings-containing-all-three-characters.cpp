class Solution {
public:
    int numberOfSubstrings(const string& s) {
        int result = 0;

        int left = 0;
        int a_count = 0;
        int b_count = 0;
        int c_count = 0;
        for (int right = 0; right < s.size(); ++right) {
            if (s[right] == 'a') {
                ++a_count;
            }
            else if (s[right] == 'b') {
                ++b_count;
            }
            else {
                ++c_count;
            }

            while (a_count > 0 && b_count > 0 && c_count > 0) {
                result += s.size() - right;
                if (s[left] == 'a') {
                    --a_count;
                }
                else if (s[left] == 'b') {
                    --b_count;
                }
                else {
                    --c_count;
                }
                ++left;
            }
        }

        return result;
    }
};