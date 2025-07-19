class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int leftProd=1, rightProd=1;
        vector<int> left(n), right(n);
        for(int i=0; i<n; i++) {
            left[i]=leftProd;
            leftProd*=nums[i];
        }
        for(int i=n-1; i>=0; i--) {
            right[i]=rightProd;
            rightProd*=nums[i];
        }

        for(int i=0; i<nums.size(); i++) {
            nums[i]=left[i]*right[i];
        }
        return nums;
    }
};