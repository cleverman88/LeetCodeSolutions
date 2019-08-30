class Solution {
//https://leetcode.com/problems/word-break/
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for(auto x : wordDict) set.insert(x);
        
        return solution3(s,set);
        
    }
        
    bool solution3(string s, unordered_set<string> set){
        
        vector<bool> dp(s.size()+1,false);
            
        dp[0] = true;
        
        for(int i = 1; i <= s.size(); i++){
            for(int j = i-1 ; j >= 0; j--){
                if(dp[j]){
                    string word = s.substr(j, i-j);
                    cout << word << endl;
                     if(set.find(word)!= set.end())
                    {
                        dp[i]=true;
                        break; 
                    }
                }
                
            }
            
        }
        for(auto x : dp){cout << x << " ";}
        return dp[s.size()];
        
    }
};
