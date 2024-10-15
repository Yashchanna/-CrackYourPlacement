class Solution {
public:
    long long minimumSteps(string s) {
        int black=0;
        long long swaps=0;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
            {
                black++;
            }
            if(s[i]=='0')
            {
                swaps+=black;
            }
        }
        return swaps;
    }
};