class Solution {
//https://leetcode.com/problems/monotone-increasing-digits/
public:
    int monotoneIncreasingDigits(int N) {
        
        return stoi(solution(to_string(N)));
    }
    
    bool isMonotone(string val){
        for(int i = 0; i < val.size()-1; i++){
            if((val[i]-'a') > (val[i+1]-'a')) return false;
        }
        return true;
    }
    
    string solution(string val){
        string s;
        for(int i = 0 ; i < val.size()-1; i++){
            if((val[i]-'0') > (val[i+1]-'0')){
                int temp = val[i]-'0';
                temp--;
                string temp2 = to_string(temp);
                s.append(temp2);
                if(!isMonotone(s)){
                    s = solution(s);
                }
                
                int loop = val.size() - s.size();
                for(int j = 0 ; j < loop; j++){
                    s.append("9");
                }
                return s;
            }
            else{
                s += val[i];
            }
        }
        s+= val[val.size()-1];
        return s;
    }
};
