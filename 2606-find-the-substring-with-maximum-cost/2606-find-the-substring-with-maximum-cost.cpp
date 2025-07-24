class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> nums;
        for(auto& ch: s) {
            int sum=0;
            bool ok=false;
            for(int g=0; g<chars[g]!='\0'; g++) {
                if(ch==chars[g]) {
                    sum+=vals[g];
                    ok=true;
                    break;
                }
            }
            if(!ok) {
                sum+=ch-'a'+1;
            }
            nums.push_back(sum);
        }
        int sum=0, maxi=INT_MIN;
        for(auto& c: nums) {
            sum+=c;
            if(sum>maxi) {
                maxi=sum;
            }
            if(sum<0) {
                sum=0;
            }
        }
        return max(maxi, 0);
    }
};