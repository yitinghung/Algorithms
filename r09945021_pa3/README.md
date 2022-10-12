# Algorithms Programming Assignment 3
# Problem: Cycle Breaking

## Introduction
Cycle breaking serves as a fundamental technique for many applications, e.g., resolving resource deadlock or simplifying a problem instance. In graph theory, a cycle is a path where the first and the last vertices are the same. A graph without cycles is called an acyclic graph. Given a simple graph $G = (V, E)$ which may contain cycles, we want to remove some edges to make the graph acyclic with minimum total cost (weight). Such a problem is so-called the *cycle breaking* or *cycle removal* problem. For example, Figure 1 (a) is a weighted undirected graph $G_u$ with cycles. We can remove $e_{01}$ and $e_{34}$ to make it acyclic with total cost = 3 + 5 = 8. For the weighted directed graph $G_d$ in Figure 1 (b), there is only one cycle $C_{143}$. So we only need to remove $e_{43}$ with total cost = 5. Cycle breaking for an (unweighted or weighted) undirected graph can optimally be solved in polynomial time. The problem for a weighted directed graph, also known as a *minimum feedback arc set* problem, however, is a NP-hard problem. In this assignment, test cases contain three types of graph instances: 1) unweighted undirected graph, 2) weighted undirected graph, and 3) weighted directed graph.
![image]()

## Input
The input will be a simple graph with only one connected component which may contain cycles or not. The first line of the input is a character “u” or a character “d”, which indicates the input graph is an undirected graph or a directed graph, respectively. The second line is an integer n, denoting the total number of vertices. The indices of these nodes will be continuous from 0 to n − 1. The third line is an integer m, denoting the total number of edges. In the following m lines, each contains three integers i, j and w, denoting an edge from vertex i to vertex j with weight w, −100 ≤ w ≤ 100. For test cases of unweighted undirected graph, the weight of each edge will be equal to 1. Please note that the order of vertex i and j implies the direction of the edge in a directed graph, while it does not matter in an undirected graph. A single “0” (zero) in the input line signifies the end of input. For undirected graph instances, 1 ≤ n ≤ 10000 and 1 ≤ m ≤ 50000000. For directed graph instances, 1 ≤ n ≤ 5000 and 1 ≤ m ≤ 10000.

## Output
The output file should report the total weight of removed edges to make the input graph acyclic, followed by a list of these removed edges and their weights. The graph must remain connected (weakly-connected component for directed graph instances) after the edges are removed. The output edges can be in arbitrary order. If the input graph has no cycles, you should output a line with single “0” (zero) in your output file.     
Here are some input/output examples:
Sample Input 1
```
u
8 
9
0 1 3
0 2 5
1 3 10
1 4 8
2 5 9
3 4 5 
3 5 11
3 6 12
4 7 6
0
```
Sample Output 1
```
8
0 1 3 
3 4 5
```
Sample Input 2
```
d
8
9
0 1 3
0 2 5
1 4 8
2 5 9
3 1 10
3 5 11
4 3 5
4 7 6
6 3 12
0
```
Sample Output 2
```
5
4 3 5
```

## How to Compile
```
make
```

## How to Run
```
cd bin/
./cb <input_file_name> <output_file_name>
```	
For example,     
under r09945021_pa3/
```
./bin/cb inputs/public_case_1.in outputs/public_case_1.out
```

