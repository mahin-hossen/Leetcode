class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        7 1 5 3 6 4
        5        
        */
        int minPrice = prices[0];
        int profit = 0;
        
        for(auto price : prices)
        {
            minPrice = min(price,minPrice);
            profit = max(price-minPrice,profit);
        }
        return profit;
    }
};