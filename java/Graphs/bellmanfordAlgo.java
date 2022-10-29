package Graphs;

import java.util.*;

public class bellmanfordAlgo {
    void isNegativeCycle(ArrayList<Node> adj, int N, int source) {

        int dist[] = new int[N];

        for (int i = 0; i < N; i++) {
            dist[i] = 1000000;
        }
        dist[source] = 0;

        for (int i = 0; i < N - 1; i++) {
            for (Node node : adj) {
                if (dist[node.getU()] + node.getWeight() < dist[node.getV()]) {
                    dist[node.getV()] = dist[node.getU()] + node.getWeight();
                }
            }
        }

        boolean flag = false;
        for (Node node : adj) {
            if (dist[node.getU()] + node.getWeight() < dist[node.getV()]) {
                System.out.println("Graph contains negative cycle");
                flag = true;
                break;
            }
        }

        if (!flag) {
            for (int i = 0; i < N; i++) {
                System.out.println(i + " " + dist[i]);
            }
        }
    }

    public static void main(String args[]) {
        int n = 6;
        ArrayList<Node> adj = new ArrayList<Node>();

        adj.add(new Node(3, 2, 6));
        adj.add(new Node(5, 3, 1));
        adj.add(new Node(0, 1, 5));
        adj.add(new Node(1, 5, -3));
        adj.add(new Node(1, 2, -2));
        adj.add(new Node(3, 4, -2));
        adj.add(new Node(2, 4, 3));

        bellmanfordAlgo obj = new bellmanfordAlgo();
        obj.isNegativeCycle(adj, n, 0);

    }
}

class Node {
    private int u;
    private int v;
    private int weight;

    Node(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        weight = _w;
    }

    Node() {
    }

    int getV() {
        return v;
    }

    int getU() {
        return u;
    }

    int getWeight() {
        return weight;
    }

}
