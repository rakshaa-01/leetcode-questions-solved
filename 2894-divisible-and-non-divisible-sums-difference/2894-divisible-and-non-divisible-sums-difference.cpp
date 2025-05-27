class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sD=0, sND=0;
        for(int i=1; i<=n; i++) {
            if(i%m!=0) {
                sND+=i;
            }
            else {
                sD+=i;
            }
        }
        return sND-sD;
    }
};