class Solution {
public:
    int findGCDOfTwo(int a, int b) {
        if(a==0) return b;
        if(b==0) return a;
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        for(int i=0; i<nums.size()-1; i++) {
            int ans=findGCDOfTwo(nums[i], nums[i+1]);
            if(ans==1) {
                continue;
            }
            else {
                long long lcm=(nums[i]/ans)*nums[i+1];
                nums[i]=(int)lcm;
                nums.erase(nums.begin()+i+1);
                i=i-2;
                if(i<-1) i=-1;
            }
        }
        return nums;
    }
};