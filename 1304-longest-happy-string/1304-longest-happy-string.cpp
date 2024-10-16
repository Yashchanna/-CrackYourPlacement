class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;

        if(a>0)
        {
            pq.push({a , 'a'});
        }

        if(b>0)
        {
            pq.push({b , 'b'});
        }

        if(c>0)
        {
            pq.push({c , 'c'});
        }


        string result="";

        while(!pq.empty())
        {
            int curcount = pq.top().first;
            char curchar = pq.top().second;

            pq.pop();
            int n=result.length();
            if(result.length()>=2 && result[n-1]==curchar && result[n-2]==curchar)
            {
                if(pq.empty()) break;

                int nextcount = pq.top().first;
                char nextchar = pq.top().second;

                pq.pop();

                result.push_back(nextchar);
                nextcount--;
                if(nextcount>0)  pq.push({nextcount , nextchar});

            }
            else
            {
                 result.push_back(curchar);
                  curcount--;             
            }

            if(curcount>0)  pq.push({curcount , curchar});
        }

        return result;
        
    }
};