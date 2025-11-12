class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n=nums.size();
        long long S2=(n*(n+1)*(2*n+1))/6;
        long long S1=n*(n+1)/2;

        long long S2N=0, S1N=0;
        for(auto& ch: nums) {
            S2N+=(ch*ch);
            S1N+=ch;
        }
        
        long long minus=S1N-S1;
        long long plus=(S2N-S2)/minus;
        int rep=(minus+plus)/2;
        int mis=rep-minus;
        return {rep, mis};
    }
};