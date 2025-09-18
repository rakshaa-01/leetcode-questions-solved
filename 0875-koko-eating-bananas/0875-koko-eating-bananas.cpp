class Solution {
public:
    long long possibleHrs(vector<int>& piles, int mid, int h) {
        long long hr=0;
        for(int i=0; i<piles.size(); i++) {
            hr+=(ceil)(piles[i]/(double)mid);
            if(hr>h) return hr;
        }
        return (int)hr;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high= *max_element(piles.begin(), piles.end());

        int ans=high;
        while(low<=high) {
            int mid=low+(high-low)/2;
            long long hr=possibleHrs(piles, mid, h);
            if(hr<=(long long) h) {
                ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
};