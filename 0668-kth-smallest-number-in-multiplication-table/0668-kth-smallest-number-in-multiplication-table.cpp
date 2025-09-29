class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low=1, high=m*n;
        while(low<=high) {
            int mid=(low+high)>>1;

            if(lessThanK(m, n, mid)<k) {
                low=mid+1;
            }
            else 
                high=mid-1;
        }
        return low;
    }
    int lessThanK(int m, int n, int mid) {
        int sum=0;
        for(int i=1; i<=m; i++) {
            sum+=min(n, mid/i);
        }
        return sum;
    }
};