class Solution {
public:
    long long possibleChildren(vector<int>& candies, int mid, long long k) {
        long long c=0;
        for(int i=0; i<candies.size(); i++) {
            c+=candies[i]/mid;
            if(c>k) return c;
        }
        return c;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum=accumulate(candies.begin(), candies.end(), 0LL);

        if(k>sum) return 0;
        int low=1, ans=-1;
        int high=*max_element(candies.begin(), candies.end());

        while(low<=high) {
            int mid=(low+high) >> 1;

            long long c=possibleChildren(candies, mid, k);

            if(c<k) {
                high=mid-1;
            }
            else {
                ans=mid;
                low=mid+1;
            }
        }
        return ans;
    }
};