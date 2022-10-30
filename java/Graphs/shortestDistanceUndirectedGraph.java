package Graphs;

import java.util.*;

public class shortestDistanceUndirectedGraph {

    public static int[] findDist(ArrayList<ArrayList<Integer>> adj, int V, int source) {

        int dist[] = new int[V];
        Queue<Integer> q = new LinkedList<>();

        for (int i = 0; i < V; i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        dist[source] = 0;
        q.add(source);

        while (!q.isEmpty()) {
            int node = q.poll();

            for (Integer it : adj.get(node)) {
                dist[it] = Math.min(dist[node] + 1, dist[it]);
                q.add(it);
            }
        }
        return dist;
    }
}
