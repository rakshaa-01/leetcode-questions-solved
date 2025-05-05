class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left; i<=right; i++) {
            int no=i, q=0;
            bool ok=true;
            while(no>0) {
                int rem=no%10;
                q++;
                if(rem==0 || i%rem!=0) {
                    ok=false;
                    break;
                }
                no=no/10;
            }
            if(ok) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};