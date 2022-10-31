package Graphs;
import java.util.*;

public class topologicalSortBfs {

    public int[] topoSort(ArrayList<ArrayList<Integer>> adj, int N) {

        int topo[] = new int[N];
        int indegree[] = new int[N];

        for (int i = 0; i < N; i++) {
            for (Integer it : adj.get(i)) {
                indegree[it]++;
            }
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                q.add(i);
            }
        }

        int ind = 0;
        while (!q.isEmpty()) {
            Integer node = q.poll();
            topo[ind++]=node;
            indegree[node]--;
            if (indegree[node] == 0) {
                q.add(node);
            }
        }

        return topo;
    }

}
