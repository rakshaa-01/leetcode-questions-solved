class Solution {
public:
using ll = long long;
    long long countSubarrays(vector<int>& nums, ll k) {
        long long cnt=0, sum=0, left=0;
        for(int i=0; i<nums.size(); i++) {
            sum+=nums[i];
            while(sum * (i-left+1) >=k) {
                sum-=nums[left++];
            }
            cnt+=(i-left+1);
        }
        return cnt;
    }
};