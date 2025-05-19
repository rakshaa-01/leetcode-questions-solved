class Solution {
public:
    string triangleType(vector<int>& nums) {
        int nums1=nums[0];
        int nums2=nums[1];
        int nums3=nums[2];

        if(nums1==nums2 && nums2==nums3 && nums3==nums1) {
            return "equilateral";
        }
        else if(nums1==nums2 || nums2==nums3 || nums3==nums1) {
            if( ((nums1+nums2) > nums3) && ((nums1+nums3) > nums2) && ((nums2+nums3) > nums1))   {
            return "isosceles";
          }
        }
        else if(nums1!=nums2 && nums2!=nums3 && nums3!=nums1) {
            if( ((nums1+nums2) > nums3) && ((nums1+nums3) > nums2) && ((nums2+nums3) > nums1))  {
            return "scalene";
         }
        }
        return "none";
    }
};