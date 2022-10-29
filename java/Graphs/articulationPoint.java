package Graphs;

import java.util.*;

public class articulationPoint {

    private static void findArticulationPoints(ArrayList<ArrayList<Integer>> adj, int N) {

        boolean vis[] = new boolean[N];
        int time[] = new int[N];
        int low[] = new int[N];
        int timer = 0;

        boolean articulationPoints[] = new boolean[N];

        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, vis, time, low, timer, articulationPoints);
            }
        }
        for (int i = 0; i < N; i++) {
            if (articulationPoints[i] == true)
                System.out.println(i);
        }
    }

    private static void dfs(int node, int par, ArrayList<ArrayList<Integer>> adj, boolean vis[], int time[], int low[], int timer, boolean[] articulationPoints) {

        vis[node] = true;
        time[node] = low[node] = timer++;
        int child = 0;

        for (Integer it : adj.get(node)) {
            if (it == par)
                continue;

            if (!vis[it]) {

                dfs(it, node, adj, vis, time, low, timer, articulationPoints);
                low[node] = Math.min(low[node], low[it]);

                if (low[it] >= time[node] && par != -1) {
                    articulationPoints[node] = true;
                }
                child++;
            } else {
                low[node] = Math.min(low[node], time[it]);
            }
        }
        if (par != -1 && child > 1)
            articulationPoints[node] = true;
    }

    public static void main(String args[]) {
        int n = 5;
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();

        for (int i = 0; i < n; i++)
            adj.add(new ArrayList<Integer>());

        adj.get(0).add(1);
        adj.get(1).add(0);

        adj.get(0).add(2);
        adj.get(2).add(0);

        adj.get(1).add(2);
        adj.get(2).add(1);

        adj.get(1).add(3);
        adj.get(3).add(1);

        adj.get(3).add(4);
        adj.get(4).add(3);

        articulationPoint obj = new articulationPoint();
        obj.findArticulationPoints(adj, n);

    }
}
