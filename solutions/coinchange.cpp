#include <limits>
//https://leetcode.com/problems/coin-change/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }
        bool allbigger = true;
        for(int coin: coins){
            if(coin <= amount){
                allbigger = false;
            }
        }
        
        if(allbigger){
            return -1;
        }
        int cache[amount+1];
        for(int n = 0; n <= amount; n++){
            cache[n] = 10000;
        }
        
        cache[0] = 0;
        for(int i = 1 ; i <= amount; i++){
            int minimum = 10000000;
            for(int c : coins){
                if(i - c == 0){
                    cache[i] = 1;
                    break;
                }
                
                else if(i < c){
                    continue;
                }
                
                else if(i - c > 0){
                    if(cache[i - c] < minimum){
                        minimum = cache[i - c];
                        cache[i] = 1 + cache[i-c];
                    }
                }
            }   
        }
        
        if(cache[amount] >= 10000){
            return -1;
        }
        return cache[amount];
        
        
    }

};
