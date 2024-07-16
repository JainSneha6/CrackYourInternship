class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit=0,price=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>price){
                totalProfit+=prices[i]-price;
            }
            price=prices[i];
        }
        return totalProfit;
    }
};
