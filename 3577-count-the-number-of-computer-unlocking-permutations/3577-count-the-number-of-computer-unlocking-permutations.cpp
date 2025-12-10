class Solution {
public:
    long long factorial_recursive(int n) {
        const long long MOD = 1000000007;
    long long result = 1;
    for(int i=1; i<=n; i++) {
        result = (result * i) % MOD;
    }
    return result;
    }

    int countPermutations(vector<int>& c) {
        int x=c[0];
        for(int i=1; i<c.size(); i++) {
            if(c[i]<=x) return 0;
        }
        long long ans=factorial_recursive(c.size()-1);
        return (int) ans%1000000007;
    }
};