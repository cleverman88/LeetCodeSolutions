class Solution {
//https://leetcode.com/problems/longest-increasing-subsequence/
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        
        vector<int> dp(nums.size() , -1);
        dp[0] = 0;
        for(int i = 1 ; i < nums.size() ; i++) {
            int val = 0;
            int m = 0;
            for(int j = 0 ; j < i; j++) {
                if(nums[i] > nums[j]){
                    val = dp[j] +1;
                }
                m = max(val,m);
            }
            dp[i] = m;
        }
        
            int ma = 0;
        for(auto x : dp){
            ma = max(ma,x);
        }
            return ma + 1;
            
        }
    
};
