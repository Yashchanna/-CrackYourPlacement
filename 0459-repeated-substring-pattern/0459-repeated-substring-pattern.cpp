class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string x;
        for(int i=0;i<s.size()/2;i++){
            x+=s[i];
            string y;
            while(y.size()<s.size()){
                y+=x;
            }
            //cout<<y<<endl;
            if(y==s) return true;
        }
        return false;
    }
};