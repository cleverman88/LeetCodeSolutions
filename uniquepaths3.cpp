class Solution {
//https://leetcode.com/problems/unique-paths-iii/
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int maxSteps = (grid.size() * grid[0].size()-1);
        int minus = 0;
        for(auto x : grid){
            for(auto y : x){
                if(y == -1){
                    minus++;
                }
            }
        }
        maxSteps = maxSteps - minus;
        
        int PATHS = 0;
        
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    solution(grid,i,j,PATHS,0,maxSteps,visited);
                    break;
                }
            }
        }
        return PATHS;
        
    }
    
    
    bool solution(vector<vector<int>>& grid, int i, int j, int& pathToEnd, int steps, int maxSteps,vector<vector<bool>>& visited){
        visited[i][j] = true;
        if(grid[i][j] == 2){
            if(maxSteps == steps){
                return true;
            }
            
            else{return false;}
        }
        // [1,0,0,0]
        // [0,0,0,0]
        // [0,0,2,-1]
        //
        //cout << "I is value " << i << " J is value " << j << endl;
        
        
        if(i+1 < grid.size() && visited[i+1][j] == false && grid[i+1][j] != -1){
            visited[i+1][j] = true;
            if(solution(grid,i+1,j,pathToEnd,steps+1,maxSteps,visited)){
                pathToEnd++;
                
            }
            visited[i+1][j] = false;
        }
        if(j+1 < grid[0].size() && visited[i][j+1] == false && grid[i][j+1] != -1){
            visited[i][j+1] = true;
            if(solution(grid,i,j+1,pathToEnd,steps+1,maxSteps,visited)){
                pathToEnd++;
            }
            visited[i][j+1] = false;
        }
        if(i-1 >= 0 && visited[i-1][j] == false && grid[i-1][j] != -1){
            visited[i-1][j] = true;
            if(solution(grid,i-1,j,pathToEnd,steps+1,maxSteps,visited)){
                pathToEnd++;
            }
            visited[i-1][j] = false;
        }
        if(j-1 >= 0 && visited[i][j-1] == false && grid[i][j-1] != -1){
            visited[i][j-1] = true;
            if(solution(grid,i,j-1,pathToEnd,steps+1,maxSteps,visited)){
                pathToEnd++;
            }
            visited[i][j-1] = false;
        }
        
        return false;
    }
};
