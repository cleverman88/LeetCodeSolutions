
class Solution {
//https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
public:
    bool isValidSerialization(string preorder) {
        
    
            string buf;                 // Have a buffer string
            stringstream ss(preorder);       // Insert the string into a stream

            vector<string> preorderArr; // Create vector to hold our words

            while(getline(ss, buf, ','))
                preorderArr.push_back(buf);
        
        int size = 0;
        
        for(auto x : preorderArr){
            size++;
        }
        
        if(size % 2 == 0){
            return false;
        }
        

        //stack<string> s;
        int count = 0;
        int negativeCount = 0;
        for(auto x : preorderArr){
            if(x != "#"){
                // s.push(x);
                // if(count > 0){
                //     count--;
                // }
                if(negativeCount > 0){
                    negativeCount--;
                }
                count++;
            }
            else if (x == "#"){
                // if(s.size() <= 0){
                    
                    if(negativeCount > 1){
                        return false;
                    }
                
                if(count > 0){
                        count--;
                    }
                else{negativeCount++;}
                    
                //}
                // else{
                //     s.pop();
                // }
            }    

           
            
        }
         //cout << count;
         if(negativeCount == 1){
             return true;
         }
            
            return false;
    }
    

        
        
        
        /*
        [9,3,4,#,#,1,#,#,2,#,6,#,#]
        
        []
        []
        []
        []
        []
        []
        []
        []
        []
        []
        
 
        
          9    1 look for 2
        (3,2)  2 look for 4
      (4,1) (#,6)  3 look for 6
  (#,#)(#,#)  (#,#)
        */
        
};
