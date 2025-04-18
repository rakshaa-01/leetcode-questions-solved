class Solution {
public:
    int reverseDegree(string s) {
        int prod=0;
        for(int i=0; i<s.length(); i++) {
            int num=26 - (s[i] - 97 + 1) + 1;
            int idx=i+1;
            prod+=num*idx;
        }
        return prod;
    }
};