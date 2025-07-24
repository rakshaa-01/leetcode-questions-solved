class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        vector<int> num;
        for(int i=0; i<numOnes; i++) {
            num.push_back(1);
        }
        for(int i=0; i<numZeros; i++) {
            num.push_back(0);
        }
        for(int i=0; i<numNegOnes; i++) {
            num.push_back(-1);
        }
        int sum=0;
        for(int i=0; i<k; i++) {
            sum+=num[i];
        }
        return sum;
    }
};