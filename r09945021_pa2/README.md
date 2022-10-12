# Algorithms Programming Assignment 2
# Problem: Maximum Planar Subset

## Introduction
Given is a set $C$ of n chords of a circle (see Figure 1 (a)). We assume that no two chords of $C$ share an endpoint. Number the endpoints of these chords from $0$ to $2n-1$, clockwise around the circle (see Figure 1 (c)). Let $M(i,j)$, $i ≤ j$, denote the number of chords in the maximum planar subset (i.e., no two chords overlap each other in the subset) in the region formed by the chord $\bar{ij}$ and the arc between the endpoints $i$ and $j$ (see Figure 1 (d)).     
As the example shown in Figure 1 (a), $M(2,7)$ = 1, $M(3, 3)$ = 0, and $M(0,11)$ = 3. You are asked to write a program that computes the number of chords in the maximum planar subset in a circle of $n$ chords, i.e., compute $M(0, 2n−1)$, and reports the details of each chords, as shown in Figure 1 (b).
![image](https://github.com/yitinghung/Algorithms/blob/main/r09945021_pa2/figure%201.png)

## Input 
The input consists of an integer 2n, 1 ≤ n ≤ 90,000, denoting the number of vertices on a circle, followed by n lines, each containing two integers a and b (0 ≤ a, b ≤ 2n − 1), denoting two endpoints of a chord. A single “0” (zero) in the input line signifies the end of inputi.     
Sample Input:
```
12 
0 4 
1 9 
2 6 
3 10 
5 7 
8 11 
0
```

## Output
The output file reports the number of chords in the maximum planar subset in the input circle of n chords, followed by a list of the two endpoints for each resulting chord in the maximum planar subset (sorted by the first endpoint in the increasing order).    
Sample Output:
```
3 
0 4 
5 7  
8 11
```

## How to Compile
```
make
```

##How to Run
```
cd bin/
./mps <input_file_name> <output_file_name>
```
For example,
under r09945021_pa2/
```
./bin/mps inputs/12.in outputs/12.out
```

