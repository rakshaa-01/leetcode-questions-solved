class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.begin(), h.end());
        int i=h.size()-1;
        int sum=0;
        int g=0;
        while(i>=0 && k>0) {
            if(h[i]-g>0) {
                sum+=h[i]-g;
            }
            i--;
            g++;
            k--;
        }
        return sum;
    }
};