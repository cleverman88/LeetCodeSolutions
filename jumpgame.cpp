class Solution {
//https://leetcode.com/problems/jump-game/
public:
    bool canJump(vector<int>& nums) {
        bool carry = false;
        int size = nums.size();
        
        if(nums[0] == 0 && size > 1){return false;}
        
        for(int i = 1; i < size-1; i++){
            if (nums[i] == 0){
                carry = true;
                break;
            }
        }
        
        if(carry){
        vector<int> dp(size,-1);
        dp[nums.size()-1] = 1; 
        
        for(int i = size-2 ; i >= 0; i--){
            
            for(int j = 0; j <= nums[i]; j++){
                int val;
                if(i+j >= size){
                    val = size-1;
                }
                else{val = i+j;}
                
                if(dp[val] == 1){
                    dp[i] = 1;
                    break;
                }
                
            }
        }

            
            if(dp[0] == -1){
                return false;
            }
            
            return true;
        }
        else{return true;}
        
        return false; 
    }
};
