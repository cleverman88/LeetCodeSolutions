//https://leetcode.com/problems/triangle/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
     // [[2], [3,     4],  [  6,    5,    7],  [4,    1   ,   8  ,   3  ]]
     //  (0,0) (1,0) (1,1)  (2,0) (2,1) (2,2)   (3,0), (3,1)  (3,2)  (3,3)
        for(int i = triangle.size()-1 ; i > 0; i--){
            for(int j = 0 ; j < triangle[i].size()-1; j++){
                triangle[i-1][j] = min(triangle[i][j]+triangle[i-1][j], triangle[i][j+1]+triangle[i-1][j] );
            }
        }
    
        
        return triangle[0][0];
    }
};
