//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char,string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        vector<string> sol(0);
        if(digits.size() == 0)
            return sol;
        solve(m , digits, 0, sol,"");
        
        return sol;
    }
    
    
    void solve(map<char,string> m, string digits, int index, vector<string> &solution, string soFar){
        if(index == digits.size()){
            solution.push_back(soFar);
            return;
        }
        string temp = soFar;
        for(auto x : m[digits[index]]){
            temp += x;
            solve(m,digits,index+1,solution,temp);
            temp = soFar;
        }
        
        return;
    }
    
    
};
