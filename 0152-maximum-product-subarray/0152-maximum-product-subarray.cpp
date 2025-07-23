class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //Case1 - +ve numbers
        //Case2 - -ve numbers - prefix/suffix will be the max subarray
        //Case3 - 0's
        int pre=1, suff=1, maxi=INT_MIN;
        int n=nums.size();
        for(int i=0; i<n; i++) {
            if(pre==0) pre=1;
            if(suff==0) suff=1;
            pre=pre*nums[i];
            suff=suff*nums[n-i-1]; //this is to last index traversal
            maxi=max(maxi, max(pre, suff));
        }
        return maxi;
    }
};