//https://leetcode.com/problems/divisor-game

class Solution {
public:
    bool divisorGame(int N) {
        int cache[N] = { 0 };
        if(N == 1){
            return false;
        }
        return findDivisorGameBottomUp(N, cache);
    }
    
    
    bool findDivisorGameBottomUp(int N, int cache[]) {
        cache[0] = -1;
        cache[1] = 1;
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < i+1; j++) {
                if ((i+1) % j == 0) {
                    if (cache[i - j] == -1) {
                        cache[i] = 1;
                        break;
                        
                    } else if (cache[i - j] == 1){
                        cache[i] = -1;
                    }
                }
            }
        }
        
        return (cache[N-1] == 1);
    }
};
