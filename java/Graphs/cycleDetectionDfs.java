package Graphs;

import java.util.*;

public class cycleDetectionDfs {

    public boolean isCyclic(int V, ArrayList<ArrayList<Integer>> adj) {
        boolean vis[] = new boolean[V + 1];

        for (int i = 1; i <= V + 1; i++) {
            if (vis[i] == false) {
                if (isCycleDetected(i, -1, vis, adj))
                    return true;
            }
        }

        return false;
    }

    public boolean isCycleDetected(int n, int parent, boolean vis[], ArrayList<ArrayList<Integer>> adj) {
        vis[n] = true;
        for (Integer it : adj.get(n)) {
            if (vis[it] == false) {
                if (isCycleDetected(it, n, vis, adj))
                    return true;
            } else if (it != parent)
                return true;
        }
        return false;
    }

}
