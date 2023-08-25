package Flood_Fill_BFS_DFS;
import java.util.*;

public class Number_Of_Provinces_BFS {
	
}

class Solution {

    public void BFS(int i, ArrayList<ArrayList<Integer>> adj, boolean[] visited){
        Queue<Integer> q = new LinkedList<>();
        q.offer(i);
        while(!q.isEmpty()){
            int curr = q.poll();
            for(int neighbor: adj.get(curr)){
                if(visited[neighbor] == false){
                    visited[neighbor] = true;
                    q.offer(neighbor);
                }
            }
        }
    }

    public int findCircleNum(int[][] isConnected) {
        
        int V = isConnected.length;
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

        for(int i=0; i<V; i++){
            adj.add(new ArrayList<>());
        }
        
        for (int i = 0; i < isConnected.length; i++) {
            for (int j = 0; j < isConnected[i].length; j++) {
                if (i != j && isConnected[i][j] == 1) {
                    adj.get(i).add(j);
                    adj.get(j).add(i);
                }
            }
        }

        boolean[] visited = new boolean[V];

        int cnt = 0 ;

        for(int i=0; i<V; i++){
            if(!visited[i]){
                cnt++;
                BFS(i, adj, visited);
            }
        }

        System.out.println(adj);
 
        return cnt;
    }
}
