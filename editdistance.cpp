class Solution {
//https://leetcode.com/problems/edit-distance/
public:
    int minDistance(string word1, string word2) {
        int m = word1.size()+1;
        int n = word2.size()+1;

        vector<vector<int>> dp (m, vector<int> (n, 0));
        for (int i = 0; i < n; i++) {
            dp[0][i] = i;
        }
        for (int i = 0; i < m; i++) {
            dp[i][0] = i;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int x = word1[i-1]!=word2[j-1];
                dp[i][j] = min({dp[i-1][j]+1,dp[i][j-1]+1,x+dp[i-1][j-1]});
            }
        }

        return dp[m-1][n-1];
    }
};
