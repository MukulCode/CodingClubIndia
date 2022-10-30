package Graphs;

import java.util.*;

public class primsAlgoOptimised {
     
    public static void primsOptimised(ArrayList<ArrayList<Node>> adj,int N){
        int key[]=new int[N];
        int parent[]=new int[N];
        boolean mstSet[]=new boolean[N];

        for(int i=0;i<N;i++){
            key[i]=Integer.MAX_VALUE;
        }

        key[0]=0;
        parent[0]=-1;

        PriorityQueue<Node> pq=new PriorityQueue<>(N,new Node());
        pq.add(new Node(key[0],0));

        for(int i=0;i<N-1;i++){
            int u=pq.poll().getV();
            mstSet[u]=true;

            for(Node it: adj.get(u)){
                if(mstSet[it.getV()]==false && it.getWeight()<key[it.getV()]){
                    key[it.getV()]=it.getWeight();
                    pq.add(new Node(it.getV(),key[it.getV()]));
                }
            }
        }

        for(int i=1;i<N;i++){
            System.out.println(parent[i] + " - "+ i);
        }
    }
}
