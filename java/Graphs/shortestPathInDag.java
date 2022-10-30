package Graphs;

import java.util.*;

public class shortestPathInDag {

    public static int[] findShortestPath(ArrayList<ArrayList<Pair>> adj, int V, int source) {
        int dist[] = new int[V];

        for (int i = 0; i < V; i++)
            dist[i] = Integer.MAX_VALUE;
        dist[source] = 0;

        Stack<Integer> s = new Stack<>();
        findtopoSort(adj, V, s);

        while (!s.isEmpty()) {
            int node = s.pop();

            if (dist[node] != Integer.MAX_VALUE) {
                for (Pair it : adj.get(node)) {
                    if (dist[node] + it.weight < dist[it.node]) {
                        dist[it.node] = dist[node] + it.weight;
                    }
                }
            }
        }
        return dist;
    }

    public static void findtopoSort(ArrayList<ArrayList<Pair>> adj, int V, Stack<Integer> s) {
        boolean vis[] = new boolean[V];

        for (int i = 0; i < V; i++) {
            if (vis[i] == false) {
                dfs(i, vis, s, adj);
            }
        }
    }

    public static void dfs(int node, boolean vis[], Stack<Integer> s, ArrayList<ArrayList<Pair>> adj) {
        vis[node] = true;
        for (Pair it : adj.get(node)) {
            if (vis[it.node] == false) {
                dfs(it.node, vis, s, adj);
            }
        }
        s.push(node);
    }

}

class Pair {
    int node;
    int weight;

    Pair(int node, int weight) {
        this.node = node;
        this.weight = weight;
    }
}
