class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int p=1, c=0, j=0;
        for(int i=0; i<nums.size(); i++) {
            p*=nums[i];
            while(p>=k && j<=i) {
                p/=nums[j];
                j++;
            }
            c+=(i-j+1);
        }
        return c;
    }
};