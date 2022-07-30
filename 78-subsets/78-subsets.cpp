class Solution {
public:
    vector<vector<int>> allSubsets;
    void generateSubsets(vector<int>& nums,int index)
    {
        static vector<int> subset;        
        if(index==nums.size())
        {
            allSubsets.push_back(subset);
            return;
        }
        
        subset.push_back(nums[index]);
        generateSubsets(nums,index+1);
        subset.pop_back();
        generateSubsets(nums,index+1);
        
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        allSubsets.clear();
        generateSubsets(nums,0);     
        return allSubsets;
    }
};