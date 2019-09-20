class Solution {
//https://leetcode.com/problems/longest-mountain-in-array/
public:
    int longestMountain(vector<int>& A) {
        int counter = 0;
        int best = 0;
        if(A.size() < 3){
            return best;
        }
        for(int i = 0; i < A.size()-1; i++){
            if(A[i] < A[i+1]){
                counter++;
            }
            else if(counter >= 1){
                pair<int,int> val = decreasing(i,counter,A);
                if(val.first == counter) val.first = 0;
                best = max(val.first,best);
                i = val.second;
                counter = 0;    
            }
        }
        return best == 0 ? 0 : best+1;
    }
    
    
    pair<int,int> decreasing(int index,int counter, vector<int> &A){
        for(int i = index; i < A.size()-1;i++){
            if(A[i] > A[i+1]){
                counter++;
            }
            else{
                return {counter,i-1};
            }
        }
        return {counter,A.size()-2};
    }
};
