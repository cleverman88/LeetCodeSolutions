class Solution {
//https://leetcode.com/problems/permutation-in-string/
public:
    bool checkInclusion(string s1, string s2) {
        int si = s1.size();
        int si2 = s2.size();
        if(si > si2){
            return false;
        }

                
        map<char, int> gquiz1; 

        
        for(auto x : s1){
            gquiz1[x]++;

        }
        
        map<char, int> temp;
        for(int j = 0; j < si; j++){
                temp[s2[j]]++;
        }
        
        for(int i = 0; i <= si2-si; i++){
            
            bool success = true;
            for ( const auto &myPair : temp ) {
                 if(temp[myPair.first] != gquiz1[myPair.first]){
                     success = false;
                     break;
                 }
            }
            
            if(success){
                return true;
            }
            temp[s2[i]]--;
            temp[s2[si+i]]++;
        }
        
        return false;
    }
};
