#include <bits/stdc++.h>
using namespace std;
class Edge{
    public:
    
    int v,wt;
    Edge(int a,int b){
        v=a,wt=b;
    }
};

void addEdge(vector<vector<Edge>>&graph,int u,int v,int wt){
    graph[u].push_back(Edge(v,wt));
    graph[v].push_back(Edge(u,wt));
}

void display(vector<vector<Edge>>&graph){
    int n=graph.size();
    for(int i=0;i<n;i++){
        int siz=graph[i].size();
        cout<<i<<"->";
        for(int j=0;j<siz;j++){
            int v=graph[i][j].v;
            int wt=graph[i][j].wt;
            cout<<"("<<v<<","<<wt<<")";
        }
        cout<<endl;
    }
}
int findEdge(vector<vector<Edge>>&graph,int u,int vtx){
    int n=graph[u].size();
    for(int i=0;i<n;i++){
        if(graph[u][i].v==vtx)return i;
    }
    return -1;
}
void removeEdge(vector<vector<Edge>>&graph,int u,int v){

    int idx=findEdge(graph,u,v);
    graph[u].erase(graph[u].begin()+idx);

    int idx=findEdge(graph,v,u);
    graph[v].erase(graph[v].begin()+idx);
}
void removeVertex(vector<vector<Edge>>&graph,int v){
    int n=graph[v].size();
    for(int i=n-1;i>=0;i--){
        int va=graph[v][i].v;
        removeEdge(graph,v,va);
    }
}
int main(){
    int n=9;
    vector<vector<Edge>>gra(n,vector<Edge>());


    addEdge(gra,0,1,10);
    addEdge(gra,0,3,10);
    addEdge(gra,1,2,10);
    addEdge(gra,2,3,40);

    addEdge(gra,2,7,2);
    addEdge(gra,2,8,4);
    addEdge(gra,7,8,3);
    
    addEdge(gra,3,4,2);
    addEdge(gra,4,5,2);
    addEdge(gra,4,6,8);
    addEdge(gra,5,6,3);
    
    display(gra);
    return 0;
}