class Solution {
//https://leetcode.com/problems/daily-temperatures/
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        return solve(T);
    }
    
    
    
    
    vector<int> solve(vector<int>& T){
        int size = T.size();
        int nextBiggestI = size-1;
        vector<int> dp (size, 0);
        dp[size-1] = 0;
        for(int i = size-2; i >= 0 ; i--){
                int count = 1;
                for(int j = i+1; j <= nextBiggestI; j++){
                    if(T[i] < T[j]){
                        dp[i] = count;
                        break;
                    }
                    count++;
                
                    if(j == size-1){
                        dp[i] = 0;
                    }
                                
                }
                if(T[i] >= T[nextBiggestI]) nextBiggestI = i;
            }
                     return dp;   
        }
    };
