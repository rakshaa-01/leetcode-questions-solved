class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        if (k == 1) return n >= 2;
        int i=0, j=k+i;
        int a=i+1, b=j+1;
        int ws=1;
        while(j<(n-k+1)) {
            if(ws<k && nums[i+ws-1]<nums[a] && nums[j+ws-1]<nums[b]) {
                ws++;
                a++;
                b++;
                if(ws==k) return true;
            }
            else {
                ws=1;
                i++;
                j++;
                a=i+1, b=j+1;
            }
        }
        return false;
    }
};