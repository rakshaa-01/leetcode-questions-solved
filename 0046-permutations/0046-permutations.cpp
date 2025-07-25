class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums) {
       int ind=-1, n=nums.size();
       for(int i=n-2; i>=0; i--) {
            if(nums[i]<nums[i+1]) {
                ind=i;
                break;
            }
       }
       if(ind==-1) {
        reverse(nums.begin(), nums.end());
        return nums;
       }

       for(int i=n-1; i>ind; i--) {
            if(nums[i]>nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
       }
       reverse(nums.begin()+ind+1, nums.end());
       return nums;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size(), i=0;
        int factorial=1;
        for (int i = 1; i <= n; ++i) {
        factorial *= i;
        }
        vector<vector<int>> ans;
        while(i<factorial) {
            ans.push_back(nextPermutation(nums));
            i++;
        }
        return ans;
    }
};