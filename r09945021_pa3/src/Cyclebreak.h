#include <iostream>
#include <vector>
using namespace std;

struct Edge{
    int u;
    int v;
    int weight;
};

struct AdjNode{
    int v;
    int weight;
};

class Graph{
private:
    int V_num;
    int E_num;
    int Cost;
    vector<Edge> Edges;
    vector<AdjNode> *MST;
public:
    Graph(int V, int E){
        V_num = V;
        E_num = E;
        MST = new vector<AdjNode>[V_num];
    }
    ~Graph(){
        delete[] MST;
    };
    void Addedge(int, int, int);
    void MST_AddEdge(int, int, int);
    void MST_RemoveEdge(int);
    vector<Edge> GetEdges();
    int GetCost();
    void decrease_cost(int);
    vector<Edge> Kruskal(char dir);
    bool CheckCycle();
    bool CheckCycle_DFS(vector<char>*, int);
};
