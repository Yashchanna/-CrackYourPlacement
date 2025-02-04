class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j = 0;

        int m = nums1.size();
        int n = nums2.size();
     
        vector<int> merge ;

        while(i<m && j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                merge.push_back(nums1[i++]);
                
            }
            else if(nums2[j]<nums1[i])
            {
                merge.push_back(nums2[j++]);
                
            }
        }

        while(i<m)
        {
             merge.push_back(nums1[i++]);
                
        }

        while(j<n)
        {
             merge.push_back(nums2[j++]);
                
        }

        // for(int i=0 ; i<m+n ; i++)
        // {
        //     cout<<merge[i];
        // }

        if((m+n)%2!=0)
        {
            int num =(m+n)/2 ;
            return merge[num];
        }
        else
        {
            int num1=(m+n)/2;
            int num2=num1 -1;
            
            float result =float(merge[num1] + merge[num2])/2;
            return result;

        }
           

        // return (((m+n)%2==1) ? merge[(m+n)/2] : (merge[(m+n)/2]+merge[((m+n)/2)-1])/2.0);

        return 0;
        
        
    }
};