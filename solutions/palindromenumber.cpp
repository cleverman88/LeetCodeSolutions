//https://leetcode.com/problems/palindrome-number
//Without converting the number to a string

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        if(x == 0){
            return true;
        }
        double val = 0;
        for(int k=0; k <= floor(log10(x));k++){
            val += ((int)(floor(x/pow(10,k))) % 10) * pow(10,floor(log10(x))-k);   
       } 
        return val == x;
    }
};
