class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum=0, maxi=INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            sum+=nums[i];
            if(sum>maxi) {
                maxi=sum;
            }
            if(sum<0) {
                sum=0;
            }
        }
        int sum1=0, mini=INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            sum1+=nums[i];
            if(sum1<mini) {
                mini=sum1;
            }
            if(sum1>0) {
                sum1=0;
            }
        }
        return abs(sum)+abs(sum1);
    }
};