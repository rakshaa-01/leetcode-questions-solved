class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> setRows;
        unordered_set<int> setCols;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j]==0) {
                    setRows.insert(i);
                    setCols.insert(j);
                }
            }
        }

        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                 if(setRows.count(i)==1 || setCols.count(j)==1) {
                         matrix[i][j]=0;
                }
            }
        }
    }
};