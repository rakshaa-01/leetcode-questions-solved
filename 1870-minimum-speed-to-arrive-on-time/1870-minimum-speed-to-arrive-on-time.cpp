class Solution {
public:
    bool possible(vector<int>& dist, int mid, double hour, int n) {
        double s=0;
        for(int i=0; i<dist.size()-1; i++) {
            s+=ceil(dist[i]/(mid*1.0));
        }
        s+=(dist[n-1]/(mid*1.0));
        cout<<mid<<" "<<s<<endl;
        return s<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        if(hour<=(n-1)) return -1;
        int low=1, high=10000000;

        while(low<=high) {
            int mid = low + (high - low) / 2;
            if(possible(dist, mid, hour, n)) {
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return low;
    }
};