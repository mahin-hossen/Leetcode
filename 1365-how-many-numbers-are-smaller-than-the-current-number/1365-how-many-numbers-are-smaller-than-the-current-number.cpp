class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        int len = nums.size();
        vector<int>result(len);
        vector<int> sorted(nums.begin(),nums.end());
        sort(sorted.begin(),sorted.end());

        for(int i=0;i<len;i++)
        {
            auto lb = lower_bound(sorted.begin(),sorted.end(),nums[i]);  
            result[i] = lb-sorted.begin();
        }
        return result;
    }
};