package Flood_Fill_BFS_DFS;
import java.util.*;

public class BFS_Format {

	public ArrayList<Integer> bfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        
        ArrayList<Integer> ans = new ArrayList<>();
        
        if(V == 0){
            return ans;
        }
        
        LinkedList<Integer> q = new LinkedList<>();
        Map<Integer, Boolean> visited = new HashMap<>();
        
        q.offer(0);
        visited.put(0, true);
        
        while(!q.isEmpty()){
            int curr = q.poll();
            ans.add(curr);
            
            for(int neighbor : adj.get(curr)){
                if( visited.containsKey(neighbor) == false
                    || visited.get(neighbor) == false){
                    q.offer(neighbor);
                    visited.put(neighbor, true);
                }
            }
        }
         
        return ans;
    }

}
