class Solution {
public:
    int bestClosingTime(string c) {
        int n = c.length();
        vector<int> arr(n + 1);

        // Initial count of 'Y'
        int ans = 0;
        for (char ch : c) {
            if (ch == 'Y') ans++;
        }

        // i = 0 case (no flip yet)
        arr[0] = ans;

        for (int i = 1; i <= n; i++) {
            // Flip c[i-1]
            if (c[i-1] == 'Y') {
                c[i-1] = 'N';
                ans--;   // one less 'Y'
            } else {
                c[i-1] = 'Y';
                ans++;   // one more 'Y'
            }
            arr[i] = ans;
        }

        int m = *min_element(arr.begin(), arr.end());
        for (int i = 0; i <= n; i++) {
            if (arr[i] == m) return i;
        }
        return 0;
    }
};
