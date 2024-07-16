class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0,price=prices[0];
        for(int i=1;i<prices.size();i++){
            int profit = prices[i]-price;
            price = min(price,prices[i]);
            maxProfit=max(maxProfit,profit);
        }
        return maxProfit;
    }
};
