class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int,int>bucket;
        for(int i=0;i<nums.size();i++)
        {
            bucket[nums[i]] = i;
        }
        
        int first, sec;
        for(int i=0;i<nums.size();i++)
        {
            int num2 = target-nums[i];
            if(bucket.count(num2) && bucket[num2]^i)
            {
                first = i, sec = bucket[target-nums[i]];
                break;
            }   
        }
        return {first,sec};
    }
};