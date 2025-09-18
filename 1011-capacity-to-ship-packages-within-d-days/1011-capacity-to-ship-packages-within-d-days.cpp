class Solution {
public:
    int possibleDays(vector<int>& weights, int mid) {
        int sum=0, d=1;
        for(int i=0; i<weights.size(); i++) {
            int temp=sum+weights[i];
            if(temp>mid) {
                d++;
                sum=weights[i];
            }
            else {
                sum=temp;
            }
        }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=INT_MIN, sum=0;
        for(int i=0; i<weights.size(); i++) {
            sum+=weights[i];
            maxi=max(maxi, weights[i]);
        }

        int low=maxi, high=sum, ans=sum;
        while(low<=high) {
            int mid=low+(high-low)/2;
            int d=possibleDays(weights, mid);
            if(d<=days) {
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