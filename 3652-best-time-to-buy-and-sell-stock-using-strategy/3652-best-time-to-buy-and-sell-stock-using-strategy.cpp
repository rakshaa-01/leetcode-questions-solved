class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long P=0;
        vector<int> some;
        for(int i=0; i<k/2; i++) {
            some.push_back(0);
        }
        for(int i=k/2; i<k; i++) {
            some.push_back(1);
        }

        for(int i=0; i<prices.size(); i++) {
            P+=(prices[i]*strategy[i]);
        }
        long long maxi=P;
        for(int i=0; i<=prices.size()-k; i++) {
            long long sum=0, sum1=0;
            int g=0;
            for(int j=i; j<(i+k); j++) {
                sum+=(prices[j]*strategy[j]);
                sum1+=(prices[j]*some[g++]);
            }
            long long star=P-sum+sum1;
            maxi=max(maxi, star);
        }
        return maxi;
    }
};