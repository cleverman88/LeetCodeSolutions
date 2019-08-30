//https://leetcode.com/problems/delete-operation-for-two-strings/

class Solution {

public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        int array[size1+1][size2+1];
        
        for(int i = 0; i <= size1; i++){
            for(int j = 0; j <= size2; j++){
               array[i][j] = 0;
            }
        }
        
        for(int i = 1; i <= size1; i++){
            for(int j = 1; j <= size2; j++){
                if(word1[i-1] == word2[j-1]){
                    array[i][j] = array[i-1][j-1] + 1; 
                }
                
                else{
                    array[i][j] = max(array[i-1][j], array[i][j-1]);
                }
            }
        }
        
        
        return (size1 - array[size1][size2] + size2 - array[size1][size2]);
    }

};
