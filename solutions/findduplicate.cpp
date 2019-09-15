//https://leetcode.com/problems/find-the-duplicate-number/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hare = nums[0];
        int tort = nums[0];
        
        do{
            hare = nums[hare];
            hare = nums[hare];
            tort = nums[tort];
        }
        while(hare != tort);
        
        int tort2 = nums[0];
        
        while(tort2 != tort){
            tort2 = nums[tort2];
            tort = nums[tort];
        }
        
        return tort;
            
    }
};
