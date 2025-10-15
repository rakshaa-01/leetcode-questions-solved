class Solution {
public:
bool possible(vector<int>& nums, int k) {
    int n=nums.size();
        if (k == 1) return n >= 2;
        vector<int> inc(n,1);
        for(int i=n-2; i>=0; i--) {
            if(nums[i]<nums[i+1]) inc[i]=inc[i+1]+1;
        }

        int i=0, j=k;
        while(j<n) {
            if(inc[i]>=k && inc[j]>=k) {
                return true;
            }
            i++;
            j++;
        }
        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int low=1, high=n/2;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(possible(nums, mid)) {
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return high;
    }
};