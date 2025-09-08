class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(nums[mid]==target) {
                return mid;
            }

            //left half is sorted
            if(nums[low]<=nums[mid]) {
                if(nums[low]<=target && target<=nums[mid]) //elt in left sorted half
                    high=mid-1;

                else //elt not in left sorted half
                    low=mid+1;
            }

            //right half is sorted
            else {
                if(nums[mid]<=target && target<=nums[high]) {
                    low=mid+1;
                }
                else 
                    high=mid-1;
            }
        }
        return -1;
    }
};