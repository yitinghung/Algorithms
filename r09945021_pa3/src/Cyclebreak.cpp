#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#include "Cyclebreak.h"


bool CompareEdge(const Edge &edge1, const Edge &edge2){
    return edge1.weight > edge2.weight;
}


void Graph::Addedge(int u, int v, int weight){
    Edge E;
    E.u = u;
    E.v = v;
    E.weight = weight;
    Edges.push_back(E);
}

void Graph::MST_AddEdge(int u, int v, int weight){
    AdjNode N;
    N.v = v;
    N.weight = weight;
    MST[u].push_back(N);
}

void Graph::MST_RemoveEdge(int u){
    MST[u].pop_back();
};

vector<Edge> Graph::GetEdges(){
    return Edges;
}

int Graph::GetCost(){
    return Cost;
}
void Graph::decrease_cost(int weight){
    Cost -= weight;
}

bool Graph::CheckCycle(){
    vector<char> color(V_num, 'W');
    for (int i=0; i<V_num; i++){
        if(color[i] == 'W' && CheckCycle_DFS(&color, i))
            return true;
    }
    return false;
}

bool Graph::CheckCycle_DFS(vector<char>* color, int u){
    (*color)[u] = 'G';
    for (int i=0; i<MST[u].size(); i++){
        int v = MST[u][i].v;
        if ((*color)[v] == 'G')
            return true;
        if ((*color)[v] == 'W' && CheckCycle_DFS(color, v))
            return true;
    }
    (*color)[u] = 'B';
    return false;
}

int FindSet(int* Set, int vertex){
    if (Set[vertex]<0){
        return vertex;
    }
    int root;
    for(root=vertex; Set[root]>=0; root=Set[root]);
    while(Set[vertex]>=0){
        int parent = Set[vertex];
        Set[vertex] = root;
        vertex = parent;
    }
    return root;
}

void Union(int* Set, int u, int v){
    int root_u = FindSet(Set, u);
    int root_v = FindSet(Set, v);
    if(Set[root_u]>Set[root_v]){
        Set[root_v] += Set[root_u];
        Set[root_u] = root_v;
    }
    else{
        Set[root_u] += Set[root_v];
        Set[root_v] = root_u;
    }
}

vector<Edge> Graph::Kruskal(char dir){
    vector<Edge> del_edge;
    //vector<AdjNode> emptyAdjList[V_num];
    //MST = emptyAdjList;
    
    int Set[V_num];
    for (int i=0; i<V_num; i++)
        Set[i] = -1;
    
    sort(Edges.begin(), Edges.end(), CompareEdge);
    
    for (int i=0; i<E_num; i++){
        if (FindSet(Set, Edges[i].u) != FindSet(Set, Edges[i].v)){
            Union(Set, Edges[i].u, Edges[i].v);
            
            if(dir == 'd')
                MST_AddEdge(Edges[i].u, Edges[i].v, Edges[i].weight);
             
        }
        else{
            del_edge.push_back(Edges[i]);
            Cost += Edges[i].weight;
        }
       
    }
    return del_edge;
}

