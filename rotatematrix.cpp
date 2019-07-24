class Solution {
//https://leetcode.com/problems/rotate-image/
public:
    void rotate(vector<vector<int>>& matrix) {
        
//         int i = 0;
//         int j = matrix.size()-1;
        
//         vector<vector<int>> matrix2 = matrix;
//         for(auto x : matrix2){

            
//             for(auto y : x){
//                 matrix[i][j] = y;
//                 i++;
//             }
//             j--;
//             i = 0;
//         }
        
        solve(matrix,matrix);
        
    
        
    }
    
    
    void solve(vector<vector<int>>& matrix, vector<vector<int>> matrix2){
        
         int i = 0;
        int j = matrix.size()-1;
        
        for(auto x : matrix2){

            
            for(auto y : x){
                matrix[i][j] = y;
                i++;
            }
            j--;
            i = 0;
        }
        
        
    }
    
    void printMatrix(vector<vector<int>>& matrix){
        for(auto x : matrix){
            for(auto y : x){
                cout << y << " ";
            }
            cout << "\n";
        }
    }
};
