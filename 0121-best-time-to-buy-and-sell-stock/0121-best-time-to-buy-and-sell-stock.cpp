class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro=0;
        int minPrice=INT_MAX;

        for(int price: prices){
            maxPro=max(maxPro,price-minPrice);
            minPrice=min(minPrice,price);
        }

        return maxPro;
    }
};