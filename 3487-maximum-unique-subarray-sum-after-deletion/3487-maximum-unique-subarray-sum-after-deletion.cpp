class Solution {
public:
    bool allNegatives(vector<int>& nums) {
        for(auto& ch: nums) {
            if(ch>0) {
                return false;
            }
        }
        return true;
    }

    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto it=unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());
        int sum=0;
    
        bool flg=false;
        for(auto& ch: nums) {
            if(ch>=0) {
                sum+=ch;
            }
            if(ch==0) {
                flg=true;
            }
        }

        if(flg && allNegatives(nums)) {
            return 0;
        }
        else if(sum==0 && allNegatives(nums)) {
            return nums[nums.size()-1];
        }

        return sum;
    }
};