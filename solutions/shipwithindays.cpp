class Solution {
public:
   //https://leetcode.com/problems/capacity-to-ship-packages-within-d-days     
    string fit(vector<int> weights, int D, int size){
        int counter = 0;
        int cuts = 1;
        for(auto x : weights){
            if(counter + x <= size){
                counter+= x;
            }
            else{
                counter = x;
                cuts++;
            }
        }
        if(cuts > D)
            return "SMALL";
        if(cuts < D)
            return "BIG";
        
        
        return "BIG";
        
    }
    
    int shipWithinDays(vector<int>& weights, int D) {
        int lower = *max_element(weights.begin(), weights.end());
        int lower2 = lower;
        int upper = 0;
        for (auto& n : weights)
            upper += n;

        //Binary search
        while(lower < upper){
            int mid = lower + (upper - lower) / 2;
            string sol = fit(weights,D,mid);
            if(sol == "BIG")
                upper = mid;
            else if(sol == "SMALL")
                lower = mid+1;
            }
        
        return lower;
        }
    
};
