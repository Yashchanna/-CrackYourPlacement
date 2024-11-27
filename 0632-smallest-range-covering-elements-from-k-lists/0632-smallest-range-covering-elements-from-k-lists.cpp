class Info {
public:
    int data;
    int rowIndex;
    int colIndex;

    // Constructor
    Info(int a, int b, int c) {
        this->data = a;
        this->rowIndex = b;
        this->colIndex = c;
    }
};

// Comparator class for priority queue
class compare {
public:
    bool operator()(Info* a, Info* b) {
        return a->data > b->data; // Min-Heap
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*,vector<Info*>,compare>pq;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            Info* d=new Info(nums[i][0],i,0);
            pq.push(d);
            maxi=max(maxi,d->data);
            mini=min(mini,d->data);
        }
    
    int ansStart=mini;
    int ansEnd=maxi;
    while(!pq.empty()){
        Info* tn=pq.top();
        int td=tn->data;
        int tr=tn->rowIndex;
        int tc=tn->colIndex;
        pq.pop();
        mini=tn->data;
        //maxi pahle se h compare kr lete h
        //very very imp
        if((maxi-mini)<(ansEnd-ansStart)){
            ansStart=mini;
            ansEnd=maxi;
        }
        //insertion wala step
        if(tc+1<nums[tr].size()){
            int newe =nums[tr][tc+1];
            maxi=max(maxi,newe);//maximum ko update krne wali heez isliye chal rhi h kyonki sorted h list isliye
            Info* newInfo=new Info(newe,tr,tc+1);
            pq.push(newInfo);
        }
        else{
            break;
        }

    }
            vector<int>ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};