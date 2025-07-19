class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        if(n<2) {
            return 0;
        }
        vector<int> prefixMax(n), suffixMax(n);
        int sum=0, prefixSum=0, suffixSum=0;
        
        for(int i=0; i<arr.size(); i++) {
            prefixSum=max(prefixSum, arr[i]);
            prefixMax[i]=prefixSum;
        }
        for(int i=n-1; i>=0; i--) {
            suffixSum=max(suffixSum, arr[i]);
            suffixMax[i]=suffixSum;
        }
        
        for(int i=1; i<n-1; i++) {
            sum+=min(prefixMax[i], suffixMax[i])-arr[i];
        }
        return sum;
    }
};