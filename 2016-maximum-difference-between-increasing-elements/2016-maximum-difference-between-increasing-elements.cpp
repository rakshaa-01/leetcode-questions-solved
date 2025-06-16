class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int min_val = nums[0];
        int ans = -1;
        
        for (int j = 1; j < n; ++j) {
            if (nums[j] > min_val) {
                ans = max(ans, nums[j] - min_val);
            } else {
                // new minimum candidate
                min_val = nums[j];
            }
        }
        
        return ans;
    }
};
