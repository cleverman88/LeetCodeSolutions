class Solution {
//https://leetcode.com/problems/spiral-matrix-ii/
public:
    vector<vector<int>> generateMatrix(int n) {       
        vector<vector<int>> values(n,vector<int>(n,-1));
        //vector<vector<bool>> visited(n,vector<bool>(n,false));
        pair<int,pair<int,int>> p = goRight(values,0,0,0);
        while(!checkAllVisited(values)){
            p = goDown(values,p.first,p.second.first,p.second.second);
            p = goLeft(values,p.first,p.second.first,p.second.second);
            p = goUp(values,p.first,p.second.first,p.second.second);
            p = goRight(values,p.first,p.second.first,p.second.second);
            
        }
        return values;   
    }
    
    pair<int,pair<int,int>> goUp(vector<vector<int>>&values, int i , int j,int num){
        num++;
        for(;i >= 0; i--){
            if(values[i][j] == -1){
                values[i][j] = num;
                num++;
            }
            else{break;}
        }
        num--;
        return {i+1,{j+1,num}};
    }
    
    pair<int,pair<int,int>> goDown(vector<vector<int>>&values, int i , int j,int num){
        num++;
        for(;i < values.size(); i++){
            if(values[i][j] == -1){
                values[i][j] = num;
                num++;
            }
            else{break;}
        }
        num--;
        return {i-1,{j-1,num}};
    }
    
    pair<int,pair<int,int>> goRight(vector<vector<int>>&values, int i , int j,int num){
        num++;
        for(;j < values.size(); j++){
            if(values[i][j] == -1){
                values[i][j] = num;
                num++;
            }
            else{break;}
        }
        num--;
        return {i+1,{j-1,num}};
    }
    
    pair<int,pair<int,int>> goLeft(vector<vector<int>>&values, int i , int j,int num){
        num++;
        for(;j >= 0; j--){
            if(values[i][j] == -1){
                values[i][j] = num;
                num++;
            }
            else{break;}
        }
        num--;
        return {i-1,{j+1,num}};
    }
    
    bool checkAllVisited(vector<vector<int>>& visited){
        for(auto x : visited){
            for(auto y : x){
                if(y == -1){
                    return false;
                }
            }
        }
        return true;
    }
    

};
