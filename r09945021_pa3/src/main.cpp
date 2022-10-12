#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include "Cyclebreak.h"

void help_message(){
    cout << "usage: cb <input file name> <output file name>" << endl;
}

int main(int argc, char* argv[]){
    if (argc != 3){
        help_message();
        return 0;
    }
    char buffer[10];
    fstream fin(argv[1]);
    fstream fout;
    fout.open(argv[2], ios::out);
    
    char dir;
    int V_num;
    int E_num;
    fin >> dir;
    fin >> V_num;
    fin >> E_num;
    
    int u, v, weight;
    Graph G(V_num, E_num);
    while(fin >> u >> v >> weight){
        G.Addedge(u, v, weight);
    }
    vector<Edge> del = G.Kruskal(dir);
    
    if (dir == 'u'){
        fout << G.GetCost() << endl;
        for (int i=0; i<del.size(); i++){
            fout << del[i].u << " " << del[i].v << " " <<  del[i].weight << endl;
        }
    }
    
    else{
        vector<Edge> final_del;
        for (int i=0; i<del.size(); i++){
            int u = del[i].u;
            int v = del[i].v;
            int weight = del[i].weight;
            
            
            if (weight<0)
                final_del.push_back(del[i]);
            else{
                
                G.MST_AddEdge(u, v, weight);
                
                if(G.CheckCycle()){
                    final_del.push_back(del[i]);
                    G.MST_RemoveEdge(u);
                }
                else
                    G.decrease_cost(del[i].weight);
            }
        }
        
        fout << G.GetCost() << endl;
        for (int i=0; i<final_del.size(); i++)
            fout << final_del[i].u << " " << final_del[i].v << " " << final_del[i].weight << endl;
          
    }
    fin.close();
    fout.close();
}
