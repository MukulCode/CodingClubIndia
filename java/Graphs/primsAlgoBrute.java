package Graphs;

import java.util.*;

public class primsAlgoBrute {

    public static void primsBrute(ArrayList<ArrayList<Node>> adj, int N) {
        int key[] = new int[N];
        int parent[] = new int[N];
        boolean mstSet[] = new boolean[N];

        for (int i = 0; i < N; i++) {
            key[i] = Integer.MAX_VALUE;
        }
        key[0] = 0;
        parent[0] = -1;

        // Main for loop for N-1 edges and N vertex
        for (int i = 0; i < N - 1; i++) {

            int mini = Integer.MAX_VALUE;
            int u = 0;

            // for finding minimum value in the keys array for N-1 times
            for (int v = 0; v < N; v++) {
                if (mstSet[v] == false && key[v] < mini) {
                    mini = key[v];
                    u = v;
                }
            }

            mstSet[u] = true;

            // Iterating adjacent nodes of the min value node

            for (Node it : adj.get(u)) {
                if (mstSet[it.getV()] == false && it.getWeight() < key[it.getV()]) {
                    parent[it.getV()] = u;
                    key[it.getV()] = it.getWeight();
                }
            }
        }

        // printing the nodes along with their respective parent node which are present
        // in the Minimum spamming tree.
        for (int i = 0; i < N; i++) {
            System.out.println(parent[i] + "-" + i);
        }
    }
}
