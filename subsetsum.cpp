//https://leetcode.com/problems/partition-equal-subset-sum/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int summation = sum(nums);
    
        if(summation % 2 != 0){
            return false;
        }
        else{
            //return solve(nums,(summation/2));
            return solution2(nums,(summation/2));
            
        }
        return true;
    }
    
    bool solve(vector<int>& nums, int value){
        //[2,2,3,5] val = 6
            //[2,3,5] val = 4   
                //[3,5] val = 2 //false   //[2,5] val = 1 //false
                    //[5] val = -1  //[3] val = -3  //false //false
        
        if(value == 0){
            return true;
        }
        
        if(value < 0){
            return false;
        }
        
        
        else{
            vector<int> temp = nums;
            int temp2 = value;
            for(int i = 0; i < nums.size(); i++){
                // print_vector(nums);
                // cout << "\nRemoving value: " << nums[i] << " from "<< value;
                value = value-nums[i];
                nums.erase(nums.begin()+i);
                //cout << "\n";
                if(solve(nums, value)){
                    return true;
                }
                nums = temp;
                value = temp2;
            }
        }
        return false;
    }
    
    void print_vector(std::vector<int> const &input){
	std::for_each(input.begin(),
				input.end(),
				[](const auto &e) {
					std::cout << e << " ";
				});
    }

    
    
    bool solution2 (vector<int> &nums,int target){
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(auto num : nums) 
        for(int i = target; i >= num; i--)
            dp[i] = dp[i] || dp[i - num];
        
        return dp[target];
        
    }
    
    int sum(vector<int> &vector){
        int sum_of_elems = 0;
        for (auto& n : vector){
            sum_of_elems += n;
        }
        
        return sum_of_elems;
    }
};
