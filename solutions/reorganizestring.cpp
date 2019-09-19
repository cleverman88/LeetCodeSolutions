//https://leetcode.com/problems/reorganize-string/submissions/
class Solution {
public:
    string reorganizeString(string S) {
        priority_queue<pair<int,char>> q;
        unordered_map<char,int> m;
        
        if(S.size() == 0) return "";
        for(auto x : S){
            m[x]++;
        }
        
        for(auto &x : m){
            //cout << x.first << " " << x.second << endl;
            q.push({x.second,x.first});
        }
        char prev = q.top().second;
        string sol;
        while(!q.empty()) {
            pair<int,char> f = q.top();
            q.pop();
            sol += f.second;
            if(sol.size() > 2){
                if(sol[sol.size()-2] == sol[sol.size()-1]) return "";
            }
            f.first = f.first-1;
            if(q.empty()){
                if(f.first > 0){
                    return "";
                }
                return sol;
            }
            pair<int,char> s = q.top();
            q.pop();
            sol += s.second;
            if(sol.size() > 2){
                if(sol[sol.size()-2] == sol[sol.size()-1]) return "";
            }
            s.first = s.first-1;
            
            if(f.first > 0){
                q.push(f);
            }
            
            if(s.first > 0){
                q.push(s);
            }
    }
        return sol;
    }
};
