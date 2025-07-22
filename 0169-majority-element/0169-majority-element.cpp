class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size()/2;
        for(int i=0; i<nums.size(); i++) {
            int cnt=count(nums.begin(), nums.end(), nums[i]);
            if(cnt>n) {
                return nums[i];
            }
        }
        return n;
    }
};