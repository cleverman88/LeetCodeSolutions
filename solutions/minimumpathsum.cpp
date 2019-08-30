//https://leetcode.com/problems/minimum-path-sum/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> s (grid.size()+2,vector <int> (grid[0].size()+2, 100000));
        s[1][1] = grid[0][0];
        s[1][0] = 0;
        s[0][1] = 0;
        for(int i = 1; i < grid.size()+1; i++){
            for(int j = 1; j <
                grid[0].size() + 1; j++){
                s[i][j] = min(s[i-1][j], s[i][j-1]) + grid[i-1][j-1];
            }
            
        }
      
        return s[grid.size()][grid[0].size()];
        
    }
};
