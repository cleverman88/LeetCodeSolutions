/**https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        ArrayList<Tuple> sol = new ArrayList<Tuple>();
        sol = label(root,0,sol,0);
        
        Comparator<Tuple> compareByO = (Tuple o1, Tuple o2) -> o1.compareTo(o2);
        Collections.sort(sol, compareByO);
        
        ArrayList<ArrayList<Integer>> solution = new ArrayList<ArrayList<Integer>>();
        int start = sol.get(0).o;
        
        ArrayList<Integer> newArr = new ArrayList<Integer>();
        for(Tuple t : sol){
            if(t.o != start){
                solution.add(newArr);
                newArr = new ArrayList<Integer>();
                newArr.add(t.node.val);
                start = t.o;
            }
            else{
                newArr.add(t.node.val);
            }
        }
        solution.add(newArr);
        

        return (List)solution;
    }
    
    
    ArrayList<Tuple> label(TreeNode root, int o, ArrayList<Tuple> sol,Integer depth){
        if(!find(sol,root))
            sol.add(new Tuple(root, o,depth));
        
        if(root.left != null){
            label(root.left, o-1,sol,depth+1);
        }
        
        if(root.right != null){
            label(root.right, o+1,sol,depth+1);
        }
        
        return sol;
    }
    
    
    boolean find(ArrayList<Tuple> sol, TreeNode node){
        for(Tuple t : sol){
            if(t.node == node){
                return true;
            }
        }
        return false;
    }
    
    
    
    public class Tuple implements Comparable<Tuple>{
        TreeNode node;
        Integer o;
        Integer depth;
        public Tuple(TreeNode node, int o, Integer depth){
            this.o = o;
            this.node = node;
            this.depth = depth;
        }
        
        public int compareTo(Tuple o2) {
            Tuple p2 = (Tuple)o2;
            if(this.getO().equals(p2.getO())) {
                if(this.depth.equals(p2.depth)){
                    Integer f = new Integer(this.node.val);
                    Integer s = new Integer(p2.node.val);
                    
                    return f.compareTo(s);
                }
                return this.depth.compareTo(p2.depth);
            }
            return this.getO().compareTo(p2.getO());
        }
        
        Integer getO(){
            return o;
        }
        String print(){
            return "Node: "+ node.val +" Orientation: "+o+ " Depth: "+depth;
        }
    }
}
