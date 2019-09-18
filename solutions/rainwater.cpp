//https://leetcode.com/problems/trapping-rain-water
class Solution {
public:
    int trap(vector<int>& height) {
     
        /*
        
            \          /
              \   /\  /  
                \/  \/
        
        1-0-2
        2-1-0-1-3
        3-1-2
        */
        bool carry = true;
        int solution = 0;
        if(height.size() < 3){
            return solution;
        }
        while(carry){
            int m = 0;
            carry = false;
            vector<pair<int,int>> ranges(0);
            vector<int> sol(0);
            for(int i =0 ; i < height.size()-1; i++){
                if(height[i] > m){
                    m = height[i];
                    int val = solve(height,i);
                    ranges.push_back({i,val});
                    i = val-1;
                    m = 0;
                }
            }

            for(auto x : ranges){
                //cout << x.first << " " << x.second << endl;
                if(x.second == height.size()-1 && height[x.second] < height[x.first]){
                    vector<int> height2(0);
                    int m = 0;
                    for(int i = x.first+1; i < height.size();i++){
                        m = max(height[i],m);   
                    }
                    height2.push_back(m);
                    for(int i = x.first+1; i < height.size();i++){
                        height2.push_back(height[i]);
                    }
                    height = height2;
                    carry = true;
                    break;
                }
                int total = ((x.second - x.first-1) * height[x.first]);
                for(int i = x.first+1; i < x.second; i++){
                    total = total - height[i]; 
                }
                solution += total;
            }
        }
        
        return solution;
    }
    
    
    int solve(vector<int> &height, int &start){
        for(int i = start+1; i < height.size(); i++){
            if(height[start] <= height[i]){
                return i;
            }   
        }
        
        return height.size()-1;
        
    }
};
