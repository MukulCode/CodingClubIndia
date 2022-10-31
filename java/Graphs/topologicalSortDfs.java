package Graphs;

import java.util.*;

public class topologicalSortDfs {

    ArrayList<Integer> topologicalSort(ArrayList<ArrayList<Integer>> adj, int N) {
        int[] vis = new int[N];
        Stack<Integer> s = new Stack<>();

        for (int i = 0; i < N; i++) {
            if (vis[i] == 0) {
                dfs(i, vis, s, adj);
            }
        }
        ArrayList<Integer> ans = new ArrayList<>();

        while (!s.isEmpty()) {
            ans.add(s.pop());
        }
        return ans;
    }

    public void dfs(int node, int[] vis, Stack<Integer> s, ArrayList<ArrayList<Integer>> adj) {

        vis[node] = 1;
        for (Integer it : adj.get(node)) {
            if (vis[it] == 0) {
                dfs(it, vis, s, adj);
            }
        }
        s.push(node);
    }

}