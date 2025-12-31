class Solution {
public:
    int findPosCnt(vector<int>& nums) {
        int n=nums.size();
        int low=0, high=n-1;
        while(low<=high) {
            int mid=(low+high)>>1;
            if(nums[mid]>=0) {
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return n-(high+1);
    }
    int maximumCount(vector<int>& nums) {
        int cntZero=count(nums.begin(), nums.end(), 0);
        int pos=findPosCnt(nums);
        int neg=nums.size()-pos;
        pos=pos-cntZero;
        return max(pos, neg);
    }
};