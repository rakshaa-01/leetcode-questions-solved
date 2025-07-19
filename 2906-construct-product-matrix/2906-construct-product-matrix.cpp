class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int rows=grid.size(), cols=grid[0].size();
        vector<int> left(rows*cols), right(rows*cols);
        int leftMax=1, rightMax=1;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                int idx=(i*cols)+j;
                left[idx]=leftMax;
                leftMax*=grid[i][j];
            }
        }

        for(int i=rows-1; i>=0; i--) {
            for(int j=cols-1; j>=0; j--) {
                int idx=(i*cols)+j;
                right[idx]=rightMax;
                rightMax*=grid[i][j];
            }
        }

         for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                int idx=(i*cols)+j;
                grid[i][j]=(left[idx]*right[idx])%12345;
            }
        }
        return grid;
    }
};