class Solution {
public:
    int crossingSum(vector<int>&nums,int L, int mid, int R)
    {
        int LS = 0, RS = 0, LMax = INT_MIN, RMax = INT_MIN;
        for(int i=mid;i>=L;i--)
        {
            LS += nums[i];
            LMax = max(LS,LMax);
        }
        
        for(int i=mid+1;i<=R;i++)
        {
            RS += nums[i];
            RMax = max(RMax,RS);
        }
        return LMax+RMax;
    }
    int divideAndConquer(vector<int> &nums,int L,int R)
    {
        if(L==R) return nums[L];
        int mid = L+(R-L)/2;
        int LS = divideAndConquer(nums,L,mid);
        int RS = divideAndConquer(nums,mid+1,R);
        int CS = crossingSum(nums,L,mid,R);
        return max(CS,max(LS,RS));
    }
    int maxSubArray(vector<int>& nums) 
    {
        if(nums.size()==0) return 0;
        return divideAndConquer(nums,0,nums.size()-1);
    }
};