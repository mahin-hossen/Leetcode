class Solution {
public:
    vector<int>intersect (vector<int> &nums1,vector<int> &nums2)
    {
        unordered_map<int,int>bucket;
        vector<int>doesIntersect;
        for(auto it: nums1)
        {
            bucket[it]++;
        }
        for(auto it: nums2)
        {
            if(bucket.count(it) && bucket[it]>0)
            {
                doesIntersect.push_back(it);
                bucket[it]--;
            }
        }
        return doesIntersect;

    }

};