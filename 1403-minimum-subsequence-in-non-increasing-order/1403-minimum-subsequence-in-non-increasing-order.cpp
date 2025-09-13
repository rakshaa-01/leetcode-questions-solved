class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        vector<int> ans;

        int origSum=0, sum=0, intSum=0, q=0;
        for(auto& ch: nums) {
            origSum+=ch;
        }

        for(int i=0; i<nums.size(); i++) {
            sum+=nums[i];
            intSum=origSum-sum;

            if(sum>intSum)  {
                q=i;
                break;
            }
        }
        for(int i=0; i<=q; i++) ans.push_back(nums[i]);
        return ans;
    }
};