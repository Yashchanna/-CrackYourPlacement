class Solution {
public:
    
    string clearDigits(string s) {
        
        stack<char> st;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                st.push(s[i]);
            }
            else
            {
                st.pop();
            }
        }

        string ans="";
        while(!st.empty())
        {
            ans=st.top() + ans;
            st.pop();
        }

        return ans;


    }
};