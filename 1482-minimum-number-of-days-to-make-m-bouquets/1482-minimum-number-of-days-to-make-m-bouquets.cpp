class Solution {
public:
    bool possible(vector<int>& bloomDay, int mid, int m, int k) {
        int cnt=0, sum=0;
        for(int i=0; i<bloomDay.size(); i++) {
            if(bloomDay[i]<=mid) {
                cnt++;
            }
            else {
                sum+=(cnt/k);
                cnt=0;
            }
        }
        sum+=(cnt/k);
        return sum>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*k > bloomDay.size()) return -1;
        int mini=INT_MAX, maxi=INT_MIN;
        for(int i=0; i<bloomDay.size(); i++) {
            mini=min(mini, bloomDay[i]);
            maxi=max(maxi, bloomDay[i]);
        }

        int low=mini, high=maxi, ans=maxi;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(possible(bloomDay, mid, m, k)) {
                ans=mid;
                high=mid-1; //minimize
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
};