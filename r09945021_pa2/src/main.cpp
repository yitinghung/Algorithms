// **************************************************************************
//  File       [main.cpp]
//  Author     [Yi-Ting Hung]
//  Synopsis   [The main program of 2021 spring Algorithm PA2]
// **************************************************************************

#include <iostream>
#include <fstream>

using namespace std;

void help_message(){
    cout << "usage: mps <input file name> <output file name>" << endl;
}

int MPS(int data[], int i, int j, int **M, int **C){
    if (M[i][j] != 0)
        return M[i][j];
    if (i == j){
        return M[i][j] = 0;
    }
    if (i < j){
        int k = data[j];
        if (k<i || k>j){   //case 1
            C[i][j] = 1;
            return M[i][j] = MPS(data, i, j-1, M, C);
        }
        else if (k == i){  //case 2
            C[i][j] = 2;
            return M[i][j] = MPS(data, i+1, j-1, M, C)+1;
        }
        else{
            int a = max(MPS(data, i, j-1, M, C), MPS(data, i, k-1, M, C)+1+MPS(data, k+1, j-1, M, C));
            if (a > MPS(data, i, j-1, M, C))
                C[i][j] = 3;  //case 3
            return M[i][j] = a;
        }
    }
    return M[i][j];
}

int n=0;  //global variable (because of recursion)
void findchord(int data[], int i, int j, int **M, int **C, int **chord){
    while(j>i){
        int k = data[j];
        if (C[i][j] == 3){
            findchord(data, k+1, j-1, M, C, chord);
            chord[n][0] = k;
            chord[n++][1] = j;
            j = k-1;
        }
        else if (C[i][j] == 2){
            findchord(data, i+1, j-1, M, C, chord);
            chord[n][0] = k;
            chord[n++][1] = j;
            j = i-1;
        }
        else
            j--;
    }
}

int main(int argc, char* argv[]){
    if (argc != 3){
        help_message();
        return 0;
    }
    
    char buffer[100];
    fstream fin(argv[1]);
    fstream fout;
    fout.open(argv[2], ios::out);
    int num;  //num = 2N
    fin >> num;
    int node1, node2;
    int data[num];
    //cout << "Reading Data..." << endl;
    while (fin >> node1 >> node2){
        data[node1] = node2;
        data[node2] = node1;
    }
    //cout << "Finish!" << endl;
    //cout << "num(2N):" << num << endl;
    
    int chord_num;
    
    int **M = new int*[num];
    for (int i=0; i<num; i++){
        M[i] = new int[num];
    }
    
    int **C = new int*[num];
    for (int i=0; i<num; i++){
        C[i] = new int[num];
    }
    //cout << "Counting chord_num..." << endl;
    chord_num = MPS(data, 0, num-1, M, C);
    
    //cout << "Finish!" << endl;
    //cout << "chord_num: " << chord_num << endl;
    
    for (int i = 0; i < num; ++i)
        delete [] M[i];
    delete [] M;

    int **chord = new int*[chord_num];
    for (int i=0; i<chord_num; i++){
        chord[i] = new int[2];
    }
    
    findchord(data, 0, num-1, M, C, chord);
   
    for (int i = 0; i < num; ++i)
        delete [] C[i];
    delete [] C;
    
    //write output file//
    fout << chord_num <<endl;
    for (int i = chord_num-1; i >= 0; i--)
        fout << chord[i][0] << " " << chord[i][1] << endl;
    fin.close();
    fout.close();
    return 0;
}
