class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int cnt=0, ans=0, left=0;
        int maxElem = *max_element(nums.begin(), nums.end());
        for(int right=0; right<nums.size(); right++) {
            if(nums[right]==maxElem) {
                cnt++;
            }
            while(cnt==k) {
                if(nums[left++]==maxElem) {
                    cnt--;
                }
            }
            ans+=left;
        }
        return ans;
    }
};