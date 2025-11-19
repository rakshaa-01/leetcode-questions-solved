class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        while(1) {
            int cnt=count(nums.begin(), nums.end(), original);
            if(cnt!=0) {
                original=original*2;
            }
            else {
                return original;
            }
        }
        return -1;
    }
};