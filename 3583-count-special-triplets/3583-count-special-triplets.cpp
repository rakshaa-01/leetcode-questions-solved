class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> left, right;
        for(auto& c: nums) right[c]++;

        int ans=0;
        for(int i=0; i<nums.size(); i++) {
            int x=nums[i];
            right[x]--;
            if(i!=0) {
                int l=left[2*x];
                int r=right[2*x];
                ans+=(l*r)%10000007;
            }
            left[x]++;
        }
        return ans%10000007;
    }
};