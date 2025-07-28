class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix[0].size();
        for(int i=0; i<matrix.size(); i++) {
            if(target>=matrix[i][0] && target<=matrix[i][m-1]) {
                bool ans = binary_search(matrix[i].begin(), matrix[i].end(), target);
                if(ans) {
                    return true;
                }
            }
        }
        return false;
    }
};