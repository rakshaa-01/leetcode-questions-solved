class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if(k==0) {
            return fill(code.begin(), code.end(), 0), code;
        }
        int n=code.size();
        vector<int> res(n);
        for(int i=0; i<n; i++) {
            if(k>0) {
                //
                for(int j=i+1; j<=(i+k); j++)
                    res[i]+=code[j%n];
            }
            else {
                //
                for(int j=i+k; j<=(i-1); j++)
                    res[i]+=code[(j+n)%n];
            }
        }
        return res;
    }
};