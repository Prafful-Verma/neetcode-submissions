class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, buy = INT_MAX;
        for(int i : prices) {
            buy = min(i, buy);
            profit = max(profit, i-buy);
        }
        return profit;
    }
};
