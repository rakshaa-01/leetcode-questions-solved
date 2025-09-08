class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0, end=nums.size()-1, pivot=0;
        while(start<=end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] >= nums[0]) {
            start = mid + 1;
        } else {
            pivot = mid;       // potential pivot
            end = mid - 1;     // move left, avoid infinite loop
        }
    }
    return nums[pivot];
    }
};