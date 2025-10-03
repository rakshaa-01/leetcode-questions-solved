class Solution {
public:
    int nthUglyNumber(int n) {
        long long low = 1, high = INT_MAX, ans = 1; 

        while (low <= high) {
            long long mid = (low + high) >> 1;

            if (countUgly(mid) >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return (int)ans;
    }

    long long countUgly(long long x) {
        long long cnt = 0;
        // powers of 2
        for (long long a = 1; a <= x; a *= 2) {
            // powers of 3
            for (long long b = a; b <= x; b *= 3) {
                // powers of 5
                for (long long c = b; c <= x; c *= 5) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
