/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
 
class Solution 
{
    public:
    int findInMountainArray(int target, MountainArray mountainArr) 
    {
        int peak = peakElement(mountainArr);
        int eltIndex = ascBS(mountainArr,0,peak,target);
        if(eltIndex == -1)
            eltIndex = desBS(mountainArr,peak+1,mountainArr.length()-1,target);
        return eltIndex;
    }
    
     int ascBS(MountainArray arr, int start, int end, int target)
     {
         while (start <= end)
         {
             int mid = start + (end - start) / 2;
             if (arr.get(mid) == target)
                 return mid;
             else if (target < arr.get(mid))
                end = mid - 1;
             else if (target > arr.get(mid))
                 start = mid + 1;
         }
         return -1;
     }
     int desBS(MountainArray arr, int start, int end, int target)
     {
         while (start <= end)
         {
             int mid = start + (end - start) / 2;
             if (arr.get(mid) == target)
                return mid;
             else if (target > arr.get(mid))
                 end = mid - 1;
            else if (target < arr.get(mid))
                 start = mid + 1;
         }
         return -1;
     }

    int peakElement(MountainArray &m) {
        int n=m.length();
        if(m.get(0)>m.get(1)) return 0;
        if(m.get(n-1)>m.get(n-2)) return n-1;

        int low=1, high=n-2;
        while(low<=high) {
            int mid=low+(high-low)/2;

            if( (m.get(mid)>m.get(mid-1)) && (m.get(mid)>m.get(mid+1)) ) {
                return mid;
            }

            if(m.get(mid)>m.get(mid-1))
                low=mid+1;
            else
                high=mid-1;
        }
        return -1;
    }


    // public int orderAgnosticBS(MountainArray mountainArr,int start,int end,int target)
    // {
    //     boolean isAsc = mountainArr.get(start) < mountainArr.get(end);
    //     while(start <= end)
    //     {
    //         int mid = start + (end - start) / 2;
    //         if (mountainArr.get(mid) == target)
    //             return mid;
    //         if (isAsc)
    //         {
    //             if (target < mountainArr.get(mid))
    //                 end = mid - 1;
    //             else
    //                 start = mid + 1;
    //         }
    //         else
    //         {
    //             if (target > mountainArr.get(mid))
    //                 end = mid - 1;
    //             else
    //                 start = mid + 1;
    //         }
    //     }
    //     return -1;
    // }
};

        