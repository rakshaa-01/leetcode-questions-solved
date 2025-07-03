class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto& ch: nums) {
            mp[ch]++;
        }
        int max=0;
        for(int i=0; i<nums.size(); i++) {
            if(find(nums.begin(), nums.end(), nums[i]+1)!=nums.end()) {
                int temp=mp[nums[i]]+mp[nums[i]+1];
                if(temp>max) {
                    max=temp;
                }
            }
        }
        return max;
    }
};