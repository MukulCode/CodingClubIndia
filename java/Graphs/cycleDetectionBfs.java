package Graphs;

import java.util.*;

public class cycleDetectionBfs {

    public boolean isCycle(int V, ArrayList<ArrayList<Integer>> adj) {

        boolean vis[] = new boolean[V + 1];
        boolean res = false;

        for (int i = 1; i <= V; i++) {
            if (vis[i] == false) {
                res = isCycleDetected(i, vis, adj);
            }
        }

        return res;
    }

    public boolean isCycleDetected(int n, boolean vis[], ArrayList<ArrayList<Integer>> adj) {

        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(n, -1));
        vis[n] = true;

        while (!q.isEmpty()) {
            int node = q.peek().node;
            int par = q.peek().prev;
            q.remove();

            for (Integer it : adj.get(node)) {
                if (vis[it] == false) {
                    q.add(new Pair(it, node));
                    vis[it] = true;
                } else if (it != par) {
                    return true;
                }
            }
        }
        return false;
    }
}

class Pair {
    int node, prev;

    public Pair(int node, int prev) {
        this.node = node;
        this.prev = prev;
    }
}
