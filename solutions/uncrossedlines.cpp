class Solution {
//https://leetcode.com/problems/uncrossed-lines/
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B){
        int size1 = A.size();
        int size2 = B.size();
        int array[size1+1][size2+1];
        
        for(int i = 0; i <= size1; i++){
            for(int j = 0; j <= size2; j++){
               array[i][j] = 0;
            }
        }
        
        for(int i = 1; i <= size1; i++){
            for(int j = 1; j <= size2; j++){
                if(A[i-1] == B[j-1]){
                    array[i][j] = array[i-1][j-1] + 1; 
                }
                
                else{
                    array[i][j] = max(array[i-1][j], array[i][j-1]);
                }
            }
        }
        
        
        return array[size1][size2];
    }       
    
    int maxUncrossedLines2(vector<int>& A, vector<int>& B) {
        vector<int> adj[A.size()];
        int connections = 0;
        for(int i = 0; i < A.size(); i++){
            for(int j = 0 ; j < B.size(); j++){
                if(A[i] == B[j]) {
                    addNode(adj,i,j);
                    connections++;
                }
            }
            
        }
        
        
      
        pair<int,int> val = findNextBiggest(adj, A);
        int k = 0;
    
        
        while(val.first != -1){
            
            adj[val.first].erase(remove(adj[val.first].begin(), adj[val.first].end(), val.second),adj[val.first].end());
            connections--;
            k = 0;
            
            val = findNextBiggest(adj, A);
        }
            for(auto x : adj){
                cout << "Node "<< k << " is connected to "; 
                for(auto y : x){
                    cout << y << " ";
                }
                k++;
                cout << endl;
            }
        return connections;
        
        
    }
    
    
    
    void addNode(vector<int> adj[], int first, int second){
        adj[first].push_back(second);
    }
    
    pair<int, int> findNextBiggest(vector<int> adj[], vector<int> A) {
        
        int maxS = -1;
        int maxE = -1;
        int maxConnections = 0;
        
        for (int i = 0; i < A.size(); i ++) {
            for (int j = 0; j < adj[i].size(); j++) {
                int tempC = sizeOfCrossover(adj, i, adj[i][j], A) ;
                if (tempC > maxConnections) {
                    maxConnections = tempC;
                    maxS = i;
                    maxE = adj[i][j];
                }
            }
        }
        return {maxS, maxE};
    }
    
    int sizeOfCrossover(vector<int> adj[], int start, int end,vector<int> A){
        int count = 0;
        for (int i = 0; i < A.size(); i ++) {
            for (int j = 0; j < adj[i].size(); j++) {
                if (!(start == i && end == adj[i][j]) && crosses(start, end, i, adj[i][j])) {
                    count ++;
                }

            }
        }
        return count;
    }
    
    bool crosses(int start1, int end1, int start2, int end2) {
        if (start1 == start2 && end1 == end2) {
            return false;
        } else if (start1 == start2 || end1 == end2) {
            return true;
        } else if (start1 > start2) {
            return end1 < end2;
        } else if (start1 < start2){
            return end1 > end2;
        } else {
            return false;
        }
    }
};
