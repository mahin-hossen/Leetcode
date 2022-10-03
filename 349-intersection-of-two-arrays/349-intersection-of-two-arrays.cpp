class Solution {
public:
    //TC : nlogn
    //MC : 0(1)
    //using binary search & if already sorted
    vector<int>setIntersect(vector<int>&nums1,vector<int>& nums2)
    {
        vector<int>intersect;
        int sz = nums1.size();     
        
        for(int i=0;i<sz;i++)
        {
            while(i+1<sz && nums1[i]==nums1[i+1]) i++;//for duplicate check
            if(binary_search(nums2.begin(),nums2.end(),nums1[i]))
            {
                intersect.push_back(nums1[i]);
            }
        }
        
        return intersect;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        //if already sorted
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>intersect;
        
        intersect = nums1.size()<nums2.size() ? setIntersect(nums1,nums2) : setIntersect(nums2,nums1);        
        
        return intersect;
    }
};