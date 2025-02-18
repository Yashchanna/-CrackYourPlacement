class Solution {
public:
    string smallestNumber(string pattern) {
        string ans="";
         
        int n = pattern.length();
        int cnt=1;
        stack<char> st;

        for(int i=0 ;i<n+1;i++)
        {
            st.push(cnt+'0');
            cnt++;

            if(pattern[i]=='I' or i==n)
            {
                while(!st.empty())
                {
                    ans+=st.top();
                    st.pop();
                }
            }
        }

        return ans;
        
    }
};