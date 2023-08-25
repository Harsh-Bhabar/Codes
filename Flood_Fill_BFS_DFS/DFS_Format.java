package Flood_Fill_BFS_DFS;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class DFS_Format {
	public void DFS(int i, ArrayList<ArrayList<Integer>> adj, Map<Integer, Boolean> visited, ArrayList<Integer> ans){
                        
        visited.put(i, true);
        ans.add(i);
        
        for(int neighbor: adj.get(i)){
            if(visited.containsKey(neighbor) == false){
                DFS(neighbor, adj, visited, ans);
            }
        }
    }
    
    public ArrayList<Integer> dfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        
        ArrayList<Integer> ans = new ArrayList<>();
        Map<Integer, Boolean> visited = new HashMap<>();
        
        if(V == 0){
            return ans;
        }
        
        for(int i=0; i<V; i++){
            if(!visited.containsKey(i)){
                DFS(i, adj, visited, ans);
            }
        }
        
        return ans;
    }
}
