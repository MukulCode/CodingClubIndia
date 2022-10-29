#include<iostream>
#include<list>
#define NIL -1
using namespace std;
class Graph{
    int v;
    list<int> *adj; // Dynamic array of adjacency lists
    bool isBCUtil(int v,bool vis[],int disc[],int low[],int par[]);
    public:
        Graph(int v);
        void AddEdge(int v,int w);
        bool isBC();
};
Graph::Graph(int v){
    this->v=v;
    adj=new list<int>[v];
}
void Graph::AddEdge(int v,int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}
bool Graph::isBCUtil(int u,bool vis[],int disc[],int low[],int par[]){
    static int time=0;
    // Count of children in dfs tree
    int child=0;
    // Mark current node visited
    vis[u]=true;
    // Initialise discovery time and low value
    disc[u]=low[u]=++time;
    for(auto x:adj[u]){
        // if x is not visited yet then make it a child of u in dfs tree and recur for it
        if(!vis[x]){
            child++;
            par[x]=u;
            if(isBCUtil(x,vis,disc,low,par)) return true;
            low[u]=min(low[u],low[x]);
            // check if subtree rooted with x has a connection to one of ancestors of u
            if(par[u]!=-1 and low[x]>=disc[u]) return true;
               // if u is root of dfs tree and has two or more children
            if(par[u]==-1 and child>1) return true;
        }
        else if(x!=par[u])
            low[u]=min(low[u],disc[x]);
    }
 
    return false;
}
bool Graph::isBC(){
    bool *vis=new bool[v];
    int *disc=new int[v];
    int  *low=new int[v];
    int *par=new int[v];
    for(int i=0;i<v;i++) {
        par[i]=-1;
        vis[i]=false;
    }
    if(isBCUtil(0,vis,disc,low,par)) return false;
    for(int i=0;i<v;i++){
        if(vis[i]==false) return false;
    }
    return true;
}
int main(){
    // create graph over here and call respective functions
}