#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct AdjNode{
    int v;
    int weight;
};

bool CheckCycle(){
    vector<char> color(V_num, 'W');
    for (int i=0; i<V_num; i++){
        if(color[i] == 'W' && CheckCycle_DFS(&color, i))
            return true;
    }
    return false;
}

bool CheckCycle_DFS(vector<char>* color, int u){
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


int main(int argc, char* argv[]){
    char buffer[10];
    fstream fin(argv[1]);
    int V_num = 100;
    vector<AdjNode> AdjList[V_num];
    int u, v, weight;
    AdjNode E;
    while(fin >> u >> v >> weight){
        E.v = v;
        E.weight = weight;
        AdjList[u].push_back(E);
    }
    for(int i=0; i<V_num; i++){
        for(int j=0; j<AdjList[i].size(); i++){
            cout << AdjList[i][j].v
        }
    }
    return 0;
}
