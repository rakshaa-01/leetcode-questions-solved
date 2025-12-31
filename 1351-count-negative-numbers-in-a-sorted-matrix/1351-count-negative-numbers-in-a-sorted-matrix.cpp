class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j]<0) {
                    ans+=col-j;
                    cout<<ans<<endl;
                    break;
                }
            }
        }
        return ans;
    }
};