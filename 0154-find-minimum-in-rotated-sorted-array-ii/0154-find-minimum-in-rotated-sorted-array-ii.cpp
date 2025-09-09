class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0, end=nums.size()-1, mini=INT_MAX;
        while(start<=end) {
            int mid=start+(end-start)/2;

            mini=min(mini, nums[start]);
            mini=min(mini, nums[mid]);
            mini=min(mini, nums[end]);

            if(nums[start]==nums[mid] && nums[mid]==nums[end]) {
                start++;
                end--;
                continue;
            }
            
            if(nums[start]<=nums[mid]) {
                // mini=min(mini, nums[start]);
                start=mid+1;
            }
            else {
                // mini=min(mini, nums[mid]);
                end=mid-1;
            }
        }
        return mini;
    }
};