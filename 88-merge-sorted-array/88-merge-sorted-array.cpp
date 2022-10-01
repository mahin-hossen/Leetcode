class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int sz = m+n-1;
        m--,n--;
        while(m>=0 && n>=0)
        {
            if(nums1[m]>nums2[n]) nums1[sz] = nums1[m], m--;
            else nums1[sz] = nums2[n], n--;
            sz--;
        }
        while(m>=0)
        {
            nums1[sz]=nums1[m];
            sz--,m--;
        }
        while(n>=0)
        {
            nums1[sz]=nums2[n];
            sz--,n--;
        }
        return;


    }
};

// [1,2,5,6], [1,3,4,7]
// [1,1,2,3,4,5,6,7]