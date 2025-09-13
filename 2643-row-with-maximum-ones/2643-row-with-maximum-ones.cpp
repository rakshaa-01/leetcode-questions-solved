class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxCnt=INT_MIN, a=-1, b=-1;
        for(int i=0; i<mat.size(); i++) {
            int cnt=0;
            for(int j=0; j<mat[0].size(); j++) {
                //
                if(mat[i][j]==1) {
                    cnt++;
                }
            }
            if(cnt>maxCnt) {
                maxCnt=cnt;
                a=i;
                b=cnt;
            }
        }
        return {a,b};
    }
};