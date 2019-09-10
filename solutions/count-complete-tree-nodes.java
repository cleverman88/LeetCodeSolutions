/**https://leetcode.com/problems/count-complete-tree-nodes
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int countNodes(TreeNode root) {
        TreeNode temp = root;
        int depth = 0;
        if(temp == null) return 0;
        while(true){
            if(temp.left != null){
                temp = temp.left;
                depth++;
                continue;
            }
            break;
        }
        
        return (power(2,depth)-1) + solve(root,depth,0);
    }
    
    
    int solve(TreeNode node, int totalDepth, int depth){
        if(node.right == null && node.left != null){
            return 1;
        }
        else if(node.right == null && node.left == null){
            if(depth == totalDepth-1) return 0;
            return 1;
        }
        
        return solve(node.left,totalDepth,depth+1) + solve(node.right,totalDepth,depth+1);
    }
    
    int power(int a, int b){
        if(b == 0) return 1;
        int so = 1;
        for(int i = 0; i < b; i++){
            so = so*a;
        }
        
        return so;
    }
}
