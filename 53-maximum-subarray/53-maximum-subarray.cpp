class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
/*
[-2,1,-3,4,-1,2,1,-5,4]
 -2 -1 -4 0 -1 1 2 -3 1
 
[5,4,-1,7,8]
 5 9 8 15 23
*/        
        int maxSub = nums[0];
        int currSub = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            currSub = max(nums[i],nums[i]+currSub);
            maxSub = max(currSub,maxSub);
        }
        
        return maxSub;
    }
};