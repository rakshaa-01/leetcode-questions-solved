class Solution {
public:
    int part(vector<int>& arr, int low, int high) {
        int pivot=arr[low];
        int i=low, j=high;
        while(i<j) {
            while(i<=high-1 && arr[i]<=pivot) {
                i++;
            }
            while(j>=low+1 && arr[j]>pivot) {
                j--;
            }
            if(i<j) {
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[low], arr[j]);
        return j;
    }
    void qS(vector<int>& arr, int low, int high) {
        if(low<high) {
            int p=part(arr, low, high);
            qS(arr, low, p-1);
            qS(arr, p+1, high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        qS(nums, 0, n-1);
        return nums;
    }
};