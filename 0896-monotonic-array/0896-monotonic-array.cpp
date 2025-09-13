class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isInc=false, isDec=false;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]<nums[i-1]) isDec=true;
            if(nums[i]>nums[i-1])   isInc=true;

            if(isInc && isDec)  return false;
        }
        return true;
    }
};