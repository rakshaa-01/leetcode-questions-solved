class Solution {
public:
    bool possible(vector<int>&time, long long mid, int totalTrips) {
        long long s=0;
        for(int i=0; i<time.size(); i++) {
            s+=(mid/time[i]);
        }
        return s>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low=1;
        long long high=1LL* (*min_element(time.begin(), time.end())) *totalTrips;

        while(low<=high) {
            long long mid=(low+high)>>1;

            if(possible(time, mid, totalTrips)) {
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return (long long) low;
    }
};