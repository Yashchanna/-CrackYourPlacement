class Solution {
public:
    bool isPalindrome(int x) {
        string temp = to_string(x);
        int i=0 , j=temp.length()-1;

        while(i<j)
        {
            if(temp[i]!=temp[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;


    }
};