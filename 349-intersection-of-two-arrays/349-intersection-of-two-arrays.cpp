class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>intersect;
        unordered_set<int>bucket(nums1.begin(),nums1.end());
        unordered_set<int>bucket2(nums2.begin(),nums2.end());

        for(auto it: bucket)
        {
            if(bucket2.count(it))
                intersect.push_back(it);
        }
        return intersect;
    }
};