class Solution {
public:
    /*
    6 6 7
    6 6 7
    */
    vector<int>setIntersect(vector<int>&nums1,vector<int>& nums2)
    {
        vector<int> intersect;
        int num1Sz = nums1.size(), num2Sz = nums2.size();
        for(int i=0,j=0;i<num1Sz && j<num2Sz;)
        {
            while(i+1<num1Sz && nums1[i]==nums1[i+1]) i++;
            while(j+1<num2Sz && nums2[j]==nums2[j+1]) j++;
            
            if(nums1[i]>nums2[j])  j++;
            else if(nums1[i]==nums2[j])
            {
                intersect.push_back(nums1[i]);               
                i++,j++;
            }
            else i++;
        }
        return intersect;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        //if already sorted
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>intersect;
        
        intersect = nums1.size()>nums2.size() ? setIntersect(nums1,nums2) : setIntersect(nums2,nums1);        
        
        return intersect;
    }
};