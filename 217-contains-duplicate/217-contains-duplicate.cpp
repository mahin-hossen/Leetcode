class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        set<int> bucket;
        bool exist = false;
        for(auto num:nums)
        {
            if(bucket.count(num))
            {
                exist = true;
                break;
            }
            bucket.insert(num);
                
        }
        return exist;
    }
};