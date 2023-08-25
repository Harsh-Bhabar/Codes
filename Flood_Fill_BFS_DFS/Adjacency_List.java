import java.util.ArrayList;
import java.util.List;

public class Graph {
    private int numVertices;
    private List<List<Integer>> adjacencyList;

    public Graph(int numVertices) {
        this.numVertices = numVertices;
        adjacencyList = new ArrayList<>();
        
        for (int i = 0; i < numVertices; i++) {
            adjacencyList.add(new ArrayList<>());
        }
    }

    public void addEdge(int source, int destination) {
        adjacencyList.get(source).add(destination);
        adjacencyList.get(destination).add(source); // For undirected graph
    }

    public List<Integer> getAdjacentVertices(int vertex) {
        return adjacencyList.get(vertex);
    }

    public static void main(String[] args) {
        int numVertices = 5;
        Graph graph = new Graph(numVertices);

        graph.addEdge(0, 1);
        graph.addEdge(0, 4);
        graph.addEdge(1, 2);
        graph.addEdge(1, 3);
        graph.addEdge(1, 4);
        graph.addEdge(2, 3);
        graph.addEdge(3, 4);

        for (int i = 0; i < numVertices; i++) {
            List<Integer> adjacentVertices = graph.getAdjacentVertices(i);
            System.out.print("Adjacent to vertex " + i + ": ");
            for (int vertex : adjacentVertices) {
                System.out.print(vertex + " ");
            }
            System.out.println();
        }
    }
}
