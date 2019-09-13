//https://leetcode.com/problems/combination-sum/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> temp;
        vector<int> temp2 = {0};
        temp.insert(temp2);
        vector<set<vector<int>>> dp (target+1,temp);
        for(int i = 1; i < target+1; i++){
            for(auto x : candidates){
                int sum = x;
                for(auto y : dp[i-1]){
                    sum = x;
                    for(auto z : y){
                        sum += z;
                    }
                    vector<int> n = y; 
                    n.push_back(x);
                    sort(n.begin(),n.end());
                    if(sum <= target)
                        dp[sum].insert(n);
                }
            }
        }
        vector<vector<int>> sol(0,vector<int>(0));
        for(auto x : dp[target]){
            vector<int> vals(0);
            for(auto y : x){
                if(y != 0){
                    vals.push_back(y);
                }
            }
           
            if(vals.size() != 0){
                sol.push_back(vals);
            } 
        }
        return sol;
    }
};
