class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n= prices.size();
        sort(prices.begin(), prices.end());
        int ans= money;
        if(prices[0]+prices[1]<=money) ans= money-prices[0]-prices[1];
        return ans; 

    }
};