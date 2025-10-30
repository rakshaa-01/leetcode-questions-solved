class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int passes=target[0];
        for(int i=1; i<target.size(); i++) {
            if(target[i]>target[i-1]) {
                passes+=target[i]-target[i-1];
            }
        }
        return passes;
    }
};