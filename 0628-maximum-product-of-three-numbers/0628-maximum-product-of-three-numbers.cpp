class Solution {
public:
    bool containsAllPositives(vector<int>& nums) {
        for(auto&ch: nums) {
            if(ch<0) {
                return false;
            }
        }
        return true;
    }
     bool containsAllNegatives(vector<int>& nums) {
        for(auto&ch: nums) {
            if(ch>0) {
                return false;
            }
        }
        return true;
    }
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        if(containsAllPositives(nums) || containsAllNegatives(nums)) {
            return nums[n-1]*nums[n-2]*nums[n-3];
        }
        return max(nums[n-1]*nums[n-2]*nums[n-3], nums[0]*nums[1]*nums[n-1]);
    }
};