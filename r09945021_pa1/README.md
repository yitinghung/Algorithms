# Algorithms Programming Assignment 1
# Problem: Sorting

## Introduction
This program supports four different sorting methods:    
**`insertion sort`**, **`merge sort`**, **`quick sort`** and **`heap sort`**.
### Directories
| Name | Description |
|------|-------------|
|/bin  |Directory of binary file|
|/doc  |Directory of document|
|/inputs|Directory of unsorted data|
|/lib|Directory of library source code|
|/outputs|Directory of sorted data|
|/src|Directory of source code|
|/utility|Directory of checker|

## Input/output Files
In the input file (*.in), the first two lines starting with ‘#’ are just comments. Except comments, each line contains two numbers: index followed by the unsorted number. The range of unsorted number is between 0 and 1,000,000. Two numbers are separated by a space. For example, the file 5.case1.in contains five numbers      
```
# 5 data points
# index number
0 16
1 13
2 0   
3 6   
4 7
```
The output file (*.out) is actually the same as the input file except that the numbers are sorted in `**increasing order**`. For example, 5.case1.out is like:       
```
# 5 data points 
# index number 
0 0 
1 6
2 7 
3 13 
4 16
```

## PLOT
You can visualize your unsorted/sorted numbers by using the gnuplot tool by the command gnuplot. After that, please key in the following
```
set xrange [0:5]
set yrange [0:20]

plot "5.case1.in" usi 1:2
plot "5.case1.out" usi 1:2

# if you want to save to png files
set terminal png
set output "5.case1.out.png"
replot
```
![image](https://github.com/yitinghung/Algorithms/blob/main/r09945021_pa1/plot_example.png)


## How to Compile
```
make
```

## How to Run
```
cd bin
./NTU_sort -[IS|MS|QS|HS] <input_file_name> <output_file_name>
```

For example,
```
under r09945021_pa1/
./bin/NTU_sort -MS inputs/1000.case1.in outputs/1000.case1.out
```

## How to Varify Result
```
cd utility/
./PA1_result_checker <input_file> <your_output_file>
```

For example,
```
under r09945021_pa1/
./utility/PA1_result_checker ./inputs/5.case1.in ./outputs/5.case1.out
```
